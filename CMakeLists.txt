cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)
set(CMAkE_CXX_STANDARD_REQUIRED ON)

project(
        HelloGl
        VERSION 1.0
        LANGUAGES CXX
)

set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

add_subdirectory(external)
add_subdirectory(source)
