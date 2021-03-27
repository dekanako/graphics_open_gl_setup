#include<gl\glut.h>
#include <cmath>

static const int left = 0;

static const int right = 100;

static const int bottom = 0;

static const int top = 100;

static const int groundY = 60;

void sky();

void ground();

void house();

void triangle();

void rectangle();

void square();

void hospital();

void flat();

void trees();

void road();

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void mydisplay() {
    gluOrtho2D(left, right, bottom, top);

    sky();
    ground();
    house();

    hospital();

    flat();
    trees();

    road();

    glFlush();
}

void road() {
    glColor3ub(61, 61, 92);
    glPushMatrix();
    glTranslatef(0, 10, 0);
    glScalef(10, 5, 0);
    rectangle();
    glPopMatrix();

    int initialLeft = 2;
    glColor3ub(255, 255, 255);
    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(initialLeft, 22, 0);
        glScalef(0.7, 0.5, 0);
        rectangle();
        glPopMatrix();
        initialLeft = initialLeft + 14;
    }

}

void trees() {

    glColor3ub(118, 92, 72);
    glPushMatrix();
    glTranslatef(left + 30, groundY - 25, 0);
    glScalef(0.2, 2.5, 0);
    rectangle();
    glPopMatrix();

    glColor3ub(66, 105, 47);
    glPushMatrix();
    glTranslatef(left + 25, groundY - 15, 0);
    glScalef(3, 3,0);
    triangle();
    glPopMatrix();

    glColor3ub(66, 105, 47);
    glPushMatrix();
    glTranslatef(left + 25, groundY - 18, 0);
    glScalef(3, 3,0);
    triangle();
    glPopMatrix();

}

void flat() {
    glColor3ub(255, 255, 0);
    glPushMatrix();
    drawFilledCircle(left + 55, top - 10, 4);
    glPopMatrix();

    //body
    glColor3ub(21, 34, 56);
    glPushMatrix();
    glTranslatef(left + 50, groundY, 0);
    glScalef(1, 6, 0);
    rectangle();
    glPopMatrix();

    //windows
    int initialY = groundY + 26;
    glColor3ub(255, 255, 0);
    for (int i = 0; i <4; ++i) {
        glPushMatrix();
        glTranslatef(left + 51.5, initialY, 0);
        glScalef(0.7, 0.4, 0);
        rectangle();
        glPopMatrix();
        initialY = initialY - 5;
    }


}


void hospital() {
    //body
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslatef(left + 5, groundY, 0);
    glScalef(2, 3, 0);
    rectangle();
    glPopMatrix();

    //row Left
    glColor3ub(105, 105, 105);
    glPushMatrix();
    glTranslatef(left + 5, groundY, 0);
    glScalef(0.2, 3.5, 0);
    rectangle();
    glPopMatrix();

    //rowRight
    glPushMatrix();
    glTranslatef(left + 25, groundY, 0);
    glScalef(0.2, 3.5, 0);
    rectangle();
    glPopMatrix();

    //symbol
    glColor3ub(255, 0, 0);
    glPushMatrix();
    glTranslatef(left + 13.5, groundY + 11, 0);
    glScalef(0.7, 0.1, 0);
    square();
    glPopMatrix();


    //symbol
    glColor3ub(255, 0, 0);
    glPushMatrix();
    glTranslatef(left + 15.2, groundY + 8, 0);
    glScalef(0.1, 0.7, 0);
    square();
    glPopMatrix();

    //Door
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(left + 13.5, groundY, 0);
    glScalef(0.4, 1.3, 0);
    rectangle();
    glPopMatrix();

}

void house() {
    int bodyX = right - 20;
    //body
    glColor3ub(150, 111, 51);
    glPushMatrix();
    glTranslatef(bodyX, groundY, 0);
    glScalef(0.6, 2.6, 0);
    rectangle();
    glPopMatrix();

    //ceiling
    glColor3ub(139, 69, 19);
    glPushMatrix();
    glTranslatef(bodyX - 2.5, groundY + 11, 0);
    glScalef(2.9, 2.9,0);
    triangle();
    glPopMatrix();

    //Door
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(bodyX + 1, groundY, 0);
    glScalef(0.2, 1.3, 0);
    rectangle();
    glPopMatrix();
}


void square(){
    glRectf(0, 0,6, 9);
}

void rectangle() {
    glRectf(left, 5 , 10, 0);
}

void triangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(2,2);// top
    glVertex2f(4, 0);// bottom right
    glVertex2f(0, 0);// bottom left
    glEnd();
}

void ground() {
    glColor3ub(73, 155, 74);
    glRectf(left,groundY , right, 0);
}

void sky() {
    glColor3ub(135, 206, 235);
    glRectf(left, top, right, 60);

    glColor3ub(253, 184, 19);

    //sun
    drawFilledCircle(15, top - 10, 8);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 785);
    glutInitWindowPosition(5, 5);
    glutCreateWindow("Open GL");
    glutDisplayFunc(mydisplay);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMainLoop();
}