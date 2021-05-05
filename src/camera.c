#include "camera.h"

#include <GL/glut.h>

#include <math.h>

void init_camera(Camera* camera)
{
    camera->position.x = 0.0;
    camera->position.y = 0.0;
    camera->position.z = 20.0;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    is_guide_visible = FALSE;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    if(camera->position.x<=100 && camera->position.x>=-100){
    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    }
    else if(camera->position.x>=100){
        if((cos(angle) * camera->speed.y * time)<=0){
            camera->position.x += cos(angle) * camera->speed.y * time;
        }
        if((cos(side_angle) * camera->speed.x * time)<=0){
            camera->position.x += cos(side_angle) * camera->speed.x * time;
        }
    }
    else if(camera->position.x<=-100){
        if((cos(angle) * camera->speed.y * time)>=0){
            camera->position.x += cos(angle) * camera->speed.y * time;
        }
        if((cos(side_angle) * camera->speed.x * time)>=0){
            camera->position.x += cos(side_angle) * camera->speed.x * time;
        }
    }
    
    if(camera->position.y<=100 && camera->position.y>=-100){
    camera->position.y += sin(side_angle) * camera->speed.x * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    }
    else if(camera->position.y>=100){
        if((sin(side_angle) * camera->speed.x * time)<=0){
            camera->position.y += sin(side_angle) * camera->speed.x * time;
        }
        if((sin(angle) * camera->speed.y * time)<=0){
            camera->position.y += sin(angle) * camera->speed.y * time;
        }
    }
    else if(camera->position.y<=-100){
        if((sin(side_angle) * camera->speed.x * time)>=0){
            camera->position.y += sin(side_angle) * camera->speed.x * time;
        }
        if((sin(angle) * camera->speed.y * time)>=0){
            camera->position.y += sin(angle) * camera->speed.y * time;
        }
    }

    if(camera->position.z<=100 && camera->position.z>=-100){
    camera->position.z += camera->speed.z * time;
    }
    else if(camera->position.z>=100){
        if((camera->speed.z * time)<=0){
            camera->position.z += camera->speed.z * time;
        }
    }
    else if(camera->position.z<=-100){
        if((camera->speed.z * time)>=0){
            camera->position.z += camera->speed.z * time;
        }
    }
}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void set_camera_up_speed(Camera* camera, double speed)
{
    camera->speed.z = speed;
}

void show_guide(int texture, int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
    
	glTexCoord2f(1, 0);
	glVertex3f(WINDOW_WIDTH, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3f(WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	glTexCoord2f(0, 1);
	glVertex3f(0, WINDOW_HEIGHT, 0);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

