set(HEADERS
        Window.hpp
        common/TypeAliases.hpp
        render/Shader.hpp
        render/Renderer.hpp
)

set(SOURCES
        Main.cpp
        Window.cpp
        render/Shader.cpp
        render/Renderer.cpp
)

add_executable(main ${HEADERS} ${SOURCES})
target_link_libraries(main ${GL_LIBS})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
