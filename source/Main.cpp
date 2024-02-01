#include "Window.hpp"
#include "render/Renderer.hpp"

using namespace hellogl;

int main() {
    Window window{1200, 720, "HelloGl"};
    Renderer renderer{};

    while (window.isOpen()) {
        renderer.render();
        window.swapBuffers();
        Window::pollEvents();
    }

    return 0;
}