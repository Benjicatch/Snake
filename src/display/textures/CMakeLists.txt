set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display/textures)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display/textures)
set(SRC
    ${INCROOT}/Settings.hpp
    ${SRCROOT}/Settings.cpp
)
add_library(textures STATIC ${SRC})
target_link_libraries(textures PRIVATE raylib)
target_include_directories(textures PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
)
target_link_libraries(textures PRIVATE
    display)
