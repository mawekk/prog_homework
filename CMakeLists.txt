cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_library(List STATIC library/list.c)

add_executable(task_2 homework_1/task_2.c)
add_executable(task_1 homework_1/task_1.c)
add_executable(task_3 homework_1/task_3.c)
add_executable(task_4 homework_1/task_4.c)
target_link_libraries(task_4 PRIVATE m)
add_executable(task_5 homework_1/task_5.c)

add_executable(hw2_task_2 homework_2/task_2.c)
target_link_libraries(hw2_task_2 List)

