/*
** CCU, 2024
** main.cpp
** File description:
** main
*/

#include "raylib.h"
#include "Display.hpp"

int main(void)
{
    Snake::Display display;

    try {
        display.display();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
