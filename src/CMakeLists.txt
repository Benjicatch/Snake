set(INCROOT ${CMAKE_SOURCE_DIR}/includes/)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/)
set(SRC
    ${INCROOT}/Map.hpp
    ${SRCROOT}/Map.cpp
    ${INCROOT}/Display.hpp
    ${SRCROOT}/Display.cpp
)
add_library(src STATIC ${SRC})
target_link_libraries(src PRIVATE raylib)
target_include_directories(src PUBLIC ${INCROOT})
