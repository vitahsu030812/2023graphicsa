#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glBegin(GL_LINE_LOOP);
    {
    glVertex2f(0.013, 0.380);
    glVertex2f(0.067, 0.387);
    glVertex2f(0.140, 0.460);
    glVertex2f(0.193, 0.500);
    glVertex2f(0.273, 0.487);
    glVertex2f(0.333, 0.453);
    glVertex2f(0.380, 0.387);
    glVertex2f(0.440, 0.307);
    glVertex2f(0.447, 0.253);
    glVertex2f(0.433, 0.207);
    glVertex2f(0.413, 0.127);
    glVertex2f(0.387, 0.060);
    glVertex2f(0.360, 0.007);
    glVertex2f(0.333, -0.027);
    glVertex2f(0.327, -0.080);
    glVertex2f(0.293, -0.113);
    glVertex2f(0.240, -0.160);
    glVertex2f(0.153, -0.240);
    glVertex2f(0.073, -0.260);
    glVertex2f(0.000, -0.260);
    glVertex2f(-0.047, -0.227);
    glVertex2f(-0.127, -0.160);
    glVertex2f(-0.180, -0.120);
    glVertex2f(-0.220, -0.093);
    glVertex2f(-0.253, -0.060);
    glVertex2f(-0.293, -0.007);
    glVertex2f(-0.353, 0.053);
    glVertex2f(-0.407, 0.120);
    glVertex2f(-0.427, 0.200);
    glVertex2f(-0.433, 0.327);
    glVertex2f(-0.407, 0.400);
    glVertex2f(-0.380, 0.447);
    glVertex2f(-0.340, 0.453);
    glVertex2f(-0.300, 0.467);
    glVertex2f(-0.273, 0.480);
    glVertex2f(-0.273, 0.480);

    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X=(x-150)/150.0;
    float Y=-(y-150)/150.0;
    if(state==GLUT_DOWN)
    {
        printf("    glVertex2f(%.3f, %.3f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
