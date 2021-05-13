#include "scene.h"
#include "math.h"
#include <GL/glut.h>
#include "planet.h"
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    /**
    * Set the starting angle of the planets
    */
    mercury.angle = 24.1;
    venus.angle = 220.3;
    earth.angle = 70;
    mars.angle = 331.2;
    jupiter.angle = 188.4;
    saturn.angle = 32.2;
    uranus.angle = 254.2;
    neptune.angle = 91.2;

    /**
    * Set the distance from sun of the planets
    */
    mercury.r = 7.3;
    venus.r = 13.5;
    earth.r = 18.9;
    moon.r = 1.4;
    mars.r = 27.5;
    jupiter.r = 45;
    saturn.r = 85.3;
    uranus.r = 100.8;
    neptune.r = 121.2;

    /**
    * Set the size of the planets
    */
    sun.scale = 2.3;
    mercury.scale = 0.48;
    venus.scale = 0.95;
    earth.scale = 1;
    moon.scale = 0.186;
    mars.scale = 0.987;
    jupiter.scale = 3.6;
    saturn.scale = 4.6;
    uranus.scale = 3.9;
    neptune.scale = 3.95;

    /**
    * Set the speed of the planets
    */
    sun.anglechange = 0;
    mercury.anglechange = 0.052;
    venus.anglechange = 0.046;
    earth.anglechange = 0.06;
    moon.anglechange = 0.08;
    mars.anglechange = 0.04;
    jupiter.anglechange = 0.03;
    saturn.anglechange = 0.04;
    uranus.anglechange = 0.025;
    neptune.anglechange = 0.03;

    scene->value=10;
    
    load_model(&(scene->sphere), "obj//sphere.obj");

    /**
    * Planet Material
    */
    scene->planets_material.ambient.red = 0.0;
    scene->planets_material.ambient.green = 0.0;
    scene->planets_material.ambient.blue = 0.0;

    scene->planets_material.diffuse.red = 5.0;
    scene->planets_material.diffuse.green = 5.0;
    scene->planets_material.diffuse.blue = 5.0;

    scene->planets_material.specular.red = 0.0;
    scene->planets_material.specular.green = 0.0;
    scene->planets_material.specular.blue = 0.0;

    scene->planets_material.shininess = 0.0;
    
    /**
    * Sun Material
    */
    scene->sun_material.ambient.red = 5.0;
    scene->sun_material.ambient.green = 5.0;
    scene->sun_material.ambient.blue = 0.0;

    scene->sun_material.diffuse.red = 0.0;
    scene->sun_material.diffuse.green = 0.0;
    scene->sun_material.diffuse.blue = 0.0;

    scene->sun_material.specular.red = 0.0;
    scene->sun_material.specular.green = 0.0;
    scene->sun_material.specular.blue = 0.0;

    scene->sun_material.shininess = 0.0;

    /**
    * Orbit Material
    */
    scene->orbit_material.ambient.red = 2.0;
    scene->orbit_material.ambient.green = 1.0;
    scene->orbit_material.ambient.blue = 0.0;

    scene->orbit_material.diffuse.red = 0.0;
    scene->orbit_material.diffuse.green = 0.0;
    scene->orbit_material.diffuse.blue = 0.0;

    scene->orbit_material.specular.red = 0.0;
    scene->orbit_material.specular.green = 0.0;
    scene->orbit_material.specular.blue = 0.0;

    scene->orbit_material.shininess = 0.0;

    /**
    * Stars Material
    */
    scene->stars_material.ambient.red = 10.0;
    scene->stars_material.ambient.green = 10.0;
    scene->stars_material.ambient.blue = 10.0;

    scene->stars_material.diffuse.red = 0.0;
    scene->stars_material.diffuse.green = 0.0;
    scene->stars_material.diffuse.blue = 0.0;

    scene->stars_material.specular.red = 0.0;
    scene->stars_material.specular.green = 0.0;
    scene->stars_material.specular.blue = 0.0;

    scene->stars_material.shininess = 0.0;
}

void update_light_down(Scene* scene)
{
    if(scene->value>0)
    {
    scene->sun_material.ambient.red -= 0.5;
    scene->sun_material.ambient.green -= 0.5;
    scene->planets_material.diffuse.red -= 0.5;
    scene->planets_material.diffuse.green -= 0.5;
    scene->planets_material.diffuse.blue -= 0.5;
    scene->value=scene->value-1;
    }
}

