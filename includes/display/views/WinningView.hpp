/*
** CCU, 2024
** WinningView.hpp
** File description:
** WinningView
*/

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Settings.hpp"
#include "Restart.hpp"
#include "Back.hpp"
#include "raylib.h"
#include "AViewDisplay.hpp"

namespace Snake {
    class WinningView : public AViewDisplay {
        public:
            WinningView(AViewDisplay &view);
            ~WinningView();
            void display() override;
        private:
            std::unique_ptr<Settings> _settings;
            std::unique_ptr<Restart> _restart;
            std::unique_ptr<Back> _back;
    };
}
