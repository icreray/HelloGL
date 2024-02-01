set(HEADERS
        Window.hpp
        common/TypeAliases.hpp
        render/Renderer.hpp
        render/shader/Shader.hpp
        render/shader/ShaderType.hpp
        util/FileUtils.hpp
)

set(SOURCES
        Main.cpp
        Window.cpp
        render/Renderer.cpp
        render/shader/Shader.cpp
        render/shader/ShaderType.cpp
        util/FileUtils.cpp
)

add_executable(main ${HEADERS} ${SOURCES})
target_link_libraries(main ${GL_LIBS})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES_DIR} $<TARGET_FILE_DIR:main>/resources
)