void update_light_up(Scene* scene)
{
    if(scene->value<10)
    {
    scene->sun_material.ambient.red += 0.5;
    scene->sun_material.ambient.green += 0.5;
    scene->planets_material.diffuse.red += 0.5;
    scene->planets_material.diffuse.green += 0.5;
    scene->planets_material.diffuse.blue += 0.5;
    scene->value=scene->value+1;
    }
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[3];
    float diffuse_material_color[3];
    float specular_material_color[3];

    ambient_material_color[0] = material->ambient.red;
    ambient_material_color[1] = material->ambient.green;
    ambient_material_color[2] = material->ambient.blue;

    diffuse_material_color[0] = material->diffuse.red;
    diffuse_material_color[1] = material->diffuse.green;
    diffuse_material_color[2] = material->diffuse.blue;
    
    specular_material_color[0] = material->specular.red;
    specular_material_color[1] = material->specular.green;
    specular_material_color[2] = material->specular.blue;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene, const World* world)
{
    int i;
    int j;
    GLuint textures[11];
    double rotation[11];
    double scale[11];
    double translatex[11];
    double translatey[11];
    Material material[3];

    textures[0]=world->planet_name.sun;
    textures[1]=world->planet_name.stars;
    textures[2]=world->planet_name.mercury;
    textures[3]=world->planet_name.venus;
    textures[4]=world->planet_name.earth;
    textures[5]=world->planet_name.moon;
    textures[6]=world->planet_name.mars;
    textures[7]=world->planet_name.jupiter;
    textures[8]=world->planet_name.saturn;
    textures[9]=world->planet_name.uranus;
    textures[10]=world->planet_name.neptune;

    rotation[0]=sun.rotation;
    rotation[1]=0;
    rotation[2]=mercury.rotation;
    rotation[3]=venus.rotation;
    rotation[4]=earth.rotation;
    rotation[5]=moon.rotation;
    rotation[6]=mars.rotation;
    rotation[7]=jupiter.rotation;
    rotation[8]=saturn.rotation;
    rotation[9]=uranus.rotation;
    rotation[10]=neptune.rotation;
    
    scale[0]=sun.scale;
    scale[1]=1000;
    scale[2]=mercury.scale;
    scale[3]=venus.scale;
    scale[4]=earth.scale;
    scale[5]=moon.scale;
    scale[6]=mars.scale;
    scale[7]=jupiter.scale;
    scale[8]=saturn.scale;
    scale[9]=uranus.scale;
    scale[10]=neptune.scale;

    translatex[0]=0;
    translatex[1]=0;
    translatex[2]=mercury.r*mercury.x;
    translatex[3]=venus.r*venus.x;
    translatex[4]=earth.r*earth.x;
    translatex[5]=earth.r*earth.x+moon.r*moon.x;
    translatex[6]=mars.r*mars.x;
    translatex[7]=jupiter.r*jupiter.x;
    translatex[8]=saturn.r*saturn.x;
    translatex[9]=uranus.r*uranus.x;
    translatex[10]=neptune.r*neptune.x;

    translatey[0]=0;
    translatey[1]=0;
    translatey[2]=mercury.r*mercury.y;
    translatey[3]=venus.r*venus.y;
    translatey[4]=earth.r*earth.y;
    translatey[5]=earth.r*earth.y+moon.r*moon.y;
    translatey[6]=mars.r*mars.y;
    translatey[7]=jupiter.r*jupiter.y;
    translatey[8]=saturn.r*saturn.y;
    translatey[9]=uranus.r*uranus.y;
    translatey[10]=neptune.r*neptune.y;

    material[0]=scene->sun_material;
    material[1]=scene->stars_material;
    material[2]=scene->planets_material;

    set_material(&(scene->orbit_material));

    draw_orbit(0,0,mercury.r);
    draw_orbit(0,0,venus.r);
    draw_orbit(0,0,earth.r);
    draw_orbit(earth.r*earth.x,earth.r*earth.y,moon.r);
    draw_orbit(0,0,mars.r);
    draw_orbit(0,0,jupiter.r);
    draw_orbit(0,0,saturn.r);
    draw_orbit(0,0,uranus.r);
    draw_orbit(0,0,neptune.r);

    set_lighting();

    for(i=0,j=0;i<11;i++)
    {
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        set_material(&(material[j]));
        glPushMatrix();
        glTranslatef(translatex[i],translatey[i],0);
        glRotatef(rotation[i],1,0,0);
        glScalef(scale[i],scale[i],scale[i]);
        draw_model(&(scene->sphere));
        glPopMatrix();
        if(j<2){
            j++;
        }
    }
}

void draw_orbit(double x, double y, double r)
{
	int i;
	int k = 1000;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= k;i++) { 
			glVertex2f(
			    x + (r * cos(i *  2*M_PI / k)), 
			    y + (r * sin(i * 2*M_PI / k))
			);
		}
	glEnd();
}
