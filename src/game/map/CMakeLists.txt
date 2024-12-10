add_subdirectory(objects)
add_subdirectory(player)
set(INCROOT ${CMAKE_SOURCE_DIR}/includes/game/map)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/game/map)
set(SRC
    ${INCROOT}/Map.hpp
    ${SRCROOT}/Map.cpp
)
add_library(map STATIC ${SRC})
target_link_libraries(map PRIVATE raylib game objects player)
target_include_directories(map PUBLIC
    ${INCROOT}
    ${INCROOT}/player
    ${INCROOT}/objects
)
