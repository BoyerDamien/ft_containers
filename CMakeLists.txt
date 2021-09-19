cmake_minimum_required(VERSION 3.0.0)
project(ft_container VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(CTest)
enable_testing()

set(
    SOURCE
    srcs/
)

add_executable(ft_container 
    main.cpp
)

include_directories(
    includes
    includes/iterators
    includes/algorithms
    includes/test
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
