
add_executable(
    poli_test
    poligono_test.cpp
    punto_test.cpp
    vector_test.cpp
)

target_link_libraries(
    poli_test
    poli
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(poli_test)

