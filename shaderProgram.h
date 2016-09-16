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
#include "uniform.h"
#include <unordered_map>
#include <regex>

namespace shaderUtils {
    class shaderProgram {
    public:
        shaderProgram();
        shaderProgram(std::initializer_list <std::string> list);
        shaderProgram(std::initializer_list <shader> list);
        ~shaderProgram();

        shaderProgram(const shaderProgram&) = delete;
        shaderProgram(shaderProgram&&)      = default;
        shaderProgram& operator=(const shaderProgram&) = delete;
        shaderProgram& operator=(shaderProgram&&) = default;

        void activate();
        void find_uniforms();

        GLuint programRef;

        std::vector <shader> shader_list;
        std::vector <std::string> attributes;

        std::unordered_map <std::string, std::unique_ptr<shaderUtils::uniform>> uniform_list;

        static std::regex uniformFinder;
    };
}

#endif //ISOMETRICENGINE_SHADERPROGRAM_H
