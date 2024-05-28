
add_executable(
    poli_test
    main_test.cpp
    poligono_test.cpp
    punto_test.cpp
    vector_test.cpp
)

target_include_directories(poli_test PUBLIC ${PROJECT_SOURCE_DIR}/include/poli)

target_link_libraries(
    poli_test
    poli
    gtest_main
)

