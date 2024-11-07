/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#pragma once
#include <iostream>
#include "Map.hpp"
#include "Apple.hpp"
#include "raylib.h"

namespace Snake {

    class Display
    {
        public:
            Display();
            ~Display();
            void display();
            void displayMap();
            void displaySnake();
            void displayScore();
            void displayGameOver();
            void displayPause();
            void displayMenu();
            void displaySettings();
            void displayBackground();
            void displayGrass(Rectangle destRect);

            void setScreenWidth(float screen_width);
            void setScreenHeight(float screen_height);
            float getScreenWidth();
            float getScreenHeight();
        private:
            float _screen_width;
            float _screen_height;
            std::shared_ptr<Map> _map;
            Texture2D _backg;
            Texture2D _grass;
            Rectangle _window_map;
    };
}
