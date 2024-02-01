#include "Window.hpp"

namespace hellogl {

    Window::Window(int32 width, int32 height, const std::string& title) {
        glfwInit();

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_window);
    }

    Window::~Window() {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }

    bool Window::isOpen() const {
        return not glfwWindowShouldClose(_window);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(_window);
    }
}
