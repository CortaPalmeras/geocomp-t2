
add_executable(
    convex_hull_test
    gift_wrapping_test.cpp
    incremental_test.cpp
)

target_link_libraries(
    convex_hull_test
    convex_hull
    poli
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(convex_hull_test)

