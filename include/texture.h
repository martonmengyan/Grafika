#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

typedef GLubyte Pixel[3];

typedef struct {
    GLuint sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto, moon, stars;
}Planet_name;

typedef struct {
    Planet_name planet_name;
    GLuint help;
}World;

World world;

/**
 * Load texture from file and returns with the texture name.
 */
GLuint load_texture(char* filename);

void init_textures(World* scene);

#endif /* TEXTURE_H */

