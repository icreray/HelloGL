add_subdirectory(glew-cmake)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(stb)

set(GL_LIBS glfw libglew_static glm PARENT_SCOPE)
set(UTIL_LIBS stb_image PARENT_SCOPE)
