cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})

add_library(Map STATIC homework2/map.c)
add_executable(hw2_task_1 homework2/task_1.c)
target_link_libraries(hw2_task_1 Map)
