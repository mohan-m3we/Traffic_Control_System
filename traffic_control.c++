#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
#define SPEED 40.0

// Variables for movement and states
float i = 0.0;  // Movement of car
float m = 0.0;  // Movement of clouds
float n = 0.0;  // Movement of plane (x-axis)
float o = 0.0;  // Movement of plane (y-axis)
float c = 0.0;  // Movement of comet
int light = 1;  // 1 = green light, 0 = red light
int day = 1;    // 1 = day, 0 = night
int plane = 0;  // 1 = plane active
int comet = 0;  // 1 = comet active

// Function prototypes
void draw_pixel(GLint cx, GLint cy);
void plotpixels(GLint h, GLint k, GLint x, GLint y);
void draw_circle(GLint h, GLint k, GLint r);
void draw_object();
void traffic_light();
void idle();
void keyboardFunc(unsigned char key, int x, int y);
void main_menu(int index);
void myinit();
void display();

// Function to draw a single pixel
void draw_pixel(GLint cx, GLint cy) {
    glBegin(GL_POINTS);
    glVertex2i(cx, cy);
    glEnd();
}

// Function to plot symmetric pixels for circles
void plotpixels(GLint h, GLint k, GLint x, GLint y) {
    draw_pixel(x + h, y + k);
    draw_pixel(-x + h, y + k);
    draw_pixel(x + h, -y + k);
    draw_pixel(-x + h, -y + k);
    draw_pixel(y + h, x + k);
    draw_pixel(-y + h, x + k);
    draw_pixel(y + h, -x + k);
    draw_pixel(-y + h, -x + k);
}

// Function to draw a circle using the midpoint algorithm
void draw_circle(GLint h, GLint k, GLint r) {
    GLint d = 1 - r, x = 0, y = r;
    while (y > x) {
        plotpixels(h, k, x, y);
        if (d < 0) d += 2 * x + 3;
        else {
            d += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    }
    plotpixels(h, k, x, y);
}

// Function to draw the main objects (background, cars, trees, etc.)
void draw_object() {
    int l;

    if (day == 1) {
        // Day Sky
        glColor3f(0.0, 0.9, 0.9);
        glBegin(GL_POLYGON);
        glVertex2f(0, 450);
        glVertex2f(0, 700);
        glVertex2f(1100, 700);
        glVertex2f(1100, 450);
        glEnd();

        // Sun
        for (l = 0; l <= 35; l++) {
            glColor3f(1.0, 0.9, 0.0);
            draw_circle(100, 625, l);
        }

        // Clouds
        for (l = 0; l <= 20; l++) {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(160 + m, 625, l);
        }
        for (l = 0; l <= 35; l++) {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(200 + m, 625, l);
            draw_circle(225 + m, 625, l);
        }
    } else {
        // Night Sky
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0, 450);
        glVertex2f(0, 700);
        glVertex2f(1100, 700);
        glVertex2f(1100, 450);
        glEnd();

        // Moon
        for (l = 0; l <= 35; l++) {
            glColor3f(1.0, 1.0, 1.0);
            draw_circle(100, 625, l);
        }
    }
    glFlush();
}

// Function to control the traffic light
void traffic_light() {
    int l;
    if (light == 1) {
        // Green Light
        for (l = 0; l <= 20; l++) {
            glColor3f(0.0, 0.7, 0.0);
            draw_circle(1065, 375, l);
        }
    } else {
        // Red Light
        for (l = 0; l <= 20; l++) {
            glColor3f(1.0, 0.0, 0.0);
            draw_circle(1065, 475, l);
        }
    }
}

// Function to handle idle animations
void idle() {
    if (light == 0 && (i >= 330 && i <= 750)) {
        i += SPEED / 10;
        m += 1;
    } else {
        i += SPEED / 10;
        m += 1;
    }

    if (i > 1630) i = 0.0;
    if (m > 1100) m = 0.0;

    glutPostRedisplay();
}

// Keyboard input handler
void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
    case 'g': case 'G': light = 1; break;
    case 'r': case 'R': light = 0; break;
    case 'd': case 'D': day = 1; break;
    case 'n': case 'N': day = 0; break;
    }
}

// Menu handler
void main_menu(int index) {
    if (index == 1) plane = 1;
    if (index == 2) comet = 1;
    if (index == 3) exit(0);
}

// Initialization function
void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    traffic_light();
    glFlush();
}

// Main function
int main(int argc, char* argv[]) {
    int c_menu;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1100, 700);
    glutInitWindowPosition(250, 0);
    glutCreateWindow("Traffic Control");
    myinit();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);

    c_menu = glutCreateMenu(main_menu);
    glutAddMenuEntry("Aeroplane", 1);
    glutAddMenuEntry("Comet", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
