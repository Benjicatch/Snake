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
#include "GameOverView.hpp"
#include "WinningView.hpp"
#include "raylib.h"

namespace Snake {

    #define FPS 60
    #define TIMER 10

    class DisplayManager : public AViewDisplay {
        public:
            DisplayManager();
            ~DisplayManager();
            void display();
            void displayBackground();
            void chooseDisplay();
        private:
            std::unique_ptr<SettingsView> _settings;
            std::unique_ptr<Menu> _menu;
            std::unique_ptr<Restart> _restart;
            std::unique_ptr<PauseView> _pauseView;
            std::unique_ptr<GameView> _gameView;
            std::unique_ptr<GameOverView> _gameOverView;
            std::unique_ptr<WinningView> _winningView;
    };
}
