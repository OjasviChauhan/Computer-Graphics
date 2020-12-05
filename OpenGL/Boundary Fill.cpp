#include <iostream>
#include <GL/glut.h>
void init(){
    gluOrtho2D(0,500,0,500);
}
void boundaryFill(int x,int y,float fill[3],float boundary[3]){
    //-------------- Boundary Fill Algorithm ---------------------------------
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=boundary[0] || color[1]!=boundary[1] || color[2]!=boundary[2]) && (color[0]!=fill[0] || color[1]!=fill[1] || color[2]!=fill[2])){
        glColor3f(fill[0],fill[1],fill[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        boundaryFill(x+1,y,fill,boundary);
        boundaryFill(x-1,y,fill,boundary);
        boundaryFill(x,y+1,fill,boundary);
        boundaryFill(x,y-1,fill,boundary);
        boundaryFill(x-1,y-1,fill,boundary);
        boundaryFill(x+1,y-1,fill,boundary);
        boundaryFill(x+1,y+1,fill,boundary);
        boundaryFill(x-1,y+1,fill,boundary);
    }
}
void mouse(int btn, int state, int x, int y){
    y=500-y;
    if(btn==GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            float boundary[3] = {1.0f,1.0f,1.0f};
            float color[3] = {0.0f,1.0f,0.0f};
            boundaryFill(x,y,color,boundary);
        }
    }
}
void display(){
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(290,290);
        glVertex2f(320,335);
        glVertex2f(290,380);
        glVertex2f(350,380);
        glVertex2f(380,446);
        glVertex2f(410,380);
        glVertex2f(470,380);
        glVertex2f(440,335);
        glVertex2f(470,290);
        glVertex2f(410,290);
        glVertex2f(380,224);
        glVertex2f(350,290);
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Boundary Fill Algorithm");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
