#include "Window.hpp"

#include <GLFW/glfw3.h>

namespace hellogl {

    Window::Window(int32 width, int32 height, const std::string& title) {
        glfwInit();

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_window);

        setupCallbacks();
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

    void Window::setResizeCallback(ResizeCallback callback) {
        _resizeCallback = std::move(callback);
    }

    void Window::setupCallbacks() {
        glfwSetWindowUserPointer(_window, this);
        auto resizeCallback = [](GLFWwindow* window, int width, int height) {
            auto* userPointer = static_cast<Window*>(glfwGetWindowUserPointer(window));
            if (userPointer->_resizeCallback) {
                userPointer->_resizeCallback(userPointer, width, height);
            }
        };
        glfwSetWindowSizeCallback(_window, resizeCallback);
    }
}
