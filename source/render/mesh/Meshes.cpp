#include "Meshes.hpp"

namespace hellogl::Meshes {

    StaticMesh* createCube(float size) {
        size /= 2;
        return new StaticMesh{
                {
                        Vertex{{-size, -size, -size}, {0, 0, -1},  {0, 0}},
                        Vertex{{-size, size, -size}, {0, 0, -1}, {0, 1}},
                        Vertex{{size, -size, -size}, {0, 0, -1}, {1, 0}},
                        Vertex{{size, size, -size}, {0, 0, -1}, {1, 1}},

                        Vertex{{-size, -size, -size}, {0, -1, 0}, {0, 0}},
                        Vertex{{-size, -size, size}, {0, -1, 0}, {0, 1}},
                        Vertex{{size, -size, -size}, {0, -1, 0}, {1, 0}},
                        Vertex{{size, -size, size}, {0, -1, 0}, {1, 1}},

                        Vertex{{-size, -size, -size}, {-1, 0, 0}, {0, 0}},
                        Vertex{{-size, -size, size}, {-1, 0, 0}, {0, 1}},
                        Vertex{{-size, size, -size}, {-1, 0, 0}, {1, 0}},
                        Vertex{{-size, size, size}, {-1, 0, 0}, {1, 1}},

                        Vertex{{-size, -size, size}, {0, 0, 1}, {0, 0}},
                        Vertex{{-size, size, size}, {0, 0, 1}, {0, 1}},
                        Vertex{{size, -size, size}, {0, 0, 1}, {1, 0}},
                        Vertex{{size, size, size}, {0, 0, 1}, {1, 1}},

                        Vertex{{-size, size, -size}, {0, 1, 0}, {0, 0}},
                        Vertex{{-size, size, size}, {0, 1, 0}, {0, 1}},
                        Vertex{{size, size, -size}, {0, 1, 0}, {1, 0}},
                        Vertex{{size, size, size}, {0, 1, 0}, {1, 1}},

                        Vertex{{size, -size, -size}, {1, 0, 0}, {0, 0}},
                        Vertex{{size, -size, size}, {1, 0, 0}, {0, 1}},
                        Vertex{{size, size, -size}, {1, 0, 0}, {1, 0}},
                        Vertex{{size, size, size}, {1, 0, 0}, {1, 1}}
                },
                {
                        0, 1, 2, 1, 2, 3, // -Z
                        4, 5, 6, 5, 6, 7, // -Y
                        8, 9, 10, 9, 10, 11, // -X
                        12, 13, 14, 13, 14, 15, // +Z
                        16, 17, 18, 17, 18, 19, // +Y
                        20, 21, 22, 21, 22, 23  // +X
                }
        };
    }
}
