cmake_minimum_required(VERSION 3.21)
project(new)

find_package(Eigen3 REQUIRED)
add_library(${PROJECT_NAME} src/YSsharedMemory.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        include
)
target_link_libraries(${PROJECT_NAME}
        Eigen3::Eigen
)