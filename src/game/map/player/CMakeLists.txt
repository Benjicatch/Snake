set(INCROOT ${CMAKE_SOURCE_DIR}/includes/game/map/player)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/game/map/player)
set(SRC
    ${INCROOT}/Player.hpp
    ${SRCROOT}/Player.cpp
)
add_library(player STATIC ${SRC})
target_link_libraries(player PRIVATE raylib)
target_include_directories(player PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/game
)
target_link_libraries(player PRIVATE
    map)
