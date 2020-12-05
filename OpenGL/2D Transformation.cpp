#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846
float x[100],y[100];
float p[100],m[100];
int n,k,c;
double angle;
float a,b;
void init(){
    gluOrtho2D(-10,10,-10,10);
}
void display(void){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);
            glVertex2f(0,100);
            glVertex2f(0,-100);
            glVertex2f(100,0);
            glVertex2f(-100,0);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f,1.0f,0.0f);
            for(int i=0;i<n;i++){
                glVertex2f(x[i],y[i]);
            }
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.070f,0.349f,0.070f);
        for(int i=0;i<n;i++){
            glVertex2f(p[i],m[i]);
        }
        glEnd();
        glFlush();
}
//-------------- Translation ------------------------------
void translation(){
    printf("\nEnter X and Y Translation Co-ordinates :");
    scanf("%f%f",&a,&b);
    for(int i=0;i<n;i++){
        p[i]+=a;
        m[i]+=b;
    }
}
//-------------- Rotation ------------------------------
void rotation(){
    printf("\nEnter The Angle Of Rotation :");
    scanf("%lf",&angle);
    printf("\nEnter 1 For AntiClockwise");
    printf("\nEnter 2 For Clockwise");
    printf("\nEnter Your Choice :");
    scanf("%d",&c);
    printf("\nEnter X and Y Co-ordinates For Rotation :");
    scanf("%f%f",&a,&b);
    if(c==1){
        angle=(angle*pi)/180;
    }
    if(c==2){
        angle=(-angle*pi)/180;
    }
    for(int i=0;i<n;i++){             //Translation
        p[i]-=a;
        m[i]-=b;
    }
    for(int i=0;i<n;i++){             //Rotation
        p[i]=(p[i]*cos(angle))-(m[i]*sin(angle));
        m[i]=(p[i]*sin(angle))+(m[i]*cos(angle));
    }
    for(int i=0;i<n;i++){             //Translate Back
        p[i]+=a;
        m[i]+=b;
    }
}
//-------------- Scaling ------------------------------
void scaling(){
    printf("\nEnter X and Y Scaling Factor :");
    scanf("%f%f",&a,&b);
    for(int i=0;i<n;i++){
        p[i]*=a;
        m[i]*=b;
    }
}
//-------------- Reflection ------------------------------
void reflection(){
    printf("\nEnter 1 To Reflect Through X-axis");
    printf("\nEnter 2 To Reflect Through Y-axis");
    printf("\nEnter 3 To Reflect Through X=Y");
    printf("\nEnter 4 To Reflect Through X=-Y");
    printf("\nEnter 5 To Reflect Through Origin");
    printf("\nEnter 6 To Reflect Through Arbitrary Line");
    printf("\nEnter Your Choice :");
    scanf("%d",&c);
    if(c==1){
        for(int i=0;i<n;i++){             //X-axis
        m[i]=-m[i];
        }
    }
    else if(c==2){
        for(int i=0;i<n;i++){             //Y-axis
            p[i]=-p[i];
        }
    }
    else if(c==3){
        for(int i=0;i<n;i++){             //X=Y
            float t;
            t=p[i];
            p[i]=m[i];
            m[i]=t;
        }
    }
    else if(c==4){
        for(int i=0;i<n;i++){             //X=-Y
            float t;
            t=-p[i];
            p[i]=-m[i];
            m[i]=t;
            }
    }
    else if(c==5){
        for(int i=0;i<n;i++){             //Origin
            p[i]=-p[i];
            m[i]=-m[i];
        }
    }
    else if(c==6){                        //Arbitrary Line
        float m1;
        printf("\nEnter Slope And Intercept Of The Line : ");
        scanf("%f%d",&m1,&c);
        a=-c/m1;
        for(int i=0;i<n;i++){             //Translation
            p[i]-=a;
            m[i]-=c;
        }
        angle=-atan(m1);
        for(int i=0;i<n;i++){             //Rotation
            p[i]=(p[i]*cos(angle))-(m[i]*sin(angle));
            m[i]=(p[i]*sin(angle))+(m[i]*cos(angle));
        }
        for(int i=0;i<n;i++){             //Reflection
            m[i]=-m[i];
        }
        angle=-angle;
        for(int i=0;i<n;i++){             //Rotate Back
            p[i]=(p[i]*cos(angle))-(m[i]*sin(angle));
            m[i]=(p[i]*sin(angle))+(m[i]*cos(angle));
        }
        for(int i=0;i<n;i++){             //Translate Back
            p[i]+=a;
            m[i]+=c;
        }
    }
}
//-------------- Shearing ------------------------------
void shearing(){
    printf("\nEnter X and Y Shearing Factor :");
    scanf("%f%f",&a,&b);
    for(int i=0;i<n;i++){
        p[i]+=a*m[i];
        m[i]+=b*p[i];
    }
}
//-------------- 2D Transformations ------------------------------
void transform2d(){
    while(1){
        printf("\n1. Translate");
        printf("\n2. Rotate");
        printf("\n3. Scale");
        printf("\n4. Reflect");
        printf("\n5. Shear");
        printf("\n0. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&k);
        if(k==1){
            translation();
        }
        else if(k==2){
            rotation();
        }
        else if(k==3){
            scaling();
        }
        else if(k==4){
           reflection();
        }
        else if(k==5){
            shearing();
        }
        else if(k==0){
            break;
        }
    }
}
int main(int argc, char** argv){
    printf("Enter The Number Of Vertices :");
    scanf("%d",&n);
    printf("\nEnter The Vertices : ");
    for(int i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i]);
        p[i]=x[i];
        m[i]=y[i];
    }
    transform2d();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("2D Tranformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

