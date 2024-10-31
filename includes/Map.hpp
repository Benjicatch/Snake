/*
** CCU, 2024
** Map.hpp
** File description:
** Map
*/

class Map
{
    public:
        Map(int x, int y);
        ~Map();
        void resize(int x, int y);

    private:
        int _x;
        int _y;
};
