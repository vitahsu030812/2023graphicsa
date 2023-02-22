#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0);
    ///glutSolidTeapot(0.5);
    glBegin(GL_POLYGON);///開始畫多邊形
        glColor3f(1,0,0); glVertex2f(0,1);///紅色頂點Vertex
        glColor3f(0,1,0); glVertex2f(-1,-1);///綠色頂點Vertex
        glColor3f(0,0,1); glVertex2f(1,-1);///藍色頂點Vertex
    glEnd();///結束畫
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);///畫出實心茶壺大小為0.3
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
