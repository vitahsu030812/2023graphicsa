#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel*body=NULL;
GLMmodel*head=NULL;
GLMmodel*downarmL=NULL;
GLMmodel*downarmR=NULL;
GLMmodel*uparmL=NULL;
GLMmodel*uparmR=NULL;
GLMmodel*downlegL=NULL;
GLMmodel*downlegR=NULL;
GLMmodel*uplegL=NULL;
GLMmodel*uplegR=NULL;
int show[10] = {0,1,2,3,4,5,6,7,8,9};
void keyboard(unsigned char key,int x,int y){
    if(key=='0') show[0] = !show[0];
    if(key=='1') show[1] = !show[1];
    if(key=='2') show[2] = !show[2];
    if(key=='3') show[3] = !show[3];
    if(key=='4') show[4] = !show[4];
    if(key=='5') show[5] = !show[5];
    if(key=='6') show[6] = !show[6];
    if(key=='7') show[7] = !show[7];
    if(key=='8') show[8] = !show[8];
    if(key=='9') show[9] = !show[9];
    glutPostRedisplay();
}
FILE*fout=NULL;
FILE*fin=NULL;
float teapotX=0,teapotY=0;
float angle=0,angle2=0,angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL){
            body=glmReadOBJ("model/body.obj");
            head=glmReadOBJ("model/head.obj");
            downarmR=glmReadOBJ("model/downarmR.obj");
            downarmL=glmReadOBJ("model/downarmL.obj");
            uparmL=glmReadOBJ("model/uparmL.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            downlegL=glmReadOBJ("model/downlegL.obj");
            downlegR=glmReadOBJ("model/downlegR.obj");
            uplegL=glmReadOBJ("model/uplegL.obj");
            uplegR=glmReadOBJ("model/uplegR.obj");
        }
        if(show[0]) glmDraw(body, GLM_MATERIAL);
        if(show[1]) glmDraw(head, GLM_MATERIAL);
        if(show[2]) glmDraw(downarmR, GLM_MATERIAL);
        if(show[3]) glmDraw(downarmL, GLM_MATERIAL);
        if(show[4]) glmDraw(uparmL, GLM_MATERIAL);
        if(show[5]) glmDraw(uparmR, GLM_MATERIAL);
        if(show[6]) glmDraw(downlegR, GLM_MATERIAL);
        if(show[7]) glmDraw(downlegL, GLM_MATERIAL);
        if(show[8]) glmDraw(uplegL, GLM_MATERIAL);
        if(show[9]) glmDraw(uplegR, GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);

                if(show[2]) glmDraw(downarmL,GLM_MATERIAL);
            glPopMatrix();
            if(show[3]) glmDraw(uparmL,GLM_MATERIAL);
        glPopMatrix();
        glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x,int y){
    teapotX += (x-oldX)/150.0;
    teapotY += (y-oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
        angle = x;
    }
    display();
}
/*void keyboard(unsigned char key,int x,int y)
{
    if(fin==NULL)
    {
        fclose(fout);
        fin=fopen("file4.txt","r");
    }
    fscanf(fin,"%f %f",&teapotX,&teapotY);
    display();
}*/
int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week12");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
