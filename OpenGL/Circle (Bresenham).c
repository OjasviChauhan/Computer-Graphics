#include <stdio.h>
#include<GL/glut.h>
#include <math.h>

int xc,yc,r;

void drawCircle(int xc, int yc, int x, int y) 
{ 
    glBegin(GL_POINTS);
	    glVertex2f(xc+x, yc+y); 
	    glVertex2f(xc-x, yc+y); 
	    glVertex2f(xc+x, yc-y); 
	    glVertex2f(xc-x, yc-y); 
	    glVertex2f(xc+y, yc+x); 
	    glVertex2f(xc-y, yc+x); 
	    glVertex2f(xc+y, yc-x); 
	    glVertex2f(xc-y, yc-x);
    glEnd(); 
    glFlush(); 
} 
  
// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(void) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
    } 
} 

void init(void)
{
    //glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}  
  
// Driver code 
int main(int argc, char** argv) {
    printf("xc : ");
    scanf("%d",&xc);
    printf("yc : ");
    scanf("%d",&yc);
    printf("Radius : ");
    scanf("%d",&r);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Circle Bresenham");
    init();
    glutDisplayFunc(circleBres);
    glutMainLoop();

return 0;
}
