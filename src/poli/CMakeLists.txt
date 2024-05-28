
add_library(poli STATIC poligono.cpp punto.cpp vector.cpp)

target_include_directories(poli PUBLIC ${PROJECT_SOURCE_DIR}/include/poli)

