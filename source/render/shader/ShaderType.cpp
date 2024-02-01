#include "ShaderType.hpp"

namespace hellogl {
    const ShaderType ShaderType::Vertex{"vertex", GL_VERTEX_SHADER};
    const ShaderType ShaderType::Fragment{"fragment", GL_FRAGMENT_SHADER};

    ShaderType::ShaderType(const std::string& name, GLenum asGlEnum) :
        Name{name},
        AsGlEnum{asGlEnum} {}
}
