//
// Created by anish on 9/10/16.
//

#include "uniform.h"

std::unique_ptr<shaderUtils::uniform>
    shaderUtils::make_uniform(const GLuint & prog, std::string name, std::string type) {

    // TODO implement single-dimension *v functions (whatever the hell those do...)
    if      (!type.compare("vec2float"))     return std::make_unique<shaderUtils::uniform2f>(prog, name);
    else if (!type.compare("vec3float"))     return std::make_unique<shaderUtils::uniform3f>(prog, name);
    else if (!type.compare("vec4float"))     return std::make_unique<shaderUtils::uniform4f>(prog, name);
    else if (!type.compare("vec2int"))       return std::make_unique<shaderUtils::uniform2i>(prog, name);
    else if (!type.compare("vec3int"))       return std::make_unique<shaderUtils::uniform3i>(prog, name);
    else if (!type.compare("vec4int"))       return std::make_unique<shaderUtils::uniform4i>(prog, name);
    else if (!type.compare("vec2uint"))      return std::make_unique<shaderUtils::uniform2ui>(prog, name);
    else if (!type.compare("vec3uint"))      return std::make_unique<shaderUtils::uniform3ui>(prog, name);
    else if (!type.compare("vec4uint"))      return std::make_unique<shaderUtils::uniform4ui>(prog, name);

    // Implementing single-dimension uniforms...
    else if (!type.compare("float"))         return std::make_unique<shaderUtils::uniform1f>(prog, name);
    else if (!type.compare("int"))           return std::make_unique<shaderUtils::uniform1i>(prog, name);
    else if (!type.compare("uint"))          return std::make_unique<shaderUtils::uniform1ui>(prog, name);

    // Now I dont know if these types are really right...
    else if (!type.compare("vec2vfloat"))    return std::make_unique<shaderUtils::uniform2fv>(prog, name);
    else if (!type.compare("vec3vfloat"))    return std::make_unique<shaderUtils::uniform3fv>(prog, name);
    else if (!type.compare("vec4vfloat"))    return std::make_unique<shaderUtils::uniform4fv>(prog, name);
    else if (!type.compare("vec2vint"))      return std::make_unique<shaderUtils::uniform2iv>(prog, name);
    else if (!type.compare("vec3vint"))      return std::make_unique<shaderUtils::uniform3iv>(prog, name);
    else if (!type.compare("vec4vint"))      return std::make_unique<shaderUtils::uniform4iv>(prog, name);
    else if (!type.compare("vec2vuint"))     return std::make_unique<shaderUtils::uniform2uiv>(prog, name);
    else if (!type.compare("vec3vuint"))     return std::make_unique<shaderUtils::uniform3uiv>(prog, name);
    else if (!type.compare("vec4vuint"))     return std::make_unique<shaderUtils::uniform4uiv>(prog, name);

    // Or if these are right...
    else if (!type.compare("mat2float"))    return std::make_unique<shaderUtils::uniformMatrix2>(prog, name);
    else if (!type.compare("mat3float"))    return std::make_unique<shaderUtils::uniformMatrix3>(prog, name);
    else if (!type.compare("mat4float"))    return std::make_unique<shaderUtils::uniformMatrix4>(prog, name);
    else if (!type.compare("mat2x3float"))  return std::make_unique<shaderUtils::uniformMatrix2x3>(prog, name);
    else if (!type.compare("mat3x2float"))  return std::make_unique<shaderUtils::uniformMatrix3x2>(prog, name);
    else if (!type.compare("mat2x4float"))  return std::make_unique<shaderUtils::uniformMatrix2x4>(prog, name);
    else if (!type.compare("mat4x2float"))  return std::make_unique<shaderUtils::uniformMatrix4x2>(prog, name);
    else if (!type.compare("mat3x4float"))  return std::make_unique<shaderUtils::uniformMatrix3x4>(prog, name);
    else if (!type.compare("mat4x3float"))  return std::make_unique<shaderUtils::uniformMatrix4x3>(prog, name);

    else throw std::invalid_argument("That's not a valid uniform type...");

}

shaderUtils::uniform::uniform(const GLuint & parentProgram, std::string & uniName) {
    address = glGetUniformLocation(parentProgram, uniName.c_str());
}

