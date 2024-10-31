set(INCROOT ${CMAKE_SOURCE_DIR}/includes/)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/)
set(SRC
    ${INCROOT}/Map.hpp
    ${SRCROOT}/Map.cpp
)
add_library(map STATIC ${SRC})
target_include_directories(map PUBLIC ${INCROOT})
