#include "Renderer.hpp"

#include <memory>
#include <stdexcept>
#include <GL/glew.h>

#include "Shader.hpp"

namespace hellogl {

    //TODO: Cleanup this mess :P

    const char* vertexSource = R"(
            #version 450 core
            layout (location = 0) in vec3 aPos;
            void main() {
                gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
            }
    )";

    const char* fragmentSource = R"(
        #version 450 core
        out vec4 fragColor;
        void main() {
                fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

    const float Vertices[] {
        -0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,
        0.5, 0.5, 0.0,
        0.5, -0.5, 0.0
    };

    const int Indices[] {
        0, 1, 3,
        1, 2, 3
    };

    uint32 vbo;
    uint32 vao;
    uint32 ebo;

    Renderer::Renderer() {
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error{"Failed to init GLEW"};
        }

        glClearColor(0.0, 0.05, 0.1, 1.0);

        // Create VAO and corresponding VBO and EBO
        //TODO: Wrap with RAII

        glCreateVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        _defaultShader = make_unique<Shader>(vertexSource, fragmentSource);
    }

    void Renderer::render() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        _defaultShader->use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}
