set(INCROOT ${CMAKE_SOURCE_DIR}/includes/game/map/objects)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/game/map/objects)
set(SRC
    ${INCROOT}/Apple.hpp
    ${SRCROOT}/Apple.cpp
    ${INCROOT}/Obstacle.hpp
    ${SRCROOT}/Obstacle.cpp
)
add_library(objects STATIC ${SRC})
target_link_libraries(objects PRIVATE raylib)
target_include_directories(objects PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/game
)
