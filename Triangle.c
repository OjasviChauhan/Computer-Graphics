#include<GL/glut.h>
#include<GL/gl.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0,1,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0,0.5);
	glEnd();

	glColor3f(0,0,0);
	glRasterPos2f(-0.1,-0.70);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Ojasvi Chauhan");
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Ojasvi");
	glClearColor(1,1,0,1);
	//gluOrtho2D(0,100,0,200);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
