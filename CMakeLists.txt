cmake_minimum_required(VERSION 3.21)
project(cs61c C)

set(CMAKE_C_STANDARD 11)

include_directories(lab01/exercise1)
include_directories(lab01/exercise2)
include_directories(lab01/exercise3)
include_directories(lab01/exercise4)
include_directories(lab02)
include_directories(proj1)

add_executable(cs61c
        lab01/exercise1/ex1.c
        lab01/exercise1/ex1.h
        lab01/exercise1/test_ex1.c
        lab01/exercise2/pwd_checker.c
        lab01/exercise2/pwd_checker.h
        lab01/exercise2/test_pwd_checker.c
        lab01/exercise3/linked_list.c
        lab01/exercise3/linked_list.h
        lab01/exercise3/test_linked_list.c
        lab01/exercise4/ll_cycle.c
        lab01/exercise4/ll_cycle.h
        lab01/exercise4/test_ll_cycle.c
        lab02/bit_ops.c
        lab02/bit_ops.h
        lab02/linked_list.c
        lab02/linked_list.h
        lab02/test_bit_ops.c
        lab02/test_linked_list.c
        lab02/test_vector.c
        lab02/vector.c
        lab02/vector.h
        lab03/ex3.c
        lab03/fib.c
        proj1/interactive_snake.c
        proj1/snake.c
        proj1/snake_utils.c
        proj1/snake_utils.h
        proj1/state.c
        proj1/state.h
        proj1/unit_tests.c)
