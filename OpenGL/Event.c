#include<GL/glut.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 700, 0.0, 700);
}
void display()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glColor3f(0.0, 0.0, 0.0);
	glBegin( GL_TRIANGLES );
		glVertex2i( 200,400 );
		glVertex2i( 400,400 );
		glVertex2i( 300,600 );
	glEnd();
	glFlush();
}

void myKeyboard(unsigned char key, int x, int y )
{
if(key)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin( GL_TRIANGLES );
		glVertex2i( 200,400 );
		glVertex2i( 400,400 );
		glVertex2i( 300,600 );
	glEnd();
	glFlush();
}
}

void myMouse(int button, int state, int x, int y) 
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin( GL_TRIANGLES );
		glVertex2i( 200,400 );
		glVertex2i( 400,400 );
		glVertex2i( 300,600 );
	glEnd();
	glFlush();
}
}

int main(int argc, char**argv) 
{
    glutInit(&argc, argv); 
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); 
    glutInitWindowSize( 700,700 ); 
    glutCreateWindow("Ojasvi"); 
    init();  
    glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard); 
    glutMainLoop();  
}
