file(GLOB_RECURSE HEADERS *.hpp)
file(GLOB_RECURSE SOURCES *.cpp)

add_executable(main ${HEADERS} ${SOURCES})
target_link_libraries(main ${GL_LIBS} ${UTIL_LIBS})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES_DIR} $<TARGET_FILE_DIR:main>/resources
)
