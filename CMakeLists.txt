cmake_minimum_required(VERSION 2.8)
project(grep-clone C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set (CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SOURCES
    # "${PROJECT_SOURCE_DIR}/src/*.cc"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCES})
# target_link_libraries (${PROJECT_NAME} lib1 lib2)
