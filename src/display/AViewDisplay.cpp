/*
** CCU, 2024
** AViewDisplay.cpp
** File description:
** AViewDisplay
*/

#include "AViewDisplay.hpp"

Snake::AViewDisplay::AViewDisplay(Status status)
{
    _window = std::make_shared<std::pair<float, float>>(std::pair<float, float>(800, 450));
    _status = std::make_shared<Status>(status);
    _mousePoint = std::make_shared<Vector2>(Vector2{0.0f, 0.0f});
}

Snake::AViewDisplay::AViewDisplay(Snake::AViewDisplay &view) : _window(view._window), _status(view._status), _window_map(view._window_map), _object(view._object), _mousePoint(view._mousePoint), _map(view._map), _backg(view._backg)
{
}

const std::shared_ptr<Snake::Status> &Snake::AViewDisplay::getStatus() const
{
    return _status;
}

void Snake::AViewDisplay::setStatus(const Status &status)
{
    *_status = status;
}
