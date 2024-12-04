/*
** CCU, 2024
** AViewDisplay.hpp
** File description:
** AViewDisplay
*/

#pragma once
#include "raylib.h"
#include "Map.hpp"
#include "IViewDisplay.hpp"
#include <iostream>

namespace Snake {

    class AViewDisplay : public IViewDisplay {
        public:
            AViewDisplay(Status status);
            AViewDisplay(AViewDisplay &view);
            ~AViewDisplay() = default;
            virtual void display() = 0;
            const std::shared_ptr<Status> &getStatus() const;
            void setStatus(const Status &status);
            const std::shared_ptr<Map> &getMap() const { return _map; }
            const Rectangle &getWindowMap() const { return _window_map; }
            const std::shared_ptr<std::pair<float, float>> &getWindow() const { return _window; }
            void setMap(const std::shared_ptr<Map> &map) { _map = map; }
            void setWindowMap(const Rectangle &window_map) { _window_map = window_map; }
        protected:
            std::shared_ptr<std::pair<float, float>> _window;
            std::shared_ptr<Status> _status;
            Rectangle _window_map;
            std::shared_ptr<Map> _map;
            Texture2D _backg;
    };
}
