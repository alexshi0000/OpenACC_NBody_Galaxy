#include "../include/graphics.hpp"
#include "../include/cun_acc.hpp"

bool begin_r = 1;

void display_func()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	for(int i = 0; i < N; i++)
	{
    	float x1,y1,z1;
		x1 = d[i][0] / (RADIUS*1.5);	
		y1 = d[i][1] / (RADIUS*1.5);
		z1 = d[i][2] / (RADIUS*1.5);
			//divided by camera dimensions
		glColor4f(0.8f, 0.8f, 1.0f, 0.11f);
		if(m[i] > 1e28)
			glColor4f(0.4f, 0.4f, 1.0f, 0.0f);

		glPushMatrix ();
	        glTranslatef    (x1, y1, z1);
	        glutSolidSphere (0.002, 5, 5);
	        glutSolidSphere (0.005, 5, 5);
   		glPopMatrix ();
    }
    update();
	glutSwapBuffers();
    glutPostRedisplay();
}

void reshape_func(GLint w, GLint h){
	if(begin_r)
	{
		GLfloat width = GLfloat(w);
		GLfloat height = GLfloat(h);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		float aspect = (float)width / (float)height;
		glOrtho(-aspect, aspect, -1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glutFullScreen();
		begin_r = 0;
	}
	else
	{
		glViewport(0, 0, w, h);
	}
}
