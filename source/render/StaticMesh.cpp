#include "StaticMesh.hpp"

#include <utility>
#include <GL/glew.h>

#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace hellogl {

    StaticMesh::StaticMesh(std::vector<Vertex> vertices, std::vector<uint32> indices) :
        _vertices{std::move(vertices)},
        _indices{std::move(indices)} {
        setup();
    }

    void StaticMesh::setup() {
        glCreateVertexArrays(1, &_vertexArrayId);
        glCreateBuffers(1, &_vertexBufferId);
        glCreateBuffers(1, &_indexBufferId);

        glBindVertexArray(_vertexArrayId);

        glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(uint32), &_indices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));

        glBindVertexArray(0);
    }

    StaticMesh::~StaticMesh() {
        glDeleteVertexArrays(1, &_vertexArrayId);
        glDeleteBuffers(1, &_vertexBufferId);
        glDeleteBuffers(1, &_indexBufferId);
    }

    void StaticMesh::render(Shader& shader) {
        glBindVertexArray(_vertexArrayId);

        shader.use();

        //TODO: move this test code outside
        glm::mat4 viewProjection{1};
        viewProjection = glm::scale(viewProjection, {720/1200.0, 1, 1});
        viewProjection = glm::rotate(viewProjection, (float)glfwGetTime(), {1, 1, 1});
        shader.setViewProjection(viewProjection);
        //end

        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}
