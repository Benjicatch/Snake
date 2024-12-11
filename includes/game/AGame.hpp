/*
** CCU, 2024
** AGame.hpp
** File description:
** AGame
*/

#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <raylib.h>
#include "IGame.hpp"
#include "ICase.hpp"

namespace Snake {

    class AGame : public IGame {
        public:
            AGame();
            AGame(const AGame &other);
            ~AGame();
        
            const int& getScore() const;
            void setScore(int score);
        
            const bool& getWin() const;
            void setWin(bool win);
        
            const std::shared_ptr<Mode> getMode() const;
            void setMode(Mode mode);
        
            const std::vector<std::vector<std::shared_ptr<ICase>>>& getMap() const;
            void setMap(int x, int y, std::shared_ptr<ICase> map);
            const std::shared_ptr<std::pair<int, int>> getSizeMap() const;
            void setSizeMap(int x, int y);
        private:
            int _score = 0;
            bool _win = false;
            std::shared_ptr<Mode> _mode;
            std::shared_ptr<std::pair<int, int>> _size_map;
            std::vector<std::vector<std::shared_ptr<ICase>>> _map;
    };
}
