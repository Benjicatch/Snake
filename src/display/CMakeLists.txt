set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display)
set(SRC
    ${INCROOT}/DisplayManager.hpp
    ${SRCROOT}/DisplayManager.cpp
    ${INCROOT}/AObjectDisplay.hpp
    ${SRCROOT}/AObjectDisplay.cpp
    ${INCROOT}/AViewDisplay.hpp
    ${SRCROOT}/AViewDisplay.cpp
)
add_subdirectory(textures)
add_subdirectory(views)
add_library(display STATIC ${SRC})
target_link_libraries(display PRIVATE raylib)
target_include_directories(display PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/game
    ${CMAKE_SOURCE_DIR}/includes/game/map
)
target_link_libraries(display PRIVATE
    map
    player
    textures
    views)
