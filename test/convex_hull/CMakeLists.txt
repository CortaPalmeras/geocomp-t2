
add_executable(
    convex_hull_test
    gift_wrapping_test.cpp
    convex_hull_test.cpp
    incremental_test.cpp
    incremental_nosort_test.cpp
    experimentacion.cpp
)

target_link_libraries(
    convex_hull_test
    GTest::gtest_main
    convex_hull
    poli
)

include(GoogleTest)
gtest_discover_tests(convex_hull_test)

