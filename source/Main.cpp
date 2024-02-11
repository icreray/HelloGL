#include "Window.hpp"
#include "render/Renderer.hpp"

using namespace hellogl;

int main() {
    Window window{1200, 720, "HelloGl"};
    Renderer renderer{};
    renderer.setViewport(1200, 720);

    window.setResizeCallback([&renderer](Window*, int32 width, int32 height) {
        renderer.setViewport(width, height);
    });

    while (window.isOpen()) {
        renderer.render();
        window.swapBuffers();
        Window::pollEvents();
    }

    return 0;
}