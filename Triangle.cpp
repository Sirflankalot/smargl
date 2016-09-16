//
// Created by anish on 9/12/16.
//

#include "Triangle.h"

GLuint Triangle::vao;
GLuint Triangle::vbo;
GLuint Triangle::ebo;

shaderUtils::shader Triangle::v, Triangle::f;
shaderUtils::shaderProgram Triangle::p;

void Triangle::initStaticVars() {

    v = shaderUtils::shader(GL_VERTEX_SHADER, "../../res/basic.vx");
    f = shaderUtils::shader(GL_FRAGMENT_SHADER, "../../res/basic.fx");
    Triangle::p = shaderUtils::shaderProgram({v, f});

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

}

GLint Triangle::getVAO() {
    return 0;
}

void Triangle::getData() {

}

void Triangle::getVBO() {

}

void Triangle::getEBO() {

}
