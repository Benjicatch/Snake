set(INCROOT ${CMAKE_SOURCE_DIR}/includes/display/views)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/display/views)
set(SRC
    ${INCROOT}/Menu.hpp
    ${SRCROOT}/Menu.cpp
    ${INCROOT}/SettingsView.hpp
    ${SRCROOT}/SettingsView.cpp
    ${INCROOT}/PauseView.hpp
    ${SRCROOT}/PauseView.cpp
    ${INCROOT}/GameView.hpp
    ${SRCROOT}/GameView.cpp
    ${INCROOT}/GameOverView.hpp
    ${SRCROOT}/GameOverView.cpp
)
add_library(views STATIC ${SRC})
target_link_libraries(views PRIVATE raylib map player)
target_include_directories(views PUBLIC
    ${INCROOT}
    ${CMAKE_SOURCE_DIR}/includes/
)
target_link_libraries(views PRIVATE
    textures)
