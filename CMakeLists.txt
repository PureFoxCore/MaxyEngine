# Initial cmake code
cmake_minimum_required(VERSION 3.8)

# Set C++ version to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create MaxyEngine project
project(MaxyEngine)
file(GLOB_RECURSE MaxyEngineFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.cpp)
add_library(MaxyEngine SHARED ${MaxyEngineFiles})

#link GL & SDL2 Library
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
target_link_libraries(${PROJECT_NAME} PUBLIC GL)

# Create SandBox project
project(SandBox)
file(GLOB_RECURSE SandBoxFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/**.cpp)
add_executable(SandBox ${SandBoxFiles})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/MaxyEngine/src)
target_link_libraries(${PROJECT_NAME} PRIVATE MaxyEngine)