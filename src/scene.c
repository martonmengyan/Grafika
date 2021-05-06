#include "scene.h"
#include "math.h"
#include <GL/glut.h>
#include "planets.h"
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    mercury.angle = 24.1;
    venus.angle = 220.3;
    earth.angle = 70;
    mars.angle = 331.2;
    jupiter.angle = 188.4;
    saturn.angle = 32.2;
    uranus.angle = 254.2;
    neptune.angle = 91.2;

    mercury.r = 7.3;
    venus.r = 13.5;
    earth.r = 18.9;
    moon.r = 1.4;
    mars.r = 27.5;
    jupiter.r = 45;
    saturn.r = 85.3;
    uranus.r = 100.8;
    neptune.r = 121.2;

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

    sun.anglechange = 0;
    mercury.anglechange = 0.052;
    venus.anglechange = 0.046;
    earth.anglechange = 0.06;
    moon.anglechange = 0.08;
    mars.anglechange = 0.04;
    jupiter.anglechange = 0.1;
    saturn.anglechange = 0.04;
    uranus.anglechange = 0.025;
    neptune.anglechange = 0.03;

    scene->value=10;
    
    load_model(&(scene->sphere), "sphere.obj");
    load_model(&(scene->cube), "cube.obj");
    scene->neptun_texture_id = load_texture("neptune.png"); 
    scene->sun_texture_id = load_texture("sun.png");
    scene->venus_texture_id = load_texture("venus.png");
    scene->earth_texture_id = load_texture("earth.png");
    scene->moon_texture_id = load_texture("moon.png");
    scene->mars_texture_id = load_texture("mars.png");
    scene->jupiter_texture_id = load_texture("jupiter.png");
    scene->block_texture_id = load_texture("stars.png");
    scene->saturn_texture_id = load_texture("saturn.png");
    scene->uranus_texture_id = load_texture("uranus.png");
    scene->neptune_texture_id = load_texture("neptune.png");
    scene->help_texture_id = load_texture("help.png");

    glBindTexture(GL_TEXTURE_2D, scene->neptun_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->sun_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->venus_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->earth_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->moon_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->mars_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->jupiter_texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->block_texture_id);

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

void draw_scene(const Scene* scene)
{
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

    glBindTexture(GL_TEXTURE_2D, scene->block_texture_id);

    set_material(&(scene->stars_material));

    glPushMatrix();
    glScalef(1000,1000,1000);
    draw_model(&(scene->cube));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->sun_texture_id);

    set_material(&(scene->sun_material));

    glPushMatrix();
    glRotatef(sun.rotation,1,0,0);
    glScalef(sun.scale,sun.scale,sun.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->mercury_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(mercury.r*mercury.x,mercury.r*mercury.y,0);
    glRotatef(mercury.rotation,1,0,0);
    glScalef(mercury.scale,mercury.scale,mercury.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, scene->venus_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(venus.r*venus.x,venus.r*venus.y,0);
    glRotatef(venus.rotation,1,0,0);
    glScalef(venus.scale,venus.scale,venus.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->earth_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(earth.r*earth.x,earth.r*earth.y,0);
    glRotatef(earth.rotation,1,0,0);
    glScalef(earth.scale,earth.scale,earth.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->moon_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(earth.r*earth.x+moon.r*moon.x,earth.r*earth.y+moon.r*moon.y,0);
    glRotatef(moon.rotation,1,0,0);
    glScalef(moon.scale,moon.scale,moon.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->mars_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(mars.r*mars.x,mars.r*mars.y,0);
    glRotatef(mars.rotation,1,0,0);
    glScalef(mars.scale,mars.scale,mars.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->jupiter_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(jupiter.r*jupiter.x,jupiter.r*jupiter.y,0);
    glRotatef(jupiter.rotation,1,0,0);
    glScalef(jupiter.scale,jupiter.scale,jupiter.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();    

    glBindTexture(GL_TEXTURE_2D, scene->saturn_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(saturn.r*saturn.x,saturn.r*saturn.y,0);
    glRotatef(saturn.rotation,1,0,0);
    glScalef(saturn.scale,saturn.scale,saturn.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->uranus_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(uranus.r*uranus.x,uranus.r*uranus.y,0);
    glRotatef(uranus.rotation,1,0,0);
    glScalef(uranus.scale,uranus.scale,uranus.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->neptune_texture_id);

    set_material(&(scene->planets_material));

    glPushMatrix();
    glTranslatef(neptune.r*neptune.x,neptune.r*neptune.y,0);
    glRotatef(neptune.rotation,1,0,0);
    glScalef(neptune.scale,neptune.scale,neptune.scale);
    draw_model(&(scene->sphere));
    glPopMatrix();
    
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
