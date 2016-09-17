//
// Created by anish on 9/12/16.
//

#include "Triangle.h"

GLuint Triangle::vao;
GLuint Triangle::vbo;
GLuint Triangle::ebo;
GLint Triangle::posAttrib;

shaderUtils::shader Triangle::v, Triangle::f;
shaderUtils::shaderProgram Triangle::p;

GLfloat Triangle::vertices[6] = {0.0f, 0.5f, .5f, -.5f, -.5f, .0f};


void Triangle::initStaticVars() {

    glGenVertexArrays(1, &Triangle::vao);
    glBindVertexArray(Triangle::vao);

    glGenBuffers(1, &Triangle::vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Triangle::vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle::vertices), Triangle::vertices, GL_STATIC_DRAW);

    Triangle::v = shaderUtils::shader(GL_VERTEX_SHADER, "res/basic.vx");
    Triangle::f = shaderUtils::shader(GL_FRAGMENT_SHADER, "res/basic.fx");
    Triangle::p = shaderUtils::shaderProgram({std::move(v), std::move(f)});
    Triangle::p.activate();
    Triangle::p.uniform_list["a"]->set1f(.5f);

    GLint posAttrib = glGetAttribLocation(Triangle::p.programRef, "position");
    glEnableVertexAttribArray(Triangle::posAttrib);
    glVertexAttribPointer(Triangle::posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

Triangle::Triangle() {

}

void Triangle::destroyStaticVars() {
    glDeleteBuffers(1, &Triangle::ebo);
    glDeleteBuffers(1, &Triangle::vbo);
    glDeleteVertexArrays(1, &Triangle::vao);
}

void Triangle::draw() {
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Triangle::~Triangle() {

}
