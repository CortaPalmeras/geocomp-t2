
add_library(
    convex_hull STATIC
    gift_wrapping.cpp
    incremental.cpp
)

target_link_libraries(
    convex_hull
    poli
)

target_include_directories(
    convex_hull 
    PUBLIC ${PROJECT_SOURCE_DIR}/include/poli
           ${PROJECT_SOURCE_DIR}/include/convex_hull
)

