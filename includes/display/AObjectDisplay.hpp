/*
** CCU, 2024
** AObjectDisplay.hpp
** File description:
** AObjectDisplay
*/

#pragma once
#include "raylib.h"
#include <iostream>
#include "IViewDisplay.hpp"
#include "IObjectDisplay.hpp"
#include "AViewDisplay.hpp"

namespace Snake {
    class AObjectDisplay: public IObjectDisplay, public AViewDisplay {
        public:
            AObjectDisplay(AViewDisplay &view);
            ~AObjectDisplay() = default;
            virtual void display() = 0;
            MouseState isMouseOverButtonClicked();
            void displayObject(Rectangle destRect);
            virtual void displayAndCheckButton() = 0;
        protected:
            Texture2D _object;
            Vector2 _mousePoint;
            Rectangle _btnBounds;
    };
}
