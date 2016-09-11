//
// Created by anish on 9/10/16.
//

#include "uniform.h"

shaderUtils::uniform::uniform(const shaderProgram & parentProgram, std::string & uniName) {
    address = glGetUniformLocation(parentProgram.programRef, uniName.c_str());
}

shaderUtils::uniform::~uniform() {
    // TODO Make sure that there's no specific uniform cleanup function, if so delete this method
}

void shaderUtils::uniform1f::set1f(GLfloat & v0) {
    glUniform1f(address, v0);
}

void shaderUtils::uniform2f::set2f(GLfloat & v0, GLfloat & v1) {
    glUniform2f(address, v0, v1);
}

void shaderUtils::uniform3f::set3f(GLfloat & v0, GLfloat & v1, GLfloat & v2) {
    glUniform3f(address, v0, v1, v2);
}

void shaderUtils::uniform4f::set4f(GLfloat & v0, GLfloat & v1, GLfloat & v2, GLfloat & v3) {
    glUniform4f(address, v0, v1, v2, v3);
}