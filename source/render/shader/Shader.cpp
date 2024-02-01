#include "Shader.hpp"

#include <iostream>
#include <GL/glew.h>

#include "render/shader/ShaderType.hpp"

namespace hellogl {

    namespace internal {
        uint32 compileShader(const char* shaderSource, const ShaderType& shaderType) {
            uint32 shader = glCreateShader(shaderType.AsGlEnum);
            glShaderSource(shader, 1, &shaderSource, nullptr);
            glCompileShader(shader);

            int32 success;
            char infoLog[512];

            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (not success) {
                glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
                std::cerr << "Error: " << shaderType.Name << " shader compilation failed\n    " << infoLog << '\n';
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

    Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource) {
        uint32 vertexShader = internal::compileShader(vertexSource.c_str(), ShaderType::Vertex);
        uint32 fragmentShader = internal::compileShader(fragmentSource.c_str(), ShaderType::Fragment);
        _programId = internal::linkProgram(vertexShader, fragmentShader);
    }

    Shader::~Shader() {
        glDeleteProgram(_programId);
    }

    void Shader::use() const {
        glUseProgram(_programId);
    }
}