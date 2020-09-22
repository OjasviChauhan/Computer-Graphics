#include <stdio.h>
#include<GL/glut.h>
#include <math.h>

int rx,ry,xc,yc;

void midptellipse(void) 
{ 
  
    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
  
    // Initial decision parameter of region 1 
    d1 = (ry * ry) 
         - (rx * rx * ry) 
         + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
    

    glBegin(GL_POINTS);
        // For region 1 
        while (dx < dy) {       
            // Print points based on 4-way symmetry             
            glVertex2f(x+xc, y+yc);
            glVertex2f(-x+xc, y+yc);
            glVertex2f(x+xc, -y+yc);
            glVertex2f(-x+xc, -y+yc);

            // Checking and updating value of 
            // decision parameter based on algorithm 
            if (d1 < 0) { 
                x++; 
                dx = dx + (2 * ry * ry); 
                d1 = d1 + dx + (ry * ry); 
            } 
            else { 
                x++; 
                y--; 
                dx = dx + (2 * ry * ry); 
                dy = dy - (2 * rx * rx); 
                d1 = d1 + dx - dy + (ry * ry); 
            } 
        }
    glEnd(); 
  
    // Decision parameter of region 2 
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
         + ((rx * rx) * ((y - 1) * (y - 1))) 
         - (rx * rx * ry * ry); 
    
    glBegin(GL_POINTS);
    // Plotting points of region 2 
        while (y >= 0) { 
            // printing points based on 4-way symmetry 
            glVertex2f(x+xc, y+yc);
            glVertex2f(-x+xc, y+yc);
            glVertex2f(x+xc, -y+yc);
            glVertex2f(-x+xc, -y+yc);
      
            // Checking and updating parameter 
            // value based on algorithm 
            if (d2 > 0) { 
                y--; 
                dy = dy - (2 * rx * rx); 
                d2 = d2 + (rx * rx) - dy; 
            } 
            else { 
                y--; 
                x++; 
                dx = dx + (2 * ry * ry); 
                dy = dy - (2 * rx * rx); 
                d2 = d2 + dx - dy + (rx * rx); 
            } 
        }
    glEnd(); 
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
    printf("rx : ");
    scanf("%d",&rx);
    printf("ry : ");
    scanf("%d",&ry);
    printf("xc : ");
    scanf("%d",&xc);
    printf("yc : ");
    scanf("%d",&yc);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("Ellipse Bresenham");
init();
glutDisplayFunc(midptellipse);
glutMainLoop();

return 0;
}
