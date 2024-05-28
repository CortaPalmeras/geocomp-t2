cmake_minimum_required(VERSION 3.20)

project(geocomp_t2
    DESCRIPTION "Tarea 2 de Geometría Computacional"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(global_compile_options -Wall -Wextra -Werror -pedantic)
add_compile_options(${global_compile_options})

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)

enable_testing()

