add_subdirectory(glew-cmake)
add_subdirectory(glfw)

set(GL_LIBS glfw libglew_static PARENT_SCOPE)
