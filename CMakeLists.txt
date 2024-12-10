cmake_minimum_required(VERSION 3.17.0)
project(snake)
set(CMAKE_CXX_STANDARD 20)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

add_executable(snake main.cpp)
set_target_properties(snake PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.)
add_subdirectory(src)
set(INCROOT
    ${CMAKE_SOURCE_DIR}/includes/
)
target_include_directories(snake PUBLIC ${INCROOT})
target_link_libraries(${PROJECT_NAME} PRIVATE game)
target_link_libraries(${PROJECT_NAME} PRIVATE map)
target_link_libraries(${PROJECT_NAME} PRIVATE display)
target_link_libraries(${PROJECT_NAME} PRIVATE objects)
target_link_libraries(${PROJECT_NAME} PRIVATE player)
target_link_libraries(${PROJECT_NAME} PRIVATE textures)
target_link_libraries(${PROJECT_NAME} PRIVATE views)
