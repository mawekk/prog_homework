cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_library(DNA STATIC library/DNA.c)

add_executable(hw2_task_2 homework_2/task_2.c)
target_link_libraries(hw2_task_2 DNA)