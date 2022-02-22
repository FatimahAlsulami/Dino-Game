#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>

//GROUP 2 /Layan Bitrah ,Fatimah al-sulami ,Asil al-hebshi ,Wejdan alqhtani 
//Section VAR
using namespace std;
#include <Windows.h>
#include <MMSystem.h>

//constants
static int animationPeriod = 4;
static int isAnimate = 0;
//to control by dino size 
const int fact = 3;
const int x = 80;
//to draw the tree
float theta;
#define PI =3.14159265
const double DEG2RAD = 3.1415926535897932384 / 180;
//constant
static double w = 50;
static int flag = 0;
static int walk = 0;
//first point to draw wall
static int x_init = 2500;
string s1, s2, s3;
//-----------------------------------------------------------

//to write string in the screen
void write_string_to_screen(float x, float y, float z, char* str) {

    glRasterPos3d(x, y, z);        //move curser to this position
    for (int i = 0; i < strlen(str); i++)  // loop over the string and write each char
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);

}
//-----------------------------------------------------------

//countinu movement to the game
void animate(int value) {
    if (isAnimate) {

        glutPostRedisplay();
        glutTimerFunc(animationPeriod, animate, 1);
    }
}
//-----------------------------------------------------------


bool collision(double len) {
    if (abs(157 + x - (x_init + x + 50)) <= 100 + x) {
        if (5 * fact + w <= 650 * len)
            return 1;
        return 0;
    }
    return 0;
}

//-----------------------------------------------------------

//for jump
void specialKeyInput(int key, int x, int y) {
    if (key == GLUT_KEY_UP && flag == 0 && w <= 200.0) {
        flag = 1;
    }
    glutPostRedisplay();
}
//------------------------------------------------------------------

//to generate the wall
void generate_Wall(int x_init, double len) {
    //draw wall method

    int x = 30;//width
    glColor3f(0.7, 0.3, 0);//wall color
    glBegin(GL_POLYGON);
    glVertex3f(x_init, 250 * len, 0);//1
    glVertex3f(x_init + x, 250 * len, 0);//2
    glVertex3f(x_init + x, 650 * len, 0);//3
    glVertex3f(x_init, 650 * len, 0);//4
    glEnd();


}
//---------------------------------------------------------------------


void reset() {
    // reset the wall when hit by the object
    w = 200;
    flag = 0;
    walk = 0;
    x_init = 2500;
    animationPeriod = 4;
    isAnimate = 0;
}
//------------------------------------------------------------------------


