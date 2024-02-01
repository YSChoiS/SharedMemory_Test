cmake_minimum_required(VERSION 3.21)
project(sharedMemory_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(ys)
add_subdirectory(HS)
add_subdirectory(original)

add_executable(sharedMemory_test main.cpp)

target_link_libraries(${PROJECT_NAME}
        new
        HS
        ori
)