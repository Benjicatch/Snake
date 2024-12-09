/*
** CCU, 2024
** Back.hpp
** File description:
** Back
*/

#pragma once
#include "AObjectDisplay.hpp"

namespace Snake {
    class Back : public AObjectDisplay {
        public:
            Back(AViewDisplay &view);
            ~Back();
            void display() override;
            bool displayAndCheckButton() override;
    };
}