void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    s1 = "Dino game...";
    write_string_to_screen(10, 1850, -200, &s1[0]);

    //draw_tree
    //1
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(200, 280, 200);//(x,y,z)
    glScalef(0.7, 1.0, 1.0);
    glutSolidSphere(250, 20, 15);//the size
    glPopMatrix();

    //2
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(700, 270, 200);
    glScalef(0.7, 1.0, 1.0);
    glutSolidSphere(250, 20, 15);
    glPopMatrix();

    //2
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(730 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(650 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(700 + 10 * cos(theta), 350 + 15 * sin(theta));
    }
    glEnd();
    //3
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(1200, 270, 200);
    glScalef(0.7, 1.0, 1.0);
    glutSolidSphere(250, 20, 15);
    glPopMatrix();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1150 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1240 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1200 + 10 * cos(theta), 350 + 15 * sin(theta));
    }
    glEnd();

    //4
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(1700, 270, 200);
    glScalef(0.7, 1.0, 1.0);
    glutSolidSphere(250, 20, 15);
    glPopMatrix();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1650 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();

    //4
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1750 + 10 * cos(theta), 300 + 15 * sin(theta));
    }
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1700 + 10 * cos(theta), 350 + 15 * sin(theta));
    }
    glEnd();

    //begin  the stret
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0, 250);
    glVertex2f(2000, 250);
    glEnd();

    // the stret
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.7, 0.3);
    glVertex2f(0, 250);
    glVertex2f(2000, 250);
    glVertex2f(2000, 0);
    glVertex2f(0, 0);
    glEnd();


    // cloud
    //1
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(358 + 100 * cos(theta), 1700 + 150 * sin(theta));
    }
    glEnd();

    //1
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(270 + 100 * cos(theta), 1600 + 150 * sin(theta));
    }
    glEnd();
    //1
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(400 + 100 * cos(theta), 1620 + 150 * sin(theta));
    }
    glEnd();

    // cloud2
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1058 + 100 * cos(theta), 1850 + 150 * sin(theta));
    }
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(970 + 100 * cos(theta), 1750 + 150 * sin(theta));
    }
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1100 + 100 * cos(theta), 1750 + 150 * sin(theta));
    }
    glEnd();



    // cloud3
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1558 + 100 * cos(theta), 1750 + 150 * sin(theta));
    }
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1500 + 100 * cos(theta), 1670 + 150 * sin(theta));
    }
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(1630 + 100 * cos(theta), 1680 + 150 * sin(theta));
    }
    glEnd();

    //Sun
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);//the color
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.14159265 / 180;
        glVertex2f(700 + 110 * cos(theta), 1800 + 165 * sin(theta));
    }
    glEnd();

    //x_init= 2500 draw the wall on the floor 
    generate_Wall(x_init, 1.0);
    if (x_init >= 0)
        x_init -= 10;
    else {
        x_init = 100 + rand() % 2000;
    }

    //dino
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);
    glVertex3f(10 + x, 95 * fact + w, 0);
    glVertex3f(10 + x, 65 * fact + w, 0);
    glVertex3f(15 + x, 85 * fact + w, 0);
    glVertex3f(15 + x, 60 * fact + w, 0);
    glVertex3f(20 + x, 80 * fact + w, 0);
    glVertex3f(20 + x, 55 * fact + w, 0);
    glVertex3f(25 + x, 75 * fact + w, 0);
    glVertex3f(25 + x, 55 * fact + w, 0);
    glVertex3f(30 + x, 75 * fact + w, 0);
    glVertex3f(30 + x, 55 * fact + w, 0);
    glVertex3f(35 + x, 75 * fact + w, 0);
    glVertex3f(35 + x, 45 * fact + w, 0);
    glVertex3f(40 + x, 80 * fact + w, 0);
    glVertex3f(40 + x, 25 * fact + w - walk, 0);
    glVertex3f(45 + x, 85 * fact + w, 0);
    glVertex3f(45 + x, 35 * fact + w, 0);
    glVertex3f(45 + x, 30 * fact + w - walk, 0);
    glVertex3f(45 + x, 25 * fact + w - walk, 0);
    glVertex3f(50 + x, 30 * fact + w - walk, 0);
    glVertex3f(50 + x, 25 * fact + w - walk, 0);
    glVertex3f(55 + x, 30 * fact + w - walk, 0);
    glVertex3f(55 + x, 25 * fact + w - walk, 0);
    glVertex3f(50 + x, 85 * fact + w, 0);
    glVertex3f(50 + x, 40 * fact + w, 0);
    glVertex3f(55 + x, 90 * fact + w, 0);
    glVertex3f(55 + x, 45 * fact + w, 0);
    glVertex3f(63 + x, 95 * fact + w, 0);
    glVertex3f(63 + x, 40 * fact + w, 0);
    glVertex3f(70 + x, 135 * fact + w, 0);
    glVertex3f(70 + x, 25 * fact + w + walk, 0);
    glVertex3f(78 + x, 140 * fact + w, 0);
    glVertex3f(78 + x, 45 * fact + w, 0);
    glVertex3f(78 + x, 30 * fact + w + walk, 0);
    glVertex3f(78 + x, 25 * fact + w + walk, 0);
    glVertex3f(85 + x, 30 * fact + w + walk, 0);
    glVertex3f(85 + x, 25 * fact + w + walk, 0);
    glVertex3f(87 + x, 140 * fact + w, 0);
    glVertex3f(87 + x, 135 * fact + w, 0);
    glVertex3f(87 + x, 130 * fact + w, 0);
    glVertex3f(87 + x, 50 * fact + w, 0);
    glVertex3f(95 + x, 140 * fact + w, 0);
    glVertex3f(95 + x, 55 * fact + w, 0);
    glVertex3f(103 + x, 140 * fact + w, 0);
    glVertex3f(103 + x, 95 * fact + w, 0);
    glVertex3f(103 + x, 85 * fact + w, 0);
    glVertex3f(103 + x, 80 * fact + w, 0);
    glVertex3f(110 + x, 85 * fact + w, 0);
    glVertex3f(110 + x, 80 * fact + w, 0);
    glVertex3f(118 + x, 85 * fact + w, 0);
    glVertex3f(118 + x, 75 * fact + w, 0);
    glVertex3f(112 + x, 140 * fact + w, 0);
    glVertex3f(112 + x, 105 * fact + w, 0);
    glVertex3f(112 + x, 100 * fact + w, 0);
    glVertex3f(112 + x, 95 * fact + w, 0);
    glVertex3f(120 + x, 140 * fact + w, 0);
    glVertex3f(120 + x, 105 * fact + w, 0);
    glVertex3f(120 + x, 100 * fact + w, 0);
    glVertex3f(120 + x, 95 * fact + w, 0);
    glVertex3f(126 + x, 140 * fact + w, 0);
    glVertex3f(126 + x, 105 * fact + w, 0);
    glVertex3f(126 + x, 100 * fact + w, 0);
    glVertex3f(126 + x, 95 * fact + w, 0);
    glVertex3f(135 + x, 140 * fact + w, 0);
    glVertex3f(135 + x, 105 * fact + w, 0);
    glVertex3f(135 + x, 100 * fact + w, 0);
    glVertex3f(135 + x, 95 * fact + w, 0);
    glVertex3f(142 + x, 140 * fact + w, 0);
    glVertex3f(142 + x, 105 * fact + w, 0);
    glVertex3f(150 + x, 140 * fact + w, 0);
    glVertex3f(150 + x, 105 * fact + w, 0);
    glVertex3f(157 + x, 135 * fact + w, 0);
    glVertex3f(157 + x, 105 * fact + w, 0);
    glEnd();

    if (collision(1.0)) {
        reset();
    }
    //to move the foot
    if (w <= 300) {
        if (walk == -20)
            walk = 20;
        else {
            walk = -20;
        }
    }
    else {
        walk = 0;
    }

    if (flag == 1) {
        if (w <= 1000) {
            w = w + 8;
        }
        else {
            flag = 0;
        }
    }
    else if (w >= 200)
        w = w - 8;

    glFlush();
}
//---------------------------------------------------------------------
//method of interface page
void welcome() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos3f(900, 1000, 0);
    char msg[] = "DanoGame";
    for (int i = 0; i < strlen(msg); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[i]);

    glRasterPos3f(820, 700, 0);
    char msg5[] = "Press p to start play";
    for (int i = 0; i < strlen(msg5); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg5[i]);
    glutSwapBuffers();
}

