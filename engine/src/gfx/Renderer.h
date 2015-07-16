#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// OpenGL includes
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../../include/glm/glm/glm.hpp"
#include "../../include/glm/glm/gtc/matrix_transform.hpp"

#include "shapes/Sphere.h"
#include "shapes/Cube.h"
#include "shapes/Triangle.h"
#include "util/ShaderLoader.h"
#include "Camera.h"
#include "Star.h"
#include "../util/GalaxyLoader.h"
#include "util/BMPLoader.h"

//#include "../cuda/GalaxyCollision.cuh"

int GFXInit(int argc, char** argv);

int initWindow();

int initEvents();

int initProgram();

int initSampleObjects();
