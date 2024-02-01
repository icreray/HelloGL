#ifndef HELLOGL_RENDERER_HPP_
#define HELLOGL_RENDERER_HPP_

#include "common/TypeAliases.hpp"
#include "render/Shader.hpp"

namespace hellogl {

    class Renderer {
    public:
        Renderer();

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        Renderer& operator=(Renderer&&) = delete;

        void render();

    private:
        unique<Shader> _defaultShader{nullptr};

    };
}

#endif
