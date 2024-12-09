set(INCROOT ${CMAKE_SOURCE_DIR}/includes/map/objects)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/map/objects)
set(SRC
    ${INCROOT}/Apple.hpp
    ${SRCROOT}/Apple.cpp
    ${INCROOT}/Obstacle.hpp
    ${SRCROOT}/Obstacle.cpp
)
add_library(objects STATIC ${SRC})
target_link_libraries(objects PRIVATE raylib src)
target_include_directories(objects PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
)
