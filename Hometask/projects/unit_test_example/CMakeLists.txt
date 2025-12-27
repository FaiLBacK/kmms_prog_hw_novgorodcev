project(unit_test_example)

set(LIBRARY bubble_sort_lib6666)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


add_library(${LIBRARY} 
    src/io.cpp
    src/sortings.cpp
)


add_executable(${PROJECT_NAME}_executable src/main.cpp)

target_link_libraries(${PROJECT_NAME}_executable ${LIBRARY})

add_subdirectory(test)