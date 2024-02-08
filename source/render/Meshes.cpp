#include "Meshes.hpp"

namespace hellogl::Meshes {

    StaticMesh* createCube(float size) {
        size /= 2;
        return new StaticMesh{
                {
                        Vertex{{-size, -size, -size}, {0, 0}},
                        Vertex{{-size, -size, size}, {1, 0}},
                        Vertex{{-size, size, -size}, {0, 1}},
                        Vertex{{-size, size, size}, {1, 1}},
                        Vertex{{size, -size, -size}, {1, 0}},
                        Vertex{{size, -size, size}, {1, 1}},
                        Vertex{{size, size, -size}, {1, 1}},
                        Vertex{{size, size, size},{1, 0}} // Its broken btw)
                },
                {
                        0, 2, 4, 2, 4, 6, // -Z
                        0, 1, 4, 1, 4, 5, // -Y
                        0, 1, 2, 1, 2, 3, // -X
                        1, 3, 5, 3, 5, 7, // +Z
                        2, 3, 6, 3, 6, 7, // +Y
                        4, 5, 6, 5, 6, 7  // +X
                }
        };
    }
}
