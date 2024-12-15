/*
** CCU, 2024
** PauseView.hpp
** File description:
** PauseView
*/

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Settings.hpp"
#include "Play.hpp"
#include "Back.hpp"
#include "raylib.h"
#include "AViewDisplay.hpp"

namespace Snake {
    class PauseView : public AViewDisplay {
        public:
            PauseView(AViewDisplay &view);
            ~PauseView();
            void display() override;
        private:
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Play> _play;
            std::unique_ptr<Back> _back;
    };
}
