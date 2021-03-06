#include<gl\glut.h>
#include <cmath>

static const int left = 0;

static const int right = 100;

static const int bottom = 0;

static const int top = 100;

static const int groundY = 60;

bool stop = false;
void sky();

void ground();

void house();

void triangle();

void rectangle();

void square();

void hospital();

void skyScraper();

void trees();

void road();

void cars(int red, int green, int blue);

void rails();

void line();

void trains();

void movingTrains();

void trafficLights();

void movingCars();

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);

    sky();
    ground();
    house();

    hospital();

    skyScraper();
//    trees();

    road();
    movingCars();

    rails();
    glutSwapBuffers();
}

const float car1Speed = 0.01;
const float car2Speed = -0.01;
float car1X = 0;
float car2X = 20;

void movingCars() {

    if (car1X >= right){
        car1X = -30;
    }
    if (car2X <= left - 30){
        car2X = right + 30;
    }

    car1X = car1X + car1Speed;
    car2X = car2X + car2Speed;

    glPushMatrix();
    glTranslatef(car1X, 0, 0);
    cars(65, 111, 66);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car2X, 17, 0);
    cars(49, 153, 204);
    glPopMatrix();

}

const int RAILS_X_START = left;

const int UPPER_RAIL_Y = groundY - 45;
const int DOWNER_RAIL_Y = UPPER_RAIL_Y - 15;
const float RAILS_WIDTH = 0.2;

void rails() {
    glColor3ub(0, 0, 0);
    //upper rail
    glPushMatrix();
    glTranslatef(RAILS_X_START, UPPER_RAIL_Y, 0);
    glScalef(20, RAILS_WIDTH, 0);
    square();
    glPopMatrix();
    //down rail
    glPushMatrix();
    glTranslatef(RAILS_X_START, DOWNER_RAIL_Y, 0);
    glScalef(20, RAILS_WIDTH, 0);
    square();
    glPopMatrix();

    glColor3ub(0, 0, 0);
    int initialX = RAILS_X_START;
    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(initialX + 5, DOWNER_RAIL_Y, 0);
        glScalef(0.3, 1.7, 0);
        square();
        glPopMatrix();
        initialX = initialX + 10;
    }

    trafficLights();
    movingTrains();
}

const float TRAFFIC_STAND_X = right - 10;

void trafficLights() {
    const float TRAFFIC_STAND_Y = UPPER_RAIL_Y;

    const float LIGHT_CONTAINER_Y = TRAFFIC_STAND_Y + 10;
    const float LIGHT_CONTAINER_X = TRAFFIC_STAND_X - 1.8;

    //stand
    glColor3ub(51, 51, 51);
    glPushMatrix();
    glTranslatef(TRAFFIC_STAND_X, TRAFFIC_STAND_Y, 0);
    glScalef(0.2, 2.1, 0);
    square();
    glPopMatrix();

    //lights container
    glColor3ub(76, 76, 76);
    glPushMatrix();
    glTranslatef(LIGHT_CONTAINER_X, LIGHT_CONTAINER_Y, 0);
    glScalef(0.8, 1.4, 0);
    square();
    glPopMatrix();

    //LIGHTS
    const float LIGHTS_X = LIGHT_CONTAINER_X + 2.4;
    const float LIGHTS_Y = LIGHT_CONTAINER_Y + 2.4;
    if (stop) {
        glColor3ub(255, 0, 0);
        drawFilledCircle(LIGHTS_X, LIGHTS_Y + 6, 1.5);

        glColor3ub(0, 0, 0);
        drawFilledCircle(LIGHTS_X, LIGHTS_Y + 2, 1.5);
    } else {
        glColor3ub(0, 0, 0);
        drawFilledCircle(LIGHTS_X, LIGHTS_Y + 6, 1.5);

        glColor3ub(0, 255, 0);
        drawFilledCircle(LIGHTS_X, LIGHTS_Y + 2, 1.5);
    }


}

float const speed = 0.006;
float trainX = -40;
float trainSpeed = speed;

void movingTrains() {
    if (trainX > right + 20) {
        trainX = -40;
    }
    trainX = trainX + trainSpeed;
    glPushMatrix();
    glTranslatef(trainX, DOWNER_RAIL_Y + 3, 0);
    trains();
    glPopMatrix();
}

