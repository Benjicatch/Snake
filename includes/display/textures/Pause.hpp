/*
** CCU, 2024
** Pause.hpp
** File description:
** Pause
*/

#pragma once
#include "AObjectDisplay.hpp"

namespace Snake {
    class Pause : public AObjectDisplay {
        public:
            Pause(AViewDisplay &view);
            ~Pause();
            void display() override;
            bool displayAndCheckButton() override;
    };
}
