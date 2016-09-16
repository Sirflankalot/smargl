//
// Created by anish on 9/12/16.
//

#ifndef SMARGL_DRAWABLE_H
#define SMARGL_DRAWABLE_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include "shaderProgram.h"

#include <array>

class Drawable {
public:
    Drawable();
    ~Drawable();

    virtual void draw() = 0;

    // TODO implement textured drawables
    virtual void initStaticVars() = 0;
    virtual void destroyStaticVars() = 0;
};


#endif //SMARGL_DRAWABLE_H
