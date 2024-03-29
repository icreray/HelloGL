#ifndef HELLOGL_SHADER_HPP_
#define HELLOGL_SHADER_HPP_

#include <string>
#include <glm/glm.hpp>

#include "common/TypeAliases.hpp"

namespace hellogl {

    class Shader {
    public:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);

        Shader(Shader&&) = delete;
        Shader& operator=(Shader&&) = delete;
        Shader(const Shader&) = delete;
        Shader& operator=(const Shader&) = delete;

        ~Shader();

        void use() const;
        void setModelView(glm::mat4 value);
        void setProjection(glm::mat4 value);

    private:
        uint32 _programId{0};

        uint32 _modelViewUniform{0};
        uint32 _projectionUniform{0};
    };
}

#endif
