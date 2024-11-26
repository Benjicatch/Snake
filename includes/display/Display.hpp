/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#pragma once
#include <iostream>
#include <algorithm>
#include "Map.hpp"
#include "Apple.hpp"
#include "Settings.hpp"
#include "Play.hpp"
#include "Pause.hpp"
#include "Back.hpp"
#include "Menu.hpp"
#include "SettingsView.hpp"
#include "raylib.h"

namespace Snake {

    #define FPS 60
    #define TIMER 20

    class Display {
        public:
            Display(int x, int y);
            ~Display();
            void display();
            void displayMap();
            void displayScore();
            void displayGameOver();
            void displayPause();
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
            std::unique_ptr<Pause> _pause;
            std::unique_ptr<SettingsView> _settings;
            std::unique_ptr<Menu> _menu;
            Texture2D _backg;
            Texture2D _grass;
            Rectangle _window_map;
            std::deque<Direction> _last_direction = { Direction::LEFT };
            Status _status = Snake::Status::MENU;
    };
}
