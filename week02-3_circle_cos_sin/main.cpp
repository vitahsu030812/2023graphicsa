#include <GL/glut.h>
#include <math.h>
void myCircle(float r,float x,float y)
{
    glBegin(GL_POLYGON);
        for(float a=0;a<2*3.141592653589793238462632383279;a+=0.01)
        {
            glVertex2f(r*cos(a)+x,r*sin(a)+y);
        }
    glEnd();
}
void display()
{
    glColor3f(1,0,1); myCircle(0.6,0,0);
    glColor3f(1,0,0); myCircle(0.3,0.5,0.5);
    glColor3f(0,1,0); myCircle(0.3,-0.5,0.5);
    glColor3f(1,1,0); myCircle(0.3,-0.5,-0.5);
    glColor3f(0,0,1); myCircle(0.3,0.5,-0.5);
    glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///�}��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes");///�}�ҵ���
    glutDisplayFunc(display);///��ܹ������
    glutMainLoop();///�ϥ�main�j������
}
