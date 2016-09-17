//
// Created by anish on 9/9/16.
//

#include "shaderProgram.h"

#include <iostream>
#include <memory>

//std::regex shaderUtils::shaderProgram::uniformFinder = std::regex("uniform (.+?) (.+?);\\s*\\/*\\s*([a-z]*)");
std::regex shaderUtils::shaderProgram::uniformFinder =
        std::regex("uniform (.+) (.+);[\\r\\t\\f ]*\\/*[\\r\\t\\f ]*(.*)\\n");

shaderUtils::shaderProgram::shaderProgram(std::initializer_list<shader> list) {

    programRef = glCreateProgram();

    // NEVER DO THIS ANYWHERE ELSE. INITALIZER_LISTS
    // POINT TO DATA THAT MIGHT BE REALLY READ ONLY.
    // I KNOW IN THIS CASE IT ISN'T, BUT THIS IS
    // VERY SKETCHY CODE (especially the const cast)
    shader_list = std::vector<shader>();
    shader_list.reserve(list.size());

    for (const shader& s : list) {
        shader_list.emplace_back(std::move(const_cast<shader&>(s)));
    }
    // </sketchy>

    assert(shader_list.size() == 2);

    for (auto&& s : shader_list) {
        assert(glIsShader(s.shaderRef));
        glAttachShader(programRef, s.shaderRef);
        std::cerr << "A loopy\n";
    }

    GLint shadercount = 0;
    glGetProgramiv(this->programRef, GL_ATTACHED_SHADERS, &shadercount);
    std::cerr << shadercount << "\n";
    assert(shadercount == 2);

    glLinkProgram(programRef);

    GLint success = GL_TRUE;
    glGetProgramiv(this->programRef, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logsize;
        glGetProgramiv(this->programRef, GL_INFO_LOG_LENGTH, &logsize);
        std::unique_ptr<GLchar> infoLog(new GLchar[logsize]);
        glGetProgramInfoLog(this->programRef, logsize, NULL, infoLog.get());
        std::cerr << "Shader program linking failed:\n" << infoLog.get() << '\n';
        // throw std::runtime_error("Shader program linking failed.");
    }

    find_uniforms();
}

shaderUtils::shaderProgram::shaderProgram(std::initializer_list<std::string> list) {
    // TODO Implement
}

shaderUtils::shaderProgram::~shaderProgram() {
    glDeleteProgram(programRef);
}

void shaderUtils::shaderProgram::activate() {
    glUseProgram(programRef);
}

void shaderUtils::shaderProgram::find_uniforms() {

    std::sregex_iterator matches_begin, matches_end;
    std::string source_suffix;

    for (shader& s : shader_list) {

        matches_begin =
                std::sregex_iterator(s.source_string.begin(), s.source_string.end(), uniformFinder);
        matches_end = std::sregex_iterator();

        std::smatch current_match;

        source_suffix = s.source_string;

        while (std::regex_search(source_suffix, current_match, uniformFinder)) {

            uniform_list[current_match[2]] = shaderUtils::make_uniform(programRef, current_match[2],
                                                current_match[1].str() + current_match[3].str());

            source_suffix = current_match.suffix();
        }
    }
}

shaderUtils::shaderProgram::shaderProgram() {

}
