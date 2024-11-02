/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#include <iostream>
#include "Map.hpp"
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
            void displayApple();
            void displayScore();
            void displayGameOver();
            void displayPause();
            void displayMenu();
            void displaySettings();
            void displayBackground();

            void setScreenWidth(float screen_width);
            void setScreenHeight(float screen_height);
            float getScreenWidth();
            float getScreenHeight();
        private:
            float _screen_width;
            float _screen_height;
            Snake::Map _map;
            Texture2D _backg;
    };
}