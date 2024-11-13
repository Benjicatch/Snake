set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display)
set(SRC
    ${INCROOT}/Display.hpp
    ${SRCROOT}/Display.cpp
    ${INCROOT}/ADisplay.hpp
    ${SRCROOT}/ADisplay.cpp
)
add_subdirectory(textures)
add_library(display STATIC ${SRC})
target_link_libraries(display PRIVATE raylib)
target_include_directories(display PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
)
target_link_libraries(display PRIVATE
    map
    player
    textures)
