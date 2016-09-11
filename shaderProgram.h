//
// Created by anish on 9/9/16.
//

#ifndef ISOMETRICENGINE_SHADERPROGRAM_H
#define ISOMETRICENGINE_SHADERPROGRAM_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include "shader.h"
#include <unordered_map>
#include <regex>

namespace shaderUtils {
    class shaderProgram {
    public:
        shaderProgram(std::initializer_list <std::string> list);
        shaderProgram(std::initializer_list <shader> list);
        ~shaderProgram();

        void activate();
        void find_uniforms();

        const GLuint programRef = glCreateProgram();

        std::vector <shader> shader_list;
        std::unordered_map <std::string, GLint> uniform_list;

        static std::regex uniformFinder;

        void set_uniform1f(std::string, GLfloat);
        void set_uniform2f(std::string, GLfloat);
    };
}

#endif //ISOMETRICENGINE_SHADERPROGRAM_H
