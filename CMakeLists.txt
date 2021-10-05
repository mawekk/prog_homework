cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_library(Vector STATIC library/vector.c)

add_executable(test1_task_1 test_1/task_1.c)
target_link_libraries(test1_task_1 Vector)