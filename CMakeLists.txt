cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)
set(CMAkE_CXX_STANDARD_REQUIRED ON)

project(
        HelloGl
        VERSION 1.0
        LANGUAGES CXX
)

add_subdirectory(external)
add_subdirectory(source)
