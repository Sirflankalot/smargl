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

    virtual shaderUtils::shaderProgram getShaderProgram() = 0;
    virtual GLint getVAO() = 0;
    virtual void getData() = 0;
    virtual void getVBO() = 0;
    virtual void getEBO() = 0;

};


#endif //SMARGL_DRAWABLE_H
