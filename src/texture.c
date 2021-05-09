#include "texture.h"

#include <SOIL/SOIL.h>

GLuint load_texture(char* filename)
{
    GLuint texture_name;
    int width;
    int height;
    Pixel* image = (Pixel*)SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);

    glGenTextures(1, &texture_name);

    glBindTexture(GL_TEXTURE_2D, texture_name);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (Pixel*)image);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    /*
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    */

    return texture_name;
}

void init_textures(World* scene)
{
    scene->planet_name.mercury = load_texture("textures//mercury.png"); 
    scene->planet_name.sun = load_texture("textures//sun.png");
    scene->planet_name.venus = load_texture("textures//venus.png");
    scene->planet_name.earth = load_texture("textures//earth.png");
    scene->planet_name.moon = load_texture("textures//moon.png");
    scene->planet_name.mars = load_texture("textures//mars.png");
    scene->planet_name.jupiter = load_texture("textures//jupiter.png");
    scene->planet_name.saturn = load_texture("textures//saturn.png");
    scene->planet_name.uranus = load_texture("textures//uranus.png");
    scene->planet_name.neptune = load_texture("textures//neptune.png");
    scene->help = load_texture("textures//help.png");
    scene->planet_name.stars = load_texture("textures//stars.png");
}

