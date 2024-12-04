set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display/textures)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display/textures)
set(SRC
    ${INCROOT}/Settings.hpp
    ${SRCROOT}/Settings.cpp
    ${INCROOT}/Play.hpp
    ${SRCROOT}/Play.cpp
    ${INCROOT}/Pause.hpp
    ${SRCROOT}/Pause.cpp
    ${INCROOT}/Back.hpp
    ${SRCROOT}/Back.cpp
    ${INCROOT}/Restart.hpp
    ${SRCROOT}/Restart.cpp
)
add_library(textures STATIC ${SRC})
target_link_libraries(textures PRIVATE raylib)
target_include_directories(textures PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
    ${CMAKE_SOURCE_DIR}/includes/display
    ${CMAKE_SOURCE_DIR}/includes/map/objects
    ${CMAKE_SOURCE_DIR}/includes/player
)
target_link_libraries(textures PRIVATE
    display)
