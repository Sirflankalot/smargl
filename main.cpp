#define GLEW_STATIC
#include <GL/glew.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

#include "shaderProgram.h"
#include "Triangle.h"

//Vertices for the triangle we're about to draw
const GLfloat vertices[] = {0.0f, 0.5f, .5f, -.5f, -.5f, -.5f};

int main() {

    //Initialise SDL window and context
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_Window* window = SDL_CreateWindow("triangle", 50, 50, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    //Initialse GLEW
    glewExperimental = GL_TRUE;
    glewInit(); glGetError(); // Calling glewInit causes a useless error 1280

    shaderUtils::shader vertexShader(GL_VERTEX_SHADER, "../../res/basic.vx");
    shaderUtils::shader fragmentShader(GL_FRAGMENT_SHADER, "../../res/basic.fx");

    shaderUtils::shaderProgram prog({vertexShader, fragmentShader});

    prog.activate();

    prog.uniform_list["a"]->set1f(1.0f);

    Triangle t = Triangle();
    t.initStaticVars();

    //Event loop
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            bool escape_pressed = event.type == SDL_KEYUP && (event.key.keysym.sym == SDLK_ESCAPE);
            if (event.type == SDL_QUIT || escape_pressed) break;
        }
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        t.draw();

        SDL_GL_SwapWindow(window);
    }

    //Cleanup code
/*
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
*/
    SDL_GL_DeleteContext(context);
    SDL_Quit();

    return 0;
}