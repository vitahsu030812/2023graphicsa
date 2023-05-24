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
int show[10] = {1,0,1,0,0,1,0,0,0,0};
int ID=2;
FILE*fout=NULL;
FILE*fin=NULL;
float teapotX=0,teapotY=0;
///float angle=0,angle2=0,angle3=0;
float angle[20]={};
void keyboard(unsigned char key,int x,int y){
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='6') ID=6;
    if(key=='7') ID=7;
    if(key=='8') ID=8;
    if(key=='9') ID=9;
    if(key=='s'){
        if(fout==NULL) fout=fopen("motion.txt","w");
        for(int i=0;i<20;i++){
            fprintf(fout,"%.2f ",angle[i]);
        }
        fprintf(fout,"\n");
    }
    else if(key=='r'){
        if(fin==NULL) fin=fopen("motion.txt","r");
        for(int i=0;i<20;i++)
        {
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay();
    }
    glutPostRedisplay();
}
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
        if(ID==0) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[0]) glmDraw(body, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(head, GLM_MATERIAL);



        if(ID==3) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[3]) glmDraw(downarmL, GLM_MATERIAL);

        if(ID==4) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[4]) glmDraw(uparmL, GLM_MATERIAL);

        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            glTranslatef(-1.213333, +0.400000, 0);
            glRotatef(angle[5],0,0,1);
            glTranslatef(1.213333, -0.400000, 0);
            if(ID==5) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[5]) glmDraw(uparmR, GLM_MATERIAL);

            glPushMatrix();
                glTranslatef(-1.919999, +0.080000, 0);
                //glTranslatef(teapotX,teapotY,0);
                glRotatef(angle[2],0,0,1);
                glTranslatef(1.919999, -0.080000, 0);
                if(ID==2) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[2]) glmDraw(downarmR, GLM_MATERIAL);
            glPopMatrix();

        glPopMatrix();

        if(ID==6) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[6]) glmDraw(downlegR, GLM_MATERIAL);

        if(ID==7) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[7]) glmDraw(downlegL, GLM_MATERIAL);

        if(ID==8) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[8]) glmDraw(uplegL, GLM_MATERIAL);

        if(ID==9) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[9]) glmDraw(uplegR, GLM_MATERIAL);



        glPopMatrix();
        glColor3f(0,1,0);
        glutSolidTeapot(0.02);
        glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x,int y){
    teapotX += (x-oldX)/150.0;
    teapotY -= (y-oldY)/150.0;
    angle[ID] += x-oldX;
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
        ///angle = x;
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
