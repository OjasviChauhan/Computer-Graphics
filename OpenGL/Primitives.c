#include <GL/glut.h>
#include<GL/gl.h>
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);


   	glBegin(GL_QUADS);                 
      glVertex2f(-0.8f, 0.1f);     
      glVertex2f(-0.2f, 0.1f);     
      glVertex2f(-0.2f, 0.7f);
      glVertex2f(-0.8f, 0.7f);
   	glEnd();


   	glColor3f(0,0,1);
   	glBegin(GL_TRIANGLES);             
      glVertex2f(0.1f, -0.6f);
      glVertex2f(0.7f, -0.6f);
      glVertex2f(0.4f, -0.1f);
   	glEnd();


 	glColor3f(0,1,1);
   	glBegin(GL_POLYGON);                
      glVertex2f(0.4f, 0.2f);
      glVertex2f(0.6f, 0.2f);
      glVertex2f(0.7f, 0.4f);
      glVertex2f(0.6f, 0.6f);
      glVertex2f(0.4f, 0.6f);
      glVertex2f(0.3f, 0.4f);
   	glEnd();


	glColor3f(1,0,1);
  	glBegin(GL_LINE_LOOP);
      glVertex2f(-0.9f,-0.9f);
      glVertex2f(-0.5f,-0.5f);
      glVertex2f(-0.5f,0.0f);
      glVertex2f(0.0f,-0.5f);
    glEnd();


    glColor3f(1,1,1);
	glBegin(GL_POINTS);
		glVertex2f(-0.5f,-0.9f);
		glVertex2f(-0.51f,-0.9f);
		glVertex2f(-0.52f,-0.89f);
		glVertex2f(-0.53f,-0.88f);
		glVertex2f(-0.54f,-0.87f);
		glVertex2f(-0.55f,-0.86f);
	glEnd();


	glColor3f(1,1,0);
	glBegin(GL_LINES);
	   	glVertex2f(0.75f,0.0f);
	   	glVertex2f(-0.75f,0.0f);
		glVertex2f(0.0f,0.75f);
		glVertex2f(0.0f,-0.75f);
	glEnd();
 glFlush();
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(800,800);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Ojasvi");
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
