/*
** CCU, 2024
** Settings.hpp
** File description:
** Settings
*/

#pragma once
#include "ADisplay.hpp"

namespace Snake {
    class Settings : public ADisplay {
        public:
            Settings(std::pair<float&, float&> &window);
            ~Settings();
            void display() override;
    };
}
