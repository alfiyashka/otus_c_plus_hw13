cmake_minimum_required(VERSION 3.28.3)



set(PATCH_VERSION "1" CACHE INTERNAL "PATCH_VERSION" )
set(PROJECT_VERSION 0.0.${PATCH_VERSION})


project(fasio_mnist VERSION ${PROJECT_VERSION} LANGUAGES C CXX)


configure_file(version.h.in version.h)

include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

set ( HW13_FILES
   src/classifier.h
   src/mlp_classifier.h
   src/mlp_classifier.cpp
   src/utils.hpp
   src/utils.cpp

   src/accuracyHelper.hpp
   src/accuracyHelper.cpp
)

find_package (Eigen3 REQUIRED)

add_executable(fashio_mnist ${HW13_FILES} main.cpp)

add_library(hw13lib STATIC ${HW13_FILES})


target_link_libraries (fashio_mnist Eigen3::Eigen)

set_property(TARGET fashio_mnist PROPERTY CXX_STANDARD 23)

enable_testing()
add_subdirectory(test)

include("functions.cmake")
generate_packages(${PROJECT_NAME})

