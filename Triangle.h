//
// Created by anish on 9/12/16.
//

#ifndef SMARGL_TRIANGLE_H
#define SMARGL_TRIANGLE_H

#include "Drawable.h"

class Triangle : Drawable {
public:
    Triangle();

    ~Triangle();

    static shaderUtils::shader v = shaderUtils::shader(GL_VERTEX_SHADER, "../../res/basic.vx");

    shaderUtils::shaderProgram getShaderProgram();
    GLint getVAO();
    void getData();
    void getVBO();
    void getEBO();

};

#endif //SMARGL_TRIANGLE_H
