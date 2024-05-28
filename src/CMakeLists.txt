
add_library(Tarea2 STATIC poligono.cpp punto.cpp vector.cpp)

target_include_directories(Tarea2 PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_options(Tarea2 PUBLIC ${global_compile_options})

