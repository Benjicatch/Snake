set(INCROOT ${CMAKE_SOURCE_DIR}/includes/game)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/game)
set(SRC
    ${INCROOT}/ACase.hpp
    ${SRCROOT}/ACase.cpp
)
add_library(game STATIC ${SRC})
target_link_libraries(game PRIVATE raylib)
target_include_directories(game PUBLIC
    ${INCROOT}
)
add_subdirectory(map)
