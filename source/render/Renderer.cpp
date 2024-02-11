#include "Renderer.hpp"

#include <memory>
#include <stdexcept>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glm/ext/matrix_transform.hpp>
#include <GL/glew.h>

#include "render/mesh/Meshes.hpp"
#include "render/shader/Shader.hpp"
#include "util/FileUtils.hpp"

namespace hellogl {

    uint32 texture;

    Renderer::Renderer() {
        if (glewInit() != GLEW_OK) {
            throw std::runtime_error{"Failed to init GLEW"};
        }

        glClearColor(0.0, 0.05, 0.1, 1.0);

        std::string vertexSource = FileUtils::readString("resources/shaders/default.vert");
        std::string fragmentSource = FileUtils::readString("resources/shaders/default.frag");

        glEnable(GL_DEPTH_TEST);

        //TODO: move into material class
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int width, height, nrChannels;
        ubyte* data = stbi_load("resources/textures/gold_block.png", &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "lol\n";
        }

        stbi_image_free(data);
        //


        _defaultShader = make_unique<Shader>(vertexSource, fragmentSource);
        _cubeMesh = unique<StaticMesh> {Meshes::createCube(1)};
    }

    void Renderer::render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        _defaultShader->use();

        //TODO: Move into camera class
        glm::mat4 projection{1};
        projection = glm::scale(projection, {_viewportHeight/_viewportWidth, 1, 1});

        _defaultShader->setProjection(projection);

        glBindTexture(GL_TEXTURE_2D, texture);
        _cubeMesh->render(*_defaultShader);
    }

    void Renderer::setViewport(int32 width, int32 height) {
        _viewportWidth = width;
        _viewportHeight = height;

        glViewport(0, 0, width, height);
    }
}
