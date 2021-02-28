#include <GL/freeglut.h>
#include <GL/glu.h>

void displayFunction() {

    gluOrtho2D(-100, 100, -100, 100);


    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TEST");
    glutDisplayFunc(displayFunction);
    glutMainLoop();

    return 0;
}
