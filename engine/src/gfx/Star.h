#pragma once

#include "shapes/Sphere.h"
#include "shapes/Point.h"
//#include "../util/Time.h"
#include <GL/freeglut.h>

#define GLX_MW 0
#define GLX_AND 1

#define GLX_DISK 0
#define GLX_BULGE 1
#define GLX_HALO 2

class Star
{
private:

    int galaxyType;
    int starType;

    float const width = 10.0f;

    float speed = 0.5f;
    int oldTimeSinceStart = 0;

    Sphere* sphere;
    Point* point;
public:

    float mass;
    float x, y, z;
    float vx, vy, vz;

    Star();

    Star(float mass, float x, float y, float z,
        float vx, float vy, float vz);

    Star(float mass, float x, float y, float z,
            float vx, float vy, float vz, GLuint Texture, GLuint TextureID);

    void setGalaxyType(int galaxyType);
    void setStarType(int starType);

    void Update(float ax, float ay, float az);

    Sphere* GetSphere();
    
    Point* GetPoint();
};

