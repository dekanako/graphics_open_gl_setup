#include<gl\glut.h>

void drawSq();

void drawHead();

void drawEyesAndNoes();

void drawBody();

void drawFeet();

void drawHands();

void draw() {
    drawHands();
    drawHead();
    drawEyesAndNoes();
    drawBody();
    drawFeet();
}

void drawHands() {
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0);
    glTranslatef(163, 109, 0);
    glRotatef(120, 0,0,1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(15, 30);
    glVertex2i(15, 0);
    glEnd();
    glColor3f(255, 0.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(15, 30);
    glVertex2i(15, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0);
    glTranslatef(205, 120, 0);
    glRotatef(240, 0,0,1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(15, 30);
    glVertex2i(15, 0);
    glEnd();
    glColor3f(255, 0.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(15, 30);
    glVertex2i(15, 0);
    glEnd();
    glPopMatrix();
}

void drawFeet() {
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0);
    glTranslatef(188, 16, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(10, 30);
    glVertex2i(10, 0);
    glEnd();
    glColor3f(255, 0.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(10, 30);
    glVertex2i(10, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0);
    glTranslatef(162, 16, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(10, 30);
    glVertex2i(10, 0);
    glEnd();
    glColor3f(255, 0.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 30);
    glVertex2i(10, 30);
    glVertex2i(10, 0);
    glEnd();
    glPopMatrix();
}

void drawBody() {
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(46.7, 14, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 25);
    glVertex2i(15, 25);
    glVertex2i(15, 0);
    glEnd();

    glColor3f(255, 0.0, 1.0);
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 25);
    glVertex2i(15, 25);
    glVertex2i(15, 0);
    glEnd();

    glPopMatrix();
}


void drawHead() {
    glPushMatrix();
    glTranslatef(39, 39, 0);
    glScalef(3, 3, 0);
    glColor3f(1.0, 0.0, 1.0);
    drawSq();
    glPopMatrix();
}

void drawEyesAndNoes() {
    glPushMatrix();
    glTranslatef(39, 39, 0);
    glScalef(3, 3, 0);
    glColor3f(1.0, 0.0, 1.0);
    int yAxis = 8;
    glBegin(GL_LINES);
    glVertex2f(1, yAxis);
    glVertex2f(4, yAxis);

    glVertex2f(6, yAxis);
    glVertex2f(9, yAxis);

    int noseYAxis = 6;
    glVertex2i(5, noseYAxis);
    glVertex2i(5, noseYAxis + -2);

    glVertex2f(3, 2);
    glVertex2f(7, 2);

    glEnd();
    glPopMatrix();
}

void drawSq() {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 10);
    glVertex2i(10, 10);
    glVertex2i(10, 0);
    glEnd();

    glColor3f(255, 0.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 0);
    glVertex2i(0, 10);
    glVertex2i(10, 10);
    glVertex2i(10, 0);
    glEnd();

}

void mydisplay() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 100, 0, 100);

    draw();

    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Open GL");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
}