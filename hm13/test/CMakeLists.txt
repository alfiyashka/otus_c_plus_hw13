cmake_minimum_required(VERSION 3.28.3)


set(HW13_UNIT_TESTS 
    test.cpp

)

include_directories(../src/)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set_property(TARGET  PROPERTY CXX_STANDARD 23)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Eigen3 REQUIRED)

add_executable (hw13_test  ${HW13_UNIT_TESTS} main.cpp)


target_link_libraries(hw13_test
 hw13lib
 ${GTEST_LIBRARIES}
 ${GTEST_MAIN_LIBRARIES}
 pthread
 Eigen3::Eigen)

