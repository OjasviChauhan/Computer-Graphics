#include<GL/glut.h>
#include<stdio.h>

float X1,X2,Y1,Y2;

void Line(void)
{
	float dy,dx,steps,x,y,k,Xin,Yin;
	dx=X2-X1;
	dy=Y2-Y1;

	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}
	else
		steps = abs(dy);

	Xin = dx/steps;
	Yin = dy/steps;

	x= X1;
	y=Y1;

	glBegin(GL_LINES);
		glVertex2i(x,y);
	glEnd();

	for (k=0 ; k<=steps; k++){
		x= x + Xin;
		y= y + Yin;
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
	}

	glFlush();
}

void init(void)
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
	printf("X1 : ");
	scanf("%f",&X1);
	printf("Y1 : ");
	scanf("%f",&Y1);
	printf("X2 : ");
	scanf("%f",&X2);
	printf("Y2 : ");
	scanf("%f",&Y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA");
init();
glutDisplayFunc(Line);
glutMainLoop();

return 0;
}
