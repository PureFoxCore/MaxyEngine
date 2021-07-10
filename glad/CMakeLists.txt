cmake_minimum_required(VERSION 3.8)

project(glad)
file(GLOB_RECURSE gladFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.c ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h)
add_library(${PROJECT_NAME} SHARED ${gladFiles})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include)