#ifndef HELLOGL_STATIC_MESH_HPP_
#define HELLOGL_STATIC_MESH_HPP_

#include <vector>

#include <glm/glm.hpp>

#include "common/TypeAliases.hpp"
#include "render/shader/Shader.hpp"

namespace hellogl {

    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoord;
    };

    class StaticMesh {
    public:
        StaticMesh(std::vector<Vertex> vertices, std::vector<uint32> indices);
        ~StaticMesh();

        void render(Shader& shader);

    private:
        const std::vector<Vertex> _vertices;
        const std::vector<uint32> _indices;

        uint32 _vertexArrayId{0};
        uint32 _vertexBufferId{0};
        uint32 _indexBufferId{0};

        void setup();
    };
}

#endif
