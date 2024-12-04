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
#include "AViewDisplay.hpp"

namespace Snake {
    class Menu : public AViewDisplay {
        public:
            Menu(AViewDisplay &view);
            ~Menu();
            void display() override;
        private:
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Play> _play;
    };
}
