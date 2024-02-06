#ifndef HELLOGL_SHADER_TYPE_HPP_
#define HELLOGL_SHADER_TYPE_HPP_

#include <string>

#include "common/TypeAliases.hpp"

namespace hellogl {

    struct ShaderType {
    public:
        const std::string Name;
        const uint32 AsGlEnum;

        static const ShaderType Vertex;
        static const ShaderType Fragment;

        ShaderType(const ShaderType&) = delete;
        ShaderType& operator=(const ShaderType&) = delete;
        ShaderType(ShaderType&&) = delete;
        ShaderType& operator=(ShaderType&&) = delete;

    private:
        ShaderType(const std::string& name, uint32 asGlEnum);

    };
}

#endif
