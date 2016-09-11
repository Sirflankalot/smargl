//
// Created by anish on 9/10/16.
//

#ifndef ISOMETRICENGINE_UNIFORM_H
#define ISOMETRICENGINE_UNIFORM_H

#include "shaderProgram.h"

#include <stdexcept>

namespace shaderUtils {

    // Factory method to make uniforms
    // TODO Implement (also, the return type shouldn't be void)
    void make_uniform(const shaderProgram &, std::string, std::string) {};

    class uniform {
    public:
        uniform(const shaderProgram &, std::string &);

        ~uniform();

        GLint address;

        virtual void set1f(GLfloat &) {};

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

        virtual void setMatrix2fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix2x3fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3x2fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix2x4fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4x2fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix3x4fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        virtual void setMatrix4x3fv(GLsizei &, GLboolean &, const GLfloat *) { err(); };

        void err() {
            // TODO Should this be inline?
            throw std::invalid_argument("Wrong set method");
        }
    };

    // And now onto the classses...

    class uniform1f : public uniform {
    public:
        uniform1f(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1f(GLfloat &);
    };
    class uniform2f : uniform {
        uniform2f(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2f(GLfloat &, GLfloat &);
    };
    class uniform3f : uniform {
        uniform3f(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3f(GLfloat &, GLfloat &, GLfloat &);
    };
    class uniform4f : uniform {
        uniform4f(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4f(GLfloat &, GLfloat &, GLfloat &, GLfloat &);
    };

    class uniform1i : uniform {
        uniform1i(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1i(GLint &);
    };
    class uniform2i : uniform {
        uniform2i(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2i(GLint &, GLint &);
    };
    class uniform3i : uniform {
        uniform3i(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3i(GLint &, GLint &, GLint &);
    };
    class uniform4i : uniform {
        uniform4i(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4i(GLint &, GLint &, GLint &, GLint &);
    };

    class uniform1ui : uniform {
        uniform1ui(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1ui(GLuint &);
    };
    class uniform2ui : uniform {
        uniform2ui(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2ui(GLuint &, GLuint &);
    };
    class uniform3ui : uniform {
        uniform3ui(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3ui(GLuint &, GLuint &, GLuint &);
    };
    class uniform4ui : uniform {
        uniform4ui(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4ui(GLuint &, GLuint &, GLuint &, GLuint &);
    };

    class uniform1fv : uniform {
        uniform1fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1fv(GLsizei &, const GLfloat *);
    };
    class uniform2fv : uniform {
        uniform2fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2fv(GLsizei &, const GLfloat *);
    };
    class uniform3fv : uniform {
        uniform3fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3fv(GLsizei &, const GLfloat *);
    };
    class uniform4fv : uniform {
        uniform4fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4iv(GLsizei &, const GLint *);
    };

    class uniform1iv : uniform {
        uniform1iv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1iv(GLsizei &, const GLint *);
    };
    class uniform2iv : uniform {
        uniform2iv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2iv(GLsizei &, const GLint *);
    };
    class uniform3iv : uniform {
        uniform3iv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3iv(GLsizei &, const GLint *);
    };
    class uniform4iv : uniform {
        uniform4iv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4iv(GLsizei &, const GLint *);
    };

    class uniform1uiv : uniform {
        uniform1uiv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set1uiv(GLsizei &, const GLuint *);
    };
    class uniform2uiv : uniform {
        uniform2uiv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set2uiv(GLsizei &, const GLuint *);
    };
    class uniform3uiv : uniform {
        uniform3uiv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set3uiv(GLsizei &, const GLuint *);
    };
    class uniform4uiv : uniform {
        uniform4uiv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void set4uiv(GLsizei &, const GLuint *);
    };

    class uniformMatrix2fv : uniform {
        uniformMatrix2fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3fv : uniform {
        uniformMatrix3fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4fv : uniform {
        uniformMatrix4fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix2x3fv : uniform {
        uniformMatrix2x3fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2x3fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3x2fv : uniform {
        uniformMatrix3x2fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3x2fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix2x4fv : uniform {
        uniformMatrix2x4fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix2x4fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4x2fv : uniform {
        uniformMatrix4x2fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4x2fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix3x4fv : uniform {
        uniformMatrix3x4fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix3x4fv(GLsizei &, GLboolean &, const GLfloat *);
    };
    class uniformMatrix4x3fv : uniform {
        uniformMatrix4x3fv(const shaderProgram & prog, std::string & name)
                : uniform (prog, name) {};
        void setMatrix4x3fv(GLsizei &, GLboolean &, const GLfloat *);
    };
}

#endif //ISOMETRICENGINE_UNIFORM_H
