#ifndef PLANET_H
#define PLANET_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Planets {
    
        double x;
        double y;
        double angle;
        double anglechange;
        double rotation;
        double r;
        double scale;
} Planets;

Planets sun;
Planets mercury;
Planets venus;
Planets earth;
Planets mars;
Planets jupiter;
Planets saturn;
Planets uranus;
Planets neptune;
Planets pluto;
Planets moon;

/**
 * Update the coordinates of the planets.
 */
void update_planet(Planets* mercury);

/**
 * Update the rotation value of each planet.
 */
void update_rotation(Planets* planet, double time, int value);

#endif /* PLANET_H */