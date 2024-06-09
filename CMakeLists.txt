cmake_minimum_required(VERSION 3.28)

project(
  Folly_Blossom
  VERSION 1.0.0
  LANGUAGES CXX)

include(GNUInstallDircs)

set(CMAKE_CXX_STANDARD 14)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)

set(CMAKE_MODULE_PATH ${${PROJECT_NAME}_SOURCE_DIR}/CMake; ${CMAKE_MODULE_PATH})

configure_file(config.h.in config.h)

add_subdirectory(encryption)
add_subdirectory(data)
add_subdirectory(file)

list(APPEND INCLUDE_DIRECTORIES encryption)
list(APPEND INCLUDE_DIRECTORIES file)
list(APPEND INCLUDE_DIRECTORIES data)

target_include_directories(${INCLUDE_DIRECTORIES}
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRECTORIES})
