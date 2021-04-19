# Initial cmake code
cmake_minimum_required(VERSION 3.8)

# Set C++ version to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add fPIC definition for spdlog [on Linux]
if (UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# Add GLFW library in to project
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)

# Add GLM library in to project
add_subdirectory(${CMAKE_SOURCE_DIR}/glm)

# Add SpdLog library in to project
add_subdirectory(${CMAKE_SOURCE_DIR}/spdlog)

# Create MaxyEngine project
project(MaxyEngine)
file(GLOB_RECURSE MaxyEngineFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_library(MaxyEngine SHARED ${MaxyEngineFiles})

# Add precompiled header in to MaxyEngine project
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Core/mxpch.h)

# Link GL, GLFW & SpdLog Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC GL)

# Include GLFW, GLM & SpdLog in to MaxyEngine project
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/spdlog/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glm/glm)

# Self include
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/MaxyEngine)

# Create SandBox project
project(SandBox)
file(GLOB_RECURSE SandBoxFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_executable(SandBox ${SandBoxFiles})

# Link SandBox to MaxyEngine
target_link_libraries(${PROJECT_NAME} PRIVATE MaxyEngine)