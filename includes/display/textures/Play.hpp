/*
** CCU, 2024
** Play.hpp
** File description:
** Play
*/

#pragma once
#include "AObjectDisplay.hpp"

namespace Snake {
    class Play : public AObjectDisplay {
        public:
            Play(AViewDisplay &view);
            ~Play();
            void display() override;
            void displayAndCheckButton() override;
    };
}
