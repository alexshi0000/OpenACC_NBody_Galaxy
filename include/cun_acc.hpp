#ifndef cun_acc
#define cun_acc

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define GC (6.673e-11)
#define AU (1.496e+11)
#define PI (3.14159265359)
#define LY (9.461e+15)

#define TS (0.8e6)
#define N  (36500)

extern float RADIUS;
extern float v[N][3], d[N][3], m[N];
/*	
	0 - i
	1 - j
	2 - k
*/
extern void update();
extern void set_ptcl(int idx, float mass, float x, float y, float z, float i, float j, float k);
extern void init();
#endif
