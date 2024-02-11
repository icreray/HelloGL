#ifndef HELLOGL_RENDERER_HPP_
#define HELLOGL_RENDERER_HPP_

#include "common/TypeAliases.hpp"
#include "render/mesh/StaticMesh.hpp"
#include "render/shader/Shader.hpp"

namespace hellogl {

    class Renderer {
    public:
        Renderer();

        Renderer(const Renderer&) = delete;
        Renderer& operator=(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        Renderer& operator=(Renderer&&) = delete;

        void render();

        void setViewport(int32 width, int32 height);

    private:
        float _viewportWidth;
        float _viewportHeight;

        unique<Shader> _defaultShader{nullptr};
        unique<StaticMesh> _cubeMesh{nullptr};

    };
}

#endif
