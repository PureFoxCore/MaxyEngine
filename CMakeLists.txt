# Initial cmake code
cmake_minimum_required(VERSION 3.8)

# Set C++ version to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add GLFW, GLAD, GLM, SpdLog, ImGUI
add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/glm)
add_subdirectory(${CMAKE_SOURCE_DIR}/spdlog)
add_subdirectory(${CMAKE_SOURCE_DIR}/imgui)

# Add fPIC definition for spdlog [on Linux]
if (UNIX AND NOT APPLE)
    target_compile_options(spdlog PRIVATE -fPIC)
endif()

# Create MaxyEngine project
project(MaxyEngine)
file(GLOB_RECURSE MaxyEngineFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_library(${PROJECT_NAME} SHARED ${MaxyEngineFiles})

# Platform definition
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE MAXY_PLATFORM_WINDOWS)
endif()
if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE MAXY_PLATFORM_APPLE)
endif()
if(UNIX AND NOT APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE MAXY_PLATFORM_LINUX)
endif()

# Enable asserts in Maxy
target_compile_definitions(${PROJECT_NAME} PRIVATE MAXY_ENABLE_ASSERTS)

# Don't include GLFW
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)

# Add precompiled header in to MaxyEngine project
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/mxpch.h)

# Link GL, GLFW, GLAD, ImGUi & SpdLog Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} PUBLIC GL)
endif()

# Include GLFW, GLAD, GLM, ImGUI & SpdLog in to MaxyEngine project
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glad/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/spdlog/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/glm/glm)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/imgui/)

# Self include
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${PROJECT_NAME})

# Create SandBox project
project(SandBox)
file(GLOB_RECURSE SandBoxFiles ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_executable(${PROJECT_NAME} ${SandBoxFiles})

# Link SandBox to MaxyEngine
target_link_libraries(${PROJECT_NAME} PRIVATE MaxyEngine)