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
#include "InputBox.hpp"
#include "raylib.h"

namespace Snake {
    class SettingsView: public AViewDisplay {
        public:
            SettingsView(AViewDisplay &view);
            ~SettingsView();
            void display();
        private:
            std::unique_ptr<Back> _back;
            std::unique_ptr<InputBox> _width;
            std::unique_ptr<InputBox> _height;
            bool _goBack = false;
    };
}
