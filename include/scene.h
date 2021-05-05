#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "planets.h"
#include <obj/model.h>

typedef struct Scene
{
    Model sphere;
    Model cube;
    Material planets_material;
    Material sun_material;
    Material orbit_material;
    Material stars_material;
    GLuint sun_texture_id;
    GLuint block_texture_id;
    GLuint neptun_texture_id;
    GLuint mercury_texture_id;
    GLuint venus_texture_id;
    GLuint earth_texture_id;
    GLuint mars_texture_id;
    GLuint moon_texture_id;
    GLuint jupiter_texture_id;
    GLuint saturn_texture_id;
    GLuint uranus_texture_id;
    GLuint neptune_texture_id;
    GLuint help_texture_id;
    int value;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Light +/-
 */
void update_light_up(Scene* scene);
void update_light_down(Scene* scene);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the orbit of the planets.
 */
void draw_orbit(double x, double y, double r);

#endif /* SCENE_H */
