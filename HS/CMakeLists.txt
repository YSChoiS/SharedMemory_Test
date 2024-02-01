cmake_minimum_required(VERSION 3.21)
project(HS)

find_package(Eigen3 REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
        INTERFACE
        include
)
target_link_libraries(${PROJECT_NAME}
        INTERFACE
        Eigen3::Eigen
)