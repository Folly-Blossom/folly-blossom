cmake_minimum_required(VERSION 3.28)

project(Folly_Blossom VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDircs)

add_library(${PROJECT_NAME} INTERFACE)

set(CMAKE_CXX_STANDARD 14)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)

target_include_directories(
        ${PROJECT_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Include Catch2 for tests.

find_package(Catch2 REQUIRED)

add_executable(Folly_Blossom_Test test/test.cpp)

target_link_libraries(Folly_Blossom_Test PRIVATE Catch2::Catch2)

target_include_directories(Folly_Blossom_Test PRIVATE ${PROJECT_SOURCE_DIR}/include)

include(CTest)

include(Catch)

catch_discover_tests(Folly_Blossom_Test)

enable_testing()
