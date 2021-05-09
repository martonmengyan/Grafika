#include "planet.h"
#include "math.h"

void update_planet(Planets* planet)
{
    planet->x = cos(degree_to_radian(planet->angle));
    planet->y = sin(degree_to_radian(planet->angle));
    if(planet->angle>=360){
        planet->angle-=360;
    }
    planet->angle += planet->anglechange;
}

void update_rotation(Planets* planet, double time, int value)
{
    planet->rotation += value * time;
}

