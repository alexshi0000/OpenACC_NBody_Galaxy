#include "../include/cun_acc.h"
#include "../include/graphics.h"
using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));
	init();
	glutInit(&argc,argv);			
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("n-body galaxy realization using openacc gpu acceleration");
	glutDisplayFunc(display_func);
	glutReshapeFunc(reshape_func);
	glutMainLoop();
	return 0;
}
