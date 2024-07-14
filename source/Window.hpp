#ifndef HELLOGL_WINDOW_HPP_
#define HELLOGL_WINDOW_HPP_

#include <string>
#include <functional>

#include "common/TypeAliases.hpp"

struct GLFWwindow;

namespace hellogl {

    class Window {
    public:
        using ResizeCallback = std::function<void(Window*,int32,int32)>;

        Window(int32 width, int32 height, const std::string& title);

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&&) = delete;

        ~Window();

        [[nodiscard]]
        bool isOpen() const;
        static void pollEvents();
        void swapBuffers();

        void setResizeCallback(ResizeCallback);

    private:
        GLFWwindow* _window{nullptr};

        ResizeCallback _resizeCallback{nullptr};

        void setupCallbacks();
    };
}

#endif
