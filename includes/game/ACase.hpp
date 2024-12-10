/*
** CCU, 2024
** Map.hpp
** File description:
** Map
*/

#pragma once
#include "ICase.hpp"

namespace Snake {

    class ACase : public ICase
    {
        public:
            ~ACase();
            void setPosition(std::pair<int, int> position);
            const std::pair<int, int> getPosition() const;
            void displayObject(Rectangle destRect);
            void display(Rectangle _window_map, std::pair<int, int> sizeMap);
            CaseType getType() const;
        protected:
            std::pair<int, int> _position;
            Texture2D _object;
            CaseType _type = CaseType::EMPTY;
    };
}
