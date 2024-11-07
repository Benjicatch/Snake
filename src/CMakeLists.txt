set(INCROOT ${CMAKE_SOURCE_DIR}/includes/)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/)
set(SRC
    ${INCROOT}/ACase.hpp
    ${SRCROOT}/ACase.cpp
)
add_library(src STATIC ${SRC})
target_link_libraries(src PRIVATE raylib)
target_include_directories(src PUBLIC
    ${INCROOT}
)

add_subdirectory(display)
add_subdirectory(map)
add_subdirectory(player)
