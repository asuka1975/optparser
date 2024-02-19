cmake_minimum_required(VERSION 3.20)

project(optparser)

enable_testing()

set(CMAKE_CXX_STANDARD 20)

add_library(optparser src/optparser.cpp
    src/types/optvalue/defaults/int_rule.cpp)

target_include_directories(optparser PRIVATE $ENV{ASUKA1975_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(optparser PRIVATE $ENV{ASUKA1975_LD_LIBRARY_PATH})
target_link_libraries(optparser PRIVATE $ENV{ASUKA1975_LD_LIBRARIES})

add_subdirectory(test)