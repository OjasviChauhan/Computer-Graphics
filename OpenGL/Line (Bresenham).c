#include <stdio.h>
#include<GL/glut.h>
#include <math.h>

float X1,X2,Y1,Y2;

void Draw(void)
{
	float M,p,dx,dy,x,y,t;
	glClear(GL_COLOR_BUFFER_BIT);

	if(X2-X1==0)
		M = Y2-Y1;
	else
		M = (Y2-Y1)/(X2-X1);

	if(fabs(M)<1)				// for values btw -1.0 to 1.0
	{
		if(X1>X2){				// if values are interchanged
			t = X1;
			X1 = X2;
			X2 = t;

			t = Y1;
			Y1 = Y2;
			Y2 = t;
		}

		dx = fabs(X2-X1);
		dy = fabs(Y2-Y1);

		p = 2*dy - dx;

		x=X1;
		y=Y1;

		glBegin(GL_POINTS);
			while(x<=X2){
				glVertex2f(x,y);
				x=x+1;

				if(p>=0)
				{
					if(M>0)				// handling the case where slope will be +ve and btw 0.0 to 1.0
						y=y+1;
					else				// handling the case where slope will be -ve and btw -1.0 to 0.0
						y=y-1;

					p = p+2*dy-2*dx;
				}
				else
				{
					y=y;
					p = p+2*dy;
				}
			}
		glEnd();
	}
	
	if(fabs(M)>=1)				// for values less than -1.0 and greater than 1.0
	{
		if(Y1>Y2){
			t = X1;
			X1 = X2;
			X2 = t;

			t = Y1;
			Y1 = Y2;
			Y2 = t;
		}

		dx = fabs(X2-X1);
		dy = fabs(Y2-Y1);

		p = 2*dx - dy;

		x=X1;
		y=Y1;

		glBegin(GL_POINTS);
			while(y<=Y2){
				glVertex2f(x,y);
				y=y+1;

				if(p>=0)
				{
					if(M>=0)
						x=x+1;
					else
						x=x-1;
					
					p = p+2*dx-2*dy;
				}
				else
				{
					x=x;
					p = p+2*dx;
				}
			}
		glEnd();
	}

	glFlush();
}

void init(void)
{
	//glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
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
glutCreateWindow ("Bresenham");
init();
glutDisplayFunc(Draw);
glutMainLoop();

return 0;
}
