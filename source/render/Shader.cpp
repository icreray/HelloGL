#include "Shader.hpp"

#include <GL/glew.h>
#include <iostream>

namespace hellogl {

    namespace {
        uint32 compileShader(const char* shaderSource, GLenum shaderType) {
            uint32 shader = glCreateShader(shaderType);
            glShaderSource(shader, 1, &shaderSource, nullptr);
            glCompileShader(shader);

            int32 success;
            char infoLog[512];

            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (not success) {
                glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
                std::cerr << "Error: Shader compilation failed\n    " << infoLog << '\n';
            }

            return shader;
        }

        uint32 linkProgram(uint32 vertexShader, uint32 fragmentShader) {
            uint32 program = glCreateProgram();
            glAttachShader(program, vertexShader);
            glAttachShader(program, fragmentShader);
            glLinkProgram(program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            int32 success;
            char infoLog[512];

            glGetProgramiv(program, GL_LINK_STATUS, &success);
            if (not success) {
                glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
                std::cerr << "Error: Shader linkage failed\n    " << infoLog << '\n';
            }

            return program;
        }
    }

    Shader::Shader(const char* vertexSource, const char* fragmentSource) {
        uint32 vertexShader = compileShader(vertexSource, GL_VERTEX_SHADER);
        uint32 fragmentShader = compileShader(fragmentSource, GL_FRAGMENT_SHADER);
        _programId = linkProgram(vertexShader, fragmentShader);
    }

    void Shader::use() const {
        glUseProgram(_programId);
    }

    Shader::Shader(uint32 programId) :
        _programId{programId} {}

    Shader::~Shader() {
        glDeleteProgram(_programId);
    }
}
