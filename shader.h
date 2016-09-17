#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include <fstream>
#include <cassert>

#ifndef ISOMETRICENGINE_SHADER_H
#define ISOMETRICENGINE_SHADER_H

namespace shaderUtils {

    class shader {

    public:
        shader();
        shader(const GLenum& type, const std::string& shaderpath);
        ~shader();

        shader(const shader&) = delete;
		shader(shader&& s) noexcept :
		    shaderRef(s.shaderRef),
		    shaderType(s.shaderType),
		    source_string(std::move(s.source_string)) {
			s.shaderRef = 0;
		};
		shader& operator=(const shader&) = delete;
		shader& operator=(shader&& s) noexcept  {
			shaderRef = s.shaderRef;
			shaderType = s.shaderType;
			source_string = std::move(s.source_string);
			s.shaderRef = 0;

			return *this;
		}

        GLuint shaderRef;
        GLenum shaderType;

        std::string source_string;
    };
}

#endif // ISOMETRICENGINE_SHADER_H