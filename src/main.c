#include "callbacks.h"
#include "init.h"
#include "texture.h"
#include <GL/glut.h>

#include <stdio.h>

/**
 * Set the callbacks for GLUT.
 */
void set_callbacks()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);
    glutSpecialFunc(specialFunc);
}

/**
 * Main function
 */
int main(int argc, char* argv[])
{
    int window;

    glutInit(&argc, argv);

    glutInitWindowSize(900, 600);     
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    window = glutCreateWindow("Bolygok");
    glutSetWindow(window);

    init_opengl();
    init_scene(&scene);
    init_textures(&world);
    init_camera(&camera);
    set_callbacks();

    glutMainLoop();

    return 0;
}
