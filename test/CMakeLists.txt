
add_executable(
    Tarea2Tests
    main_test.cpp
    poligono_test.cpp
    punto_test.cpp
    vector_test.cpp
)

#https://google.github.io/googletest/quickstart-cmake.html
target_link_libraries(
    Tarea2Tests
    Tarea2
    gtest_main
)

target_compile_options(Tarea2Tests PUBLIC ${global_compile_options})

#include(GoogleTest)
#gtest_discover_tests(Tarea2Tests)