void trains() {
    const int TRAIN_TIRES_Y = DOWNER_RAIL_Y + 3;
    //train connector
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(-1, TRAIN_TIRES_Y, 0);
    glScalef(1.3, 0.2, 0);
    square();
    glPopMatrix();

    //hood dispenser
    glColor3ub(49, 153, 204);
    glPushMatrix();
    glTranslatef(25, TRAIN_TIRES_Y + 10, 0);
    glScalef(1, 1, 0);
    square();
    glPopMatrix();

    //dispenser cup
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(24.2, TRAIN_TIRES_Y + 18, 0);
    glScalef(1.3, 0.3, 0);
    square();
    glPopMatrix();

    //train storage room
    glColor3ub(166, 42, 42);
    glPushMatrix();
    glTranslatef(7, TRAIN_TIRES_Y + 3, 0);
    glScalef(2, 2.2, 0);
    square();
    glPopMatrix();

    //hood
    glColor3ub(166, 42, 42);
    glPushMatrix();
    glTranslatef(19, TRAIN_TIRES_Y + 3, 0);
    glScalef(1.5, 2.3, 0);
    rectangle();
    glPopMatrix();


    //storage widnows
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslatef(8.3, TRAIN_TIRES_Y + 4.5, 0);
    glScalef(1.6, 1.8, 0);
    square();
    glPopMatrix();


    glColor3ub(49, 153, 204);
    glPushMatrix();
    glTranslatef(6, TRAIN_TIRES_Y, 0);
    glScalef(3, 1, 0);
    rectangle();
    glPopMatrix();

    //hood
    glColor3ub(49, 153, 204);
    glPushMatrix();
    glTranslatef(6, TRAIN_TIRES_Y, 0);
    glScalef(3, 1, 0);
    rectangle();
    glPopMatrix();


    glColor3ub(255, 63, 4);
    glPushMatrix();
    drawFilledCircle(10, TRAIN_TIRES_Y, 3);
    glPopMatrix();

    glColor3ub(255, 63, 4);
    glPushMatrix();
    drawFilledCircle(30, TRAIN_TIRES_Y, 3);
    glPopMatrix();



    //Second train
    //base
    glPushMatrix();
    glColor3ub(65, 111, 66);
    glPushMatrix();
    glTranslatef(-22, TRAIN_TIRES_Y, 0);
    glScalef(4, 2, 0);
    square();
    glPopMatrix();

    //base
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glPushMatrix();
    glTranslatef(-17, TRAIN_TIRES_Y + 7, 0);
    glScalef(2.4, 1, 0);
    square();
    glPopMatrix();

    //tire left
    glColor3ub(255, 63, 4);
    glPushMatrix();
    drawFilledCircle(-17, TRAIN_TIRES_Y, 3);
    glPopMatrix();

    //tire right
    glColor3ub(255, 63, 4);
    glPushMatrix();
    drawFilledCircle(-3, TRAIN_TIRES_Y, 3);
    glPopMatrix();

}

const float asphaltY = 35;

void cars(int red, int green, int blue) {
    int carX = 10;
    int carY = asphaltY + 3;
    //car body
    glColor3ub(red, green, blue);
    glPushMatrix();
    glTranslatef(carX, carY, 0);
    glScalef(1.5, 1.5, 0);
    rectangle();
    glPopMatrix();

    //tire1
    glColor3ub(0, 0, 0);
    drawFilledCircle(carX + 3, asphaltY + 3, 2);

    //tire2
    glColor3ub(0, 0, 0);
    drawFilledCircle(carX + 11.5, asphaltY + 3, 2);

    //glass
    glColor3ub(255, 127, 0);
    glPushMatrix();
    glTranslatef(carX + 2.5, carY + 7.5, 0);
    glScalef(1, 1, 0);
    rectangle();
    glPopMatrix();
}

void road() {
    //Asphalt
    glColor3ub(61, 61, 92);
    glPushMatrix();
    glTranslatef(0, asphaltY, 0);
    glScalef(10, 5, 0);
    rectangle();
    glPopMatrix();

    //street lines
    int initialLeft = 2;
    glColor3ub(255, 255, 255);
    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(initialLeft, asphaltY + 12, 0);
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
    glScalef(3, 3, 0);
    triangle();
    glPopMatrix();

    glColor3ub(66, 105, 47);
    glPushMatrix();
    glTranslatef(left + 25, groundY - 18, 0);
    glScalef(3, 3, 0);
    triangle();
    glPopMatrix();

}

void skyScraper() {
    glutStrokeCharacter(GLUT_BITMAP_8_BY_13, '$');  // Updates the position

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
    for (int i = 0; i < 4; ++i) {
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
    glScalef(2.9, 2.9, 0);
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


void square() {
    glRectf(0, 0, 6, 9);
}

void rectangle() {
    glRectf(left, 5, 10, 0);
}

void triangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(2, 2);// top
    glVertex2f(4, 0);// bottom right
    glVertex2f(0, 0);// bottom left
    glEnd();
}

void ground() {
    glColor3ub(73, 155, 74);
    glRectf(left, groundY, right, 0);
}

void sky() {
    glColor3ub(135, 206, 235);
    glRectf(left, top, right, 60);

    glColor3ub(253, 184, 19);

    //sun
    drawFilledCircle(15, top - 10, 8);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r') {
        stop = true;
        trainSpeed = 0.0;

        glutPostRedisplay();
    } else if (key == 'g') {
        stop = false;
        trainSpeed = speed;
        glutPostRedisplay();
    }

}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 785);
    glutInitWindowPosition(5, 5);
    glutCreateWindow("Open GL");
    glutDisplayFunc(mydisplay);
    glutIdleFunc(mydisplay);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutKeyboardFunc(keyboard);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMainLoop();
}