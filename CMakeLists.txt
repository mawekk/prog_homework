cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        library/sort/mergeSort.c
        library/map/map.c
        library/list/list.c
        library/vector/vector.c
        library/binary/binary.c
        library/DFA/DFA.c
        library/complexNumber/complexNumber.c
        )
add_library(library ${SOURCE_LIB})

add_executable(task_1 homework_1/task_1.c)
add_executable(task_2 homework_1/task_2.c)
add_executable(task_3 homework_1/task_3.c)
add_executable(task_4 homework_1/task_4.c)
add_executable(task_5 homework_1/task_5.c)

add_executable(hw2_task_1 homework_2/task_1.c)
add_executable(hw2_task_2 homework_2/task_2.c)

add_executable(test1_task_1 test_1/task_1.c)

add_executable(hw3_task_1 homework_3/task_1.c)
add_executable(hw3_task_2 homework_3/task_2.c)
add_executable(hw3_task_3 homework_3/task_3.c)

add_executable(hw4_task_1 homework_4/task_1.c)

add_executable(test2_task_1 test_2/task_1.c)
add_executable(test2_task_2 test_2/task_2.c)

add_executable(hw7 homework_7/task_1.c)

add_executable(hw8_task_2 homework_8/task_2.c)

add_executable(retest1_task_1 retest_1/task_1.c)
add_executable(retest1_task_2 retest_1/task_2.c)
add_executable(retest1_task_3 retest_1/task_3.c)

target_link_libraries(task_1 PRIVATE m)
target_link_libraries(task_4 PRIVATE m)
target_link_libraries(hw4_task_1 library)

target_link_libraries(hw2_task_1 library)
target_link_libraries(hw2_task_2 library)

target_link_libraries(hw3_task_1 library m)
target_link_libraries(hw3_task_2 library)
target_link_libraries(hw3_task_3 library)

target_link_libraries(test1_task_1 library m)

target_link_libraries(hw8_task_2 library)

target_link_libraries(retest1_task_1 library m)