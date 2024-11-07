/*
** CCU, 2024
** Empty.cpp
** File description:
** Empty
*/
#include "Empty.hpp"

Snake::Empty::Empty()
{
    _type = CaseType::EMPTY;
}

Snake::Empty::~Empty()
{
}

void Snake::Empty::display(Rectangle _window_map, std::pair<int, int> sizeMap)
{
}
