cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_library(Vector STATIC library/vector.c)

add_executable(test1_task_1 test_1/task_1.c)
target_link_libraries(test1_task_1 Vector m)

add_executable(task_2 homework_1/task_2.c)
add_executable(task_1 homework_1/task_1.c)
add_executable(task_3 homework_1/task_3.c)
add_executable(task_4 homework_1/task_4.c)
target_link_libraries(task_4 PRIVATE m)
target_link_libraries(task_1 PRIVATE m)
add_executable(task_5 homework_1/task_5.c)

