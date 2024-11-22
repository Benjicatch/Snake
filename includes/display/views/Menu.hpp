/*
** CCU, 2024
** Menu.hpp
** File description:
** Menu
*/

#pragma once
#include <iostream>
#include <memory>
#include "Settings.hpp"
#include "Play.hpp"
#include "raylib.h"

namespace Snake {
    class Menu {
        public:
            Menu(std::pair<float&, float&> &window, Status &status);
            ~Menu();
            void display();
        private:
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Play> _play;
    };
}
