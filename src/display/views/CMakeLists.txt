set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display/views)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display/views)
set(SRC
    ${INCROOT}/Menu.hpp
    ${SRCROOT}/Menu.cpp
    ${INCROOT}/SettingsView.hpp
    ${SRCROOT}/SettingsView.cpp
)
add_library(views STATIC ${SRC})
target_link_libraries(views PRIVATE raylib)
target_include_directories(views PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
)
target_link_libraries(views PRIVATE
    textures)
