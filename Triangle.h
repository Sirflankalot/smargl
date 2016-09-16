//
// Created by anish on 9/12/16.
//

#ifndef SMARGL_TRIANGLE_H
#define SMARGL_TRIANGLE_H

#include "Drawable.h"

#include "memory"
#include "array"
#include "iostream"

class Triangle : Drawable {
public:
    Triangle();
    ~Triangle();

    static shaderUtils::shader v, f;
    static shaderUtils::shaderProgram p;

    static GLfloat vertices[6];

    static GLuint vao;
    static GLuint vbo;
    static GLuint ebo;
    static GLint posAttrib;

    void draw();
    GLuint elements[3] = {0, 1, 2};

    void initStaticVars();
    void destroyStaticVars();
};

#endif //SMARGL_TRIANGLE_H
