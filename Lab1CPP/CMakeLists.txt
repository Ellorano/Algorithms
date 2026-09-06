cmake_minimum_required(VERSION 3.10)
project(Lab1CPP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab1CPP lab1.cpp)
target_include_directories(Lab1CPP PUBLIC ../LibraryCPP)
target_link_libraries(Lab1CPP LibraryCPP)

enable_testing()

add_test(NAME test1_task1 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test1.txt
)
set_property(TEST test1_task1 PROPERTY PASS_REGULAR_EXPRESSION "0 0 -9 5")

add_test(NAME test2_task1 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test2.txt
)
set_property(TEST test2_task1 PROPERTY PASS_REGULAR_EXPRESSION "-10 0 0 -3 3")

add_test(NAME test3_task1 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test3.txt
)
set_property(TEST test3_task1 PROPERTY PASS_REGULAR_EXPRESSION "90 -75 15 -100 0 -55")

add_test(NAME test1_task2 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test1.txt
)
set_property(TEST test1_task2 PROPERTY PASS_REGULAR_EXPRESSION "0 0 0 10 20")

add_test(NAME test2_task2 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test2.txt
)
set_property(TEST test2_task2 PROPERTY PASS_REGULAR_EXPRESSION "0 0 0 -5 2 0")

add_test(NAME test3_task2 
    COMMAND Lab1CPP ${CMAKE_CURRENT_SOURCE_DIR}/test3.txt
)
set_property(TEST test3_task2 PROPERTY PASS_REGULAR_EXPRESSION "0 0 0 1000")

add_custom_target(test_all
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS Lab1CPP
    COMMENT "Running all tests..."
)
