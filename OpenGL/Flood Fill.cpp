#include <iostream>
#include <GL/glut.h>
void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0,500,0,500);
}
void floodFill(int x,int y,float fillColor[3],float oldColor[3]){
    //-------------- Flood Fill Algorithm ---------------------------------
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((oldColor[0]==color[0] && oldColor[1]==color[1] && oldColor[2]==color[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        floodFill(x+1,y,fillColor,oldColor);
        floodFill(x-1,y,fillColor,oldColor);
        floodFill(x,y+1,fillColor,oldColor);
        floodFill(x,y-1,fillColor,oldColor);
        floodFill(x-1,y-1,fillColor,oldColor);
        floodFill(x+1,y-1,fillColor,oldColor);
        floodFill(x+1,y+1,fillColor,oldColor);
        floodFill(x-1,y+1,fillColor,oldColor);
    }
}
void mouse(int btn, int state, int x, int y){
    y=500-y;
    if(btn==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            float oldColor[3] = {0.0f,0.0f,0.0f};
            float fillColor[3] = {1.0f,0.568f,0.141f};
            floodFill(x,y,fillColor,oldColor);
        }
    }
}
void display(){
    glLineWidth(2);
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(200,200);
        glVertex2f(200,400);
        glVertex2f(250,400);
        glVertex2f(250,320);
        glVertex2f(350,320);
        glVertex2f(350,400);
        glVertex2f(400,400);
        glVertex2f(400,200);
        glVertex2f(350,200);
        glVertex2f(350,280);
        glVertex2f(250,280);
        glVertex2f(250,200);
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