//control of keys to upper second page
void Start_display() {
    glutDisplayFunc(draw);
    glutPostRedisplay();
}

void keyInput(unsigned char key, int x, int y) {
    switch (key) {
        // to start the game
    case 'P':
    case 'p':
        Start_display();
        break;
        //close the game windo
    case 'E':
    case 'e':
        exit(0);
        break;

        //enable lighting
    case 'L':
    case 'l':
        glEnable(GL_LIGHT0);
        break;
        //turn off the light
    case 'D':
    case 'd':
        glDisable(GL_LIGHT0);
        break;

        //run to the wall and stop
    case ' ':
        if (isAnimate) isAnimate = 0;
        else {
            isAnimate = 1;
            animate(1);//call the method and redisplay
        }
        break;
        //for enable the sound   
    case 'S':
    case 's':
        bool Played = PlaySound(TEXT("Monk.wav"), NULL, SND_SYNC);// the sound 
        break;
    }
    glutPostOverlayRedisplay();

}




void background(void) {
    //Back graund color
    glClearColor(0.9, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 2000, 0.0, 2000, 0.0, 2000);

    //lighting

    float dif[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
    float amb[] = { 0.2,0.2,0.2,1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);

    float position[] = { 0.0,0.0,-7000.0 ,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

}


//------------------------------------------------------------------
int main(int argc, char** argv) {

    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1230, 650);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Dinosaur!!");
    background();
    glutDisplayFunc(welcome);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);
    ////////////////////////////////////////////////////////////
    glutMainLoop();
    return 0;
}