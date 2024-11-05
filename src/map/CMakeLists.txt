add_subdirectory(objects)
set(INCROOT ${CMAKE_SOURCE_DIR}/includes/map)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/map)
set(SRC
    ${INCROOT}/Map.hpp
    ${SRCROOT}/Map.cpp
)
add_library(map STATIC ${SRC})
target_link_libraries(map PRIVATE raylib src objects)
target_include_directories(map PUBLIC
    ${INCROOT}
    ${INCROOT}/objects
)
