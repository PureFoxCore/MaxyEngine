# Initial cmake code
cmake_minimum_required(VERSION 3.8)

# Set C++ version to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add GLFW project
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)

# Create MaxyEngine project
project(MaxyEngine)
file(GLOB_RECURSE MaxyEngineFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_library(MaxyEngine SHARED ${MaxyEngineFiles})

# Link GL & SDL2 Library
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC GL)

# Include glfw to MaxyEngine project
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glfw/include)

# Create SandBox project
project(SandBox)
file(GLOB_RECURSE SandBoxFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_executable(SandBox ${SandBoxFiles})

# Link SandBox to MaxyEngine
target_link_libraries(${PROJECT_NAME} PRIVATE MaxyEngine)

# Include MaxyEngine in to SandBox 
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/MaxyEngine)