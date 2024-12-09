/*
** CCU, 2024
** Restart.hpp
** File description:
** Restart
*/

#pragma once
#include "AObjectDisplay.hpp"

namespace Snake {
    class Restart : public AObjectDisplay {
        public:
            Restart(AViewDisplay &view);
            ~Restart();
            void display() override;
            bool displayAndCheckButton() override;
    };
}
