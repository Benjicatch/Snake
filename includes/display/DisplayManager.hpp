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
#include "Restart.hpp"
#include "SettingsView.hpp"
#include "raylib.h"

namespace Snake {

    #define FPS 60
    #define TIMER 10

    class DisplayManager : public AViewDisplay {
        public:
            DisplayManager(int x, int y);
            ~DisplayManager();
            void display();
            void displayMap();
            void displayScore();
            void displayGameOver();
            void displayPause();
            void displayGame();
            void displayBackground();
            void displayGrass(Rectangle destRect);
            void handleEvent();
            void getEvent();
            void chooseDisplay();
        private:
            int _timer;
            std::shared_ptr<Map> _map;
            std::unique_ptr<Pause> _pause;
            std::unique_ptr<SettingsView> _settings;
            std::unique_ptr<Menu> _menu;
            std::unique_ptr<Restart> _restart;
            Texture2D _grass;
            std::deque<Direction> _directions = { Direction::LEFT };
    };
}
