#include "callbacks.h"
#include "scene.h"
#include "GL/glut.h"
#include "init.h"
#include "planet.h"

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0

int is_guide_visible=0;
int pause=0;

int WINDOW_WIDTH;
int WINDOW_HEIGHT;

struct {
    int x;
    int y;
} mouse_position;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&camera);
    draw_scene(&scene,&world);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT, 0.1, 20000.0);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (is_guide_visible) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
        show_guide(world.help,WINDOW_WIDTH,WINDOW_HEIGHT);
    }

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, 10000.0);
}

void mouse(int button, int state, int x, int y)
{
    mouse_position.x = x;
    mouse_position.y = y;
}

void motion(int x, int y)
{
    rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
    mouse_position.x = x;
    mouse_position.y = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
        if (!is_guide_visible) {
            set_camera_speed(&camera, 10);
        }
        break;
    case 's':
        if (!is_guide_visible) {
            set_camera_speed(&camera, -10);
        }
        break;
    case 'a':
        if (!is_guide_visible) {
            set_camera_side_speed(&camera, 10);
        }
        break;
    case 'd':
        if (!is_guide_visible) {
            set_camera_side_speed(&camera, -10);
        }
        break;
    case 'q':
        if (!is_guide_visible) {
            set_camera_up_speed(&camera, -10);
        }
        break;
    case 'e':
        if (!is_guide_visible) {
            set_camera_up_speed(&camera, 10);
        }
        break;   
    case '+':
        update_light_up(&scene);
		break;
	case '-':
		update_light_down(&scene);
		break;
    case 'p':
        if (pause) {
            pause = FALSE;
        }
        else {
            pause = TRUE;
        }
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 's':
        set_camera_speed(&camera, 0.0);
        break;
    case 'a':
    case 'd':
        set_camera_side_speed(&camera, 0.0);
        break;
    case 'q':
    case 'e':
        set_camera_up_speed(&camera, 0.0);
        break;
	}

    glutPostRedisplay();
}

void specialFunc(int key, int x, int y) {
	switch (key)
	{
		case GLUT_KEY_F1:
            if (is_guide_visible) {
                is_guide_visible = FALSE;
            }
            else {
                is_guide_visible = TRUE;
            }
	}
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    set_lighting();
    update_camera(&camera, elapsed_time);
    if (!is_guide_visible && !pause) {
        update_planet(&mercury);
        update_planet(&venus);
        update_planet(&earth);
        update_planet(&mars);
        update_planet(&jupiter);
        update_planet(&moon);
        update_planet(&saturn);
        update_planet(&uranus);
        update_planet(&neptune);

        update_rotation(&mercury, elapsed_time, 10);
        update_rotation(&venus, elapsed_time, 5);
        update_rotation(&sun, elapsed_time, 1);
        update_rotation(&earth, elapsed_time, 8);
        update_rotation(&mars, elapsed_time, -4);
        update_rotation(&jupiter, elapsed_time, 8);
        update_rotation(&moon, elapsed_time, 2);
        update_rotation(&saturn, elapsed_time, 4);
        update_rotation(&uranus, elapsed_time, -3);
        update_rotation(&neptune, elapsed_time, -9);
    }

    glutPostRedisplay();
    
}
