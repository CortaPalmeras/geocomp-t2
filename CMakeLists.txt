
cmake_minimum_required(VERSION 3.20)

project(geocomp_t2
    DESCRIPTION "Tarea 2 de Geometría Computacional"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CONFIGURATION_TYPES Release)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" 
    OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        "-Wall"
        "-Wextra"
        "-Wpedantic"
    )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(
        "/W4" 
    )

endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

