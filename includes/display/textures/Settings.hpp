/*
** CCU, 2024
** Settings.hpp
** File description:
** Settings
*/

#pragma once
#include "AObjectDisplay.hpp"

namespace Snake {
    class Settings : public AObjectDisplay {
        public:
            Settings(AViewDisplay &view);
            ~Settings();
            void display() override;
            bool displayAndCheckButton() override;
    };
}
