#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include <fstream>
#include <cassert>
#include <list>
#include <iostream>
#include <vector>
#include <regex>

#ifndef ISOMETRICENGINE_SHADERU_H
#define ISOMETRICENGINE_SHADER_H

namespace shaderUtils {

    class shader {

    public:
        shader(const GLenum& type, const std::string& shaderpath);
        ~shader();

        GLuint shaderRef;
        GLenum shaderType;

        std::string source_string;
    };
}

#endif // ISOMETRICENGINE_SHADER_H