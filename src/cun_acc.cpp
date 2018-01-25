#include "../include/cun_acc.hpp"

float RADIUS = AU*120;
float v[N][3], d[N][3], m[N];

void update()
{
	float t_d[N][3];
	#pragma acc kernels copyin(m[0:N]) copy(d[0:N][0:3], v[0:N][0:3]) create(t_d[0:N][0:3])
	{
		for(int i = 0; i < N; i++)		//part 1
		{
			float nf_i = 0, nf_j = 0, nf_k = 0; 
			for(int j = 0; j < N; j++)	//part 2
			{
				if(i != j)
				{
					float g[3] = {0,0,0};
					g[0] = d[j][0] - d[i][0];
					g[1] = d[j][1] - d[i][1];
					g[2] = d[j][2] - d[i][2];

					float g_m = (GC * m[i] * m[j]) /
								(pow(g[0],2) + 
								 pow(g[1],2) +
								 pow(g[2],2));

					g_m /= sqrt(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);

					nf_i += g[0] * g_m;
					nf_j += g[1] * g_m;
					nf_k += g[2] * g_m;
				}
			}

			v[i][0] += (nf_i * TS) / m[i];
			v[i][1] += (nf_j * TS) / m[i];
			v[i][2] += (nf_k * TS) / m[i];

			t_d[i][0] = d[i][0] + v[i][0] * TS;
			t_d[i][1] = d[i][1] + v[i][1] * TS;
			t_d[i][2] = d[i][2] + v[i][2] * TS;
		}

		for(int i = 0; i < N; i++)
		{
			d[i][0] = t_d[i][0];
			d[i][1] = t_d[i][1];
			d[i][2] = t_d[i][2];
		}
	}
}

void set_ptcl(int idx, float mass, float x, float y, float z, float i, float j, float k)
{
	d[idx][0] = x;
	d[idx][1] = y;
	d[idx][2] = z;
	
	v[idx][0] = i;
	v[idx][1] = j;
	v[idx][2] = k;

	m[idx] = mass;
}

void init()
{
	float mass = 1e28;
	float c    = 0.01;			//flatness
	set_ptcl(0, 1e33, 0,0,0, 0,0,0);
	for(int i = 1; i < N; i++)
	{
		if(i == 5000)
		{
			c = 1.0;
			mass = 1e30;
			RADIUS = 500*AU;
		}

		float x_pos, y_pos;
		while(true)
		{
			x_pos = 2 * ((float)rand()/(float)RAND_MAX) - 1;
			y_pos = 2 * ((float)rand()/(float)RAND_MAX) - 1;
			if(y_pos >= -sqrt( 1 - pow( x_pos, 2)) && y_pos <= sqrt( 1 - pow( x_pos, 2)))
			{
				break;
			}
		}
		float z_max = sqrt(c * (1 - pow( x_pos, 2)-pow( y_pos, 2)));
		float z_min = -z_max;
		float z_pos = (z_max - z_min) * ((float)rand()/(float)RAND_MAX) + z_min;
		x_pos *= RADIUS;
		y_pos *= RADIUS;
		z_pos *= RADIUS;
		float m = y_pos / x_pos;
		m = -1/m;
		float b = y_pos - x_pos*m;
		if(y_pos > 0)
		{
			float vel[3] = {-(RADIUS/2), (x_pos - RADIUS/2)*m + b - y_pos, 0};
			float vel_m = sqrt((float)(GC * (1e33 + mass*1.2e3)) / (float)sqrt(x_pos*x_pos + y_pos*y_pos + z_pos*z_pos));
			vel_m /= sqrt(vel[0]*vel[0] + vel[1]*vel[1] + vel[2]*vel[2]);
			vel[0] *= vel_m;
			vel[1] *= vel_m;
			vel[2] *= vel_m;
			set_ptcl(i, mass, x_pos, y_pos, z_pos, vel[0], vel[1], vel[2]);
		}
		else
		{
			float vel[3] = {(RADIUS/2), (x_pos + RADIUS/2)*m + b - y_pos, 0};
			float vel_m = sqrt((float)(GC * (1e33 + mass*1.2e3)) / (float)sqrt(x_pos*x_pos + y_pos*y_pos + z_pos*z_pos));
			vel_m /= sqrt(vel[0]*vel[0] + vel[1]*vel[1] + vel[2]*vel[2]);
			vel[0] *= vel_m;
			vel[1] *= vel_m;
			vel[2] *= vel_m;
			set_ptcl(i, mass, x_pos, y_pos, z_pos, vel[0], vel[1], vel[2]);
		}
	}
	RADIUS = 140*AU;
}
