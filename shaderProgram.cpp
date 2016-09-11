//
// Created by anish on 9/9/16.
//

#include "shaderProgram.h"

std::regex shaderUtils::shaderProgram::uniformFinder = std::regex("uniform (.+?) (.+?);\\s*//\\s*([a-z]+)");

shaderUtils::shaderProgram::shaderProgram(std::initializer_list<shader> list) {

    shader_list = std::vector<shader>(list);

    for (shader s : shader_list) {
        glAttachShader(programRef, s.shaderRef);
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

    for (shader s : shader_list) {

        matches_begin =
                std::sregex_iterator(s.source_string.begin(), s.source_string.end(), uniformFinder);
        matches_end = std::sregex_iterator();

        std::smatch current_match;

        source_suffix = s.source_string;

        while (std::regex_search(source_suffix, current_match, uniformFinder)) {
            uniform_list[current_match[2]] = shaderUtils::make_uniform(programRef, current_match[2],
                                                current_match[1].str() + current_match[3].str());
            std::cout << current_match[2] << current_match[1] << current_match[3] << std::endl;
            source_suffix = current_match.suffix();
        }
    }
}
