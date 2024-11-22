/*
** CCU, 2024
** Back.hpp
** File description:
** Back
*/

#pragma once
#include "ADisplay.hpp"

namespace Snake {
    class Back : public ADisplay {
        public:
            Back(std::pair<float&, float&> &window, Status &status);
            ~Back();
            void display() override;
            void displayAndCheckButton() override;
    };
}
