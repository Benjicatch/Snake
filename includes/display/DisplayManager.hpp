/*
** CCU, 2024
** Player.hpp
** File description:
** Player
*/

#pragma once
#include <iostream>
#include "Menu.hpp"
#include "Restart.hpp"
#include "SettingsView.hpp"
#include "PauseView.hpp"
#include "GameView.hpp"
#include "raylib.h"

namespace Snake {

    #define FPS 60
    #define TIMER 10

    class DisplayManager : public AViewDisplay {
        public:
            DisplayManager(int x, int y);
            ~DisplayManager();
            void display();
            void displayGameOver();
            void displayPause();
            void displayBackground();
            void chooseDisplay();
        private:
            int _timer;
            std::unique_ptr<Pause> _pause;
            std::unique_ptr<SettingsView> _settings;
            std::unique_ptr<Menu> _menu;
            std::unique_ptr<Restart> _restart;
            std::unique_ptr<PauseView> _pauseView;
            std::unique_ptr<GameView> _gameView;
            std::deque<Direction> _directions = { Direction::LEFT };
    };
}
