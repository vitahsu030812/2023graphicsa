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
    glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///開啟GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///設定顯示模式
    glutCreateWindow("GLUT Shapes");///開啟視窗
    glutDisplayFunc(display);///顯示對應函數
    glutMainLoop();///使用main迴圈壓後
}
