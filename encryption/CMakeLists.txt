cmake_minimum_required(VERSION 3.28)
project(Folly_Blossom_Encryption)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${${PROJECT_NAME}_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

add_library(${PROJECT_NAME} STATIC)

add_executable(
        ${PROJECT_NAME}
)
