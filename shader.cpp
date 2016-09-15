#include "shader.h"

shaderUtils::shader::shader(const GLenum &type, const std::string &shaderpath) {

    shaderType = type;

    // Create the shader

    // Load contents of file into source string
    std::ifstream in(shaderpath);
    source_string = std::string((std::istreambuf_iterator<GLchar>(in)), std::istreambuf_iterator<GLchar>());

    // Create a shader, load in the char array, and compile
    const GLchar* shader_source = source_string.c_str();
    shaderRef = glCreateShader(type);
    glShaderSource(shaderRef, 1, &shader_source, NULL);
    glCompileShader(shaderRef);

    // Check to see that compilation was successful
    GLint compileStatus;
    glGetShaderiv(shaderRef, GL_COMPILE_STATUS, &compileStatus);
    assert(compileStatus == GL_TRUE);
}

shaderUtils::shader::~shader() {
    glDeleteShader(shaderRef);
}

shaderUtils::shader::shader() {

}
