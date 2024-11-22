/*
** CCU, 2024
** SettingsView.hpp
** File description:
** SettingsView
*/

#pragma once
#include <iostream>
#include <memory>
#include "Back.hpp"
#include "raylib.h"

namespace Snake {
    class SettingsView {
        public:
            SettingsView(std::pair<float&, float&> &window, Status &status);
            ~SettingsView();
            void display();
        private:
            std::unique_ptr<Back> _back;
            std::pair<float&, float&> _window;
    };
}
