#include <GL/glut.h>
 void init(void)
 {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(0.0, 700, 0.0, 700);
 }

void display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    //mountains
    glColor3f(0.36,0.25,0.22);
    glBegin(GL_TRIANGLES);   
        glVertex2f(-1.0f, 0.2f); 
        glVertex2f(-0.5f, 0.2f); 
        glVertex2f(-0.75f, 0.7f);
    glEnd( );
    
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, 0.2f); 
        glVertex2f(0.0f, 0.2f); 
        glVertex2f(-0.25f, 0.7f);
    glEnd( );

    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.2f); 
        glVertex2f(0.5f, 0.2f); 
        glVertex2f(0.25f, 0.7f);
    glEnd( );

    glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, 0.2f); 
        glVertex2f(1.0f, 0.2f); 
        glVertex2f(0.75f, 0.7f);
    glEnd( );


    //sun
    glBegin(GL_TRIANGLES);
        glColor3f(1,0.87,0.01); 
        glVertex2f(0.0f, 0.2f); 
        glVertex2f(-0.097f, 0.4f); 
        glVertex2f(0.097f, 0.4f);
    glEnd( );


    //sky LEFT
    glColor3f(0.505,0.823,0.96);
     glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f, 0.2f); 
        glVertex2f(-1.0f, 1.0f); 
        glVertex2f(-0.75f, 0.7f);
    glEnd( );

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.75f, 0.7f); 
        glVertex2f(-0.5f, 0.2f); 
        glVertex2f(-0.25f, 0.7f);
    glEnd( );
    
    glBegin(GL_QUADS);       
        glVertex2f(-0.097f, 0.4f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.0f, 1.0f); 
        glVertex2f(-0.25f, 0.7f);    
    glEnd( );

    glBegin(GL_QUADS);       
        glVertex2f(-0.25f, 0.7f);
        glVertex2f(-0.75f, 0.7f);
        glVertex2f(-1.0f, 1.0f); 
        glVertex2f(0.0f, 1.0f);    
    glEnd( );


    //sky RIGHT
    glColor3f(0.505,0.823,0.96);
    glBegin(GL_TRIANGLES);
        glVertex2f(1.0f, 0.2f); 
        glVertex2f(1.0f, 1.0f); 
        glVertex2f(0.75f, 0.7f);
    glEnd( );

    glBegin(GL_TRIANGLES);
        glVertex2f(0.75f, 0.7f); 
        glVertex2f(0.5f, 0.2f); 
        glVertex2f(0.25f, 0.7f);
    glEnd( );

    glBegin(GL_QUADS);       
        glVertex2f(0.097f, 0.4f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.0f, 1.0f); 
        glVertex2f(0.25f, 0.7f);    
    glEnd( );

    glBegin(GL_QUADS);       
        glVertex2f(0.25f, 0.7f);
        glVertex2f(0.75f, 0.7f);
        glVertex2f(1.0f, 1.0f); 
        glVertex2f(0.0f, 1.0f);    
    glEnd( );


    //River
    glColor3f(0.09,0.278,0.796);
    glBegin(GL_QUADS);       
        glVertex2f(-0.097f, 0.2f);
        glVertex2f(-0.097f, -1.0f); 
        glVertex2f(0.097f, -1.0f);
        glVertex2f(0.097f, 0.2f);    
    glEnd( );


    //green land
    glColor3f(0.133,0.752,0.258);
    glBegin(GL_QUADS);       
        glVertex2f(-1.0f, 0.2f);
        glVertex2f(-1.0f, -1.0f); 
        glVertex2f(-0.097f, -1.0f);
        glVertex2f(-0.097f, 0.2f);    
    glEnd( );

    glBegin(GL_QUADS);       
        glVertex2f(1.0f, 0.2f);
        glVertex2f(1.0f, -1.0f); 
        glVertex2f(0.097f, -1.0f);
        glVertex2f(0.097f, 0.2f);    
    glEnd( );



    glFlush();
}

void myMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	   	glColor3f(0.5,0.5,0.5);
	    glBegin(GL_QUADS);       
	        glVertex2f(-1.0f, 0.2f);
	        glVertex2f(-1.0f, -1.0f); 
	        glVertex2f(-0.097f, -1.0f);
	        glVertex2f(-0.097f, 0.2f);    
	    glEnd( );
	    glBegin(GL_QUADS);       
	        glVertex2f(1.0f, 0.2f);
	        glVertex2f(1.0f, -1.0f); 
	        glVertex2f(0.097f, -1.0f);
	        glVertex2f(0.097f, 0.2f);    
	    glEnd( );
		glFlush();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
	   	glColor3f(0.133,0.752,0.258);
	    glBegin(GL_QUADS);       
	        glVertex2f(-1.0f, 0.2f);
	        glVertex2f(-1.0f, -1.0f); 
	        glVertex2f(-0.097f, -1.0f);
	        glVertex2f(-0.097f, 0.2f);    
	    glEnd( );
	    glBegin(GL_QUADS);       
	        glVertex2f(1.0f, 0.2f);
	        glVertex2f(1.0f, -1.0f); 
	        glVertex2f(0.097f, -1.0f);
	        glVertex2f(0.097f, 0.2f);    
	    glEnd( );
		glFlush();
	}
}


void myKeyboard(unsigned char key, int x, int y )
{
	if(key=='z'||key=='Z')
	{
		glColor3f(0.133,0.752,0.258);
		glBegin(GL_QUADS);       
	        glVertex2f(1.0f, 0.2f);
	        glVertex2f(1.0f, -1.0f); 
	        glVertex2f(0.097f, -1.0f);
	        glVertex2f(0.097f, 0.2f);    
    	glEnd( );
    	glBegin(GL_QUADS);       
	        glVertex2f(-1.0f, 0.2f);
	        glVertex2f(-1.0f, -1.0f); 
	        glVertex2f(-0.097f, -1.0f);
	        glVertex2f(-0.097f, 0.2f);    
    	glEnd( );
		glFlush();
	}
	else if(key=='g'||key=='G')
	{
		glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUADS);       
	        glVertex2f(1.0f, 0.2f);
	        glVertex2f(1.0f, -1.0f); 
	        glVertex2f(0.097f, -1.0f);
	        glVertex2f(0.097f, 0.2f);    
    	glEnd( );
    	glBegin(GL_QUADS);       
	        glVertex2f(-1.0f, 0.2f);
	        glVertex2f(-1.0f, -1.0f); 
	        glVertex2f(-0.097f, -1.0f);
	        glVertex2f(-0.097f, 0.2f);    
    	glEnd( );
		glFlush();
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); 
    glutInitWindowSize( 800,800 ); 
    glutCreateWindow("Ojasvi"); 
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
    return 0;
}
