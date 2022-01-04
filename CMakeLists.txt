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

# Create MaxyEngine project
project(MaxyEngine)
file(GLOB_RECURSE ${PROJECT_NAME}Files
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.c
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}Files})

# Check use editor or no
option(MAXY_EDITOR "Use editor to edit game" ON)

if(MAXY_EDITOR)
    target_compile_definitions(${PROJECT_NAME} PRIVATE MAXY_EDITOR)    
endif(MAXY_EDITOR)

# Platform definition
if(WIN32 OR MINGW)
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
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/mxpch.hpp)

# Link GL, GLFW, GLAD, ImGUi & SpdLog Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)

if (WIN32 OR MINGW)
    target_link_libraries(${PROJECT_NAME} PUBLIC imm32)
endif()
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

if (MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
endif()

file(GLOB_RECURSE ${PROJECT_NAME}Files
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.h
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.c
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.hpp 
    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/**.cpp)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}Files})

# For MinGW build
if (MINGW)
    message(STATUS "[MinGW Build] static link static-libgcc -static-libstdc++ and winpthread")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
endif()

# Link SandBox to MaxyEngine
target_link_libraries(${PROJECT_NAME} PRIVATE MaxyEngine)