shaderUtils::uniform::~uniform() {
    // TODO Make sure that there's no specific uniform cleanup function, if so delete this method
}

shaderUtils::uniform::uniform() {
    // This method only exists so that I can create hashmaps mapping to uniform objects
}

void shaderUtils::uniform1f::set1f(GLfloat v0) {
    std::cout << "Was set to " << v0 << std::endl;
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

void shaderUtils::uniform1i::set1i(GLint & v0) {
    glUniform1i(address, v0);
}

void shaderUtils::uniform2i::set2i(GLint & v0, GLint & v1) {
    glUniform2i(address, v0, v1);
}

void shaderUtils::uniform3i::set3i(GLint & v0, GLint & v1, GLint & v2) {
    glUniform3i(address, v0, v1, v2);
}

void shaderUtils::uniform4i::set4i(GLint & v0, GLint & v1, GLint & v2, GLint & v3) {
    glUniform4i(address, v0, v1, v2, v3);
}
void shaderUtils::uniform1ui::set1ui(GLuint & v0) {
    glUniform1ui(address, v0);
}

void shaderUtils::uniform2ui::set2ui(GLuint & v0, GLuint & v1) {
    glUniform2ui(address, v0, v1);
}

void shaderUtils::uniform3ui::set3ui(GLuint & v0, GLuint & v1, GLuint & v2) {
    glUniform3ui(address, v0, v1, v2);
}

void shaderUtils::uniform4ui::set4ui(GLuint & v0, GLuint & v1, GLuint & v2, GLuint & v3) {
    glUniform4ui(address, v0, v1, v2, v3);
}

void shaderUtils::uniform1fv::set1fv(GLsizei & count, const GLfloat * value) {
    glUniform1fv(address, count, value);
}

void shaderUtils::uniform2fv::set2fv(GLsizei & count, const GLfloat * value) {
    glUniform2fv(address, count, value);
}

void shaderUtils::uniform3fv::set3fv(GLsizei & count, const GLfloat * value) {
    glUniform3fv(address, count, value);
}

void shaderUtils::uniform4fv::set4fv(GLsizei & count, const GLfloat * value) {
    glUniform4fv(address, count, value);
}

void shaderUtils::uniform1iv::set1iv(GLsizei & count, const GLint * value) {
    glUniform1iv(address, count, value);
}

void shaderUtils::uniform2iv::set2iv(GLsizei & count, const GLint * value) {
    glUniform2iv(address, count, value);
}

void shaderUtils::uniform3iv::set3iv(GLsizei & count, const GLint * value) {
    glUniform3iv(address, count, value);
}

void shaderUtils::uniform4iv::set4iv(GLsizei & count, const GLint * value) {
    glUniform4iv(address, count, value);
}

void shaderUtils::uniform1uiv::set1uiv(GLsizei & count, const GLuint * value) {
    glUniform1uiv(address, count, value);
}

void shaderUtils::uniform2uiv::set2uiv(GLsizei & count, const GLuint * value) {
    glUniform2uiv(address, count, value);
}

void shaderUtils::uniform3uiv::set3uiv(GLsizei & count, const GLuint * value) {
    glUniform3uiv(address, count, value);
}

void shaderUtils::uniform4uiv::set4uiv(GLsizei & count, const GLuint * value) {
    glUniform4uiv(address, count, value);
}

void shaderUtils::uniformMatrix2::setMatrix2(GLsizei &count, GLboolean &tpose, const GLfloat *value) {
    glUniformMatrix2fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix3::setMatrix3(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix3fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix4::setMatrix4(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix4fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix2x3::setMatrix2x3(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix2x3fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix3x2::setMatrix3x2(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix3x2fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix2x4::setMatrix2x4(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix2x4fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix4x2::setMatrix4x2(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix4x2fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix3x4::setMatrix3x4(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix3x4fv(address, count, tpose, value);
}

void shaderUtils::uniformMatrix4x3::setMatrix4x3(GLsizei & count, GLboolean & tpose, const GLfloat * value) {
    glUniformMatrix4x3fv(address, count, tpose, value);
}