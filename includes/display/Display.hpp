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
#include "Settings.hpp"
#include "Play.hpp"
#include "raylib.h"

namespace Snake {

    #define FPS 60
    #define TIMER 20

    class Display
    {
        public:
            Display(int x, int y);
            ~Display();
            void display();
            void displayMap();
            void displayScore();
            void displayGameOver();
            void displayPause();
            void displayMenu();
            void displaySettings();
            void displayGame();
            void displayBackground();
            void displayGrass(Rectangle destRect);
            void setScreenWidth(float screen_width);
            void setScreenHeight(float screen_height);
            void handleEvent();
            void getEvent();
            void chooseDisplay();
        private:
            int _timer;
            float _screen_width;
            float _screen_height;
            std::shared_ptr<Map> _map;
            Vector2 _mousePoint = { 0.0f, 0.0f };
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Play> _play;
            Texture2D _backg;
            Texture2D _grass;
            Rectangle _window_map;
            Direction _last_direction = Snake::Direction::LEFT;
            Status _status = Snake::Status::MENU;
    };
}
