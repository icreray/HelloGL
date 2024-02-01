#ifndef HELLOGL_WINDOW_HPP_
#define HELLOGL_WINDOW_HPP_

#include <string_view>
#include <GLFW/glfw3.h>

#include "common/TypeAliases.hpp"

namespace hellogl {

    class Window {
    public:
        Window(int32 width, int32 height, std::string_view title);
        ~Window();

        [[nodiscard]]
        bool isOpen() const;
        static void pollEvents();
        void swapBuffers();

    private:
        GLFWwindow* _window{nullptr};
    };
}

#endif
