#include <iostream>

#include <GL/freeglut.h>

void myDisplay() {
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glVertex2i(0, -1);
    glVertex2i(1, -1);
    glVertex2i(-1, -1);
    glVertex2i(-1, 1);
    glEnd();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TEST");
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
