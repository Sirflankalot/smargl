//
// Created by anish on 9/12/16.
//

#ifndef SMARGL_TRIANGLE_H
#define SMARGL_TRIANGLE_H

#include "Drawable.h"

#include "memory"

class Triangle : Drawable {
public:
    Triangle();
    ~Triangle();

    static bool hasInitialized;

    static shaderUtils::shader v, f;
    static shaderUtils::shaderProgram p;

    static GLuint vao;
    static GLuint vbo;
    static GLuint ebo;

    void draw();
    GLuint elements[3] = {0, 1, 2};

    shaderUtils::shaderProgram getShaderProgram();
    GLint getVAO();
    void getData();
    void getVBO();
    void getEBO();

    void initStaticVars();
};

#endif //SMARGL_TRIANGLE_H
