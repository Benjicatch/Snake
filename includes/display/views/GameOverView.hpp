/*
** CCU, 2024
** GameOverView.hpp
** File description:
** GameOverView
*/

#pragma once
#include <iostream>
#include <memory>
#include "Settings.hpp"
#include "Restart.hpp"
#include "Back.hpp"
#include "raylib.h"
#include "AViewDisplay.hpp"

namespace Snake {
    class GameOverView : public AViewDisplay {
        public:
            GameOverView(AViewDisplay &view);
            ~GameOverView();
            void display() override;
        private:
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Restart> _restart;
            std::unique_ptr<Back> _back;
    };
}
