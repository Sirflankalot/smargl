//
// Created by anish on 9/10/16.
//

#ifndef ISOMETRICENGINE_UNIFORM_H
#define ISOMETRICENGINE_UNIFORM_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include <memory>
#include <stdexcept>
#include <iostream>

namespace shaderUtils {

    class uniform {
    public:
        uniform(const GLuint &, std::string &);
        uniform();

        ~uniform();

        GLint address;

        virtual void set1f(GLfloat) {};

        virtual void set2f(GLfloat &, GLfloat &) { err(); };

        virtual void set3f(GLfloat &, GLfloat &, GLfloat &) { err(); };

        virtual void set4f(GLfloat &, GLfloat &, GLfloat &, GLfloat &) { err(); };

        virtual void set1i(GLint &) { err(); };

        virtual void set2i(GLint &, GLint &) { err(); };

        virtual void set3i(GLint &, GLint &, GLint &) { err(); };

        virtual void set4i(GLint &, GLint &, GLint &, GLint &) { err(); };

        virtual void set1ui(GLuint &) { err(); };

        virtual void set2ui(GLuint &, GLuint &) { err(); };

        virtual void set3ui(GLuint &, GLuint &, GLuint &) { err(); };

        virtual void set4ui(GLuint &, GLuint &, GLuint &, GLuint &) { err(); };

        // TODO What do these functions even do?

        virtual void set1fv(GLsizei &, const GLfloat *) { err(); };

        virtual void set2fv(GLsizei &, const GLfloat *) { err(); };

        virtual void set3fv(GLsizei &, const GLfloat *) { err(); };

        virtual void set4fv(GLsizei &, const GLfloat *) { err(); };

        virtual void set1iv(GLsizei &, const GLint *) { err(); };

        virtual void set2iv(GLsizei &, const GLint *) { err(); };

        virtual void set3iv(GLsizei &, const GLint *) { err(); };

        virtual void set4iv(GLsizei &, const GLint *) { err(); };

        virtual void set1uiv(GLsizei &, const GLuint *) { err(); };

        virtual void set2uiv(GLsizei &, const GLuint *) { err(); };

        virtual void set3uiv(GLsizei &, const GLuint *) { err(); };

        virtual void set4uiv(GLsizei &, const GLuint *) { err(); };

        virtual void setMatrix2(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix2x3(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3x2(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix2x4(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4x2(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3x4(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4x3(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        void err() {
            // TODO Should this be inline?
            throw std::invalid_argument("Wrong set method");
        }
    };

    std::unique_ptr<uniform> make_uniform(const GLuint &, std::string, std::string);

    // And now onto the classses...

    class uniform1f : public uniform {
    public:
        uniform1f(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1f(GLfloat);
    };
    class uniform2f : public uniform {
    public:
        uniform2f(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2f(GLfloat &, GLfloat &);
    };
    class uniform3f : public uniform {
    public:
        uniform3f(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3f(GLfloat &, GLfloat &, GLfloat &);
    };
    class uniform4f : public uniform {
    public:
        uniform4f(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4f(GLfloat &, GLfloat &, GLfloat &, GLfloat &);
    };

    class uniform1i : public uniform {
    public:
        uniform1i(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1i(GLint &);
    };
    class uniform2i : public uniform {
    public:
        uniform2i(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2i(GLint &, GLint &);
    };
    class uniform3i : public uniform {
    public:
        uniform3i(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3i(GLint &, GLint &, GLint &);
    };
    class uniform4i : public uniform {
    public:
        uniform4i(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4i(GLint &, GLint &, GLint &, GLint &);
    };

    class uniform1ui : public uniform {
    public:
        uniform1ui(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1ui(GLuint &);
    };
    class uniform2ui : public uniform {
    public:
        uniform2ui(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2ui(GLuint &, GLuint &);
    };
    class uniform3ui : public uniform {
    public:
        uniform3ui(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3ui(GLuint &, GLuint &, GLuint &);
    };
    class uniform4ui : public uniform {
    public:
        uniform4ui(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4ui(GLuint &, GLuint &, GLuint &, GLuint &);
    };

    class uniform1fv : public uniform {
    public:
        uniform1fv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1fv(GLsizei &, const GLfloat *);
    };
    class uniform2fv : public uniform {
    public:
        uniform2fv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2fv(GLsizei &, const GLfloat *);
    };
    class uniform3fv : public uniform {
    public:
        uniform3fv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3fv(GLsizei &, const GLfloat *);
    };
    class uniform4fv : public uniform {
    public:
        uniform4fv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4fv(GLsizei &, const GLfloat *);
    };

    class uniform1iv : public uniform {
    public:
        uniform1iv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1iv(GLsizei &, const GLint *);
    };
    class uniform2iv : public uniform {
    public:
        uniform2iv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2iv(GLsizei &, const GLint *);
    };
    class uniform3iv : public uniform {
    public:
        uniform3iv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3iv(GLsizei &, const GLint *);
    };
    class uniform4iv : public uniform {
    public:
        uniform4iv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4iv(GLsizei &, const GLint *);
    };

    class uniform1uiv : public uniform {
    public:
        uniform1uiv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set1uiv(GLsizei &, const GLuint *);
    };
    class uniform2uiv : public uniform {
    public:
        uniform2uiv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set2uiv(GLsizei &, const GLuint *);
    };
    class uniform3uiv : public uniform {
    public:
        uniform3uiv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set3uiv(GLsizei &, const GLuint *);
    };
    class uniform4uiv : public uniform {
    public:
        uniform4uiv(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void set4uiv(GLsizei &, const GLuint *);
    };

    class uniformMatrix2 : public uniform {
    public:
        uniformMatrix2(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3 : public uniform {
    public:
        uniformMatrix3(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4 : public uniform {
    public:
        uniformMatrix4(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix2x3 : public uniform {
    public:
        uniformMatrix2x3(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2x3(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3x2 : public uniform {
    public:
        uniformMatrix3x2(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3x2(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix2x4: public uniform {
    public:
        uniformMatrix2x4(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2x4(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4x2 : public uniform {
    public:
        uniformMatrix4x2(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4x2(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3x4 : public uniform {
    public:
        uniformMatrix3x4(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3x4(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4x3 : public uniform {
    public:
        uniformMatrix4x3(const GLuint & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4x3(GLsizei &, GLboolean &, const GLfloat *);
    };
}

#endif //ISOMETRICENGINE_UNIFORM_H
