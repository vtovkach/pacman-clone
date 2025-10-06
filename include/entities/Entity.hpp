#pragma once 

#include <utility>
#include <QPixmap>

class Entity 
{
public:
    Entity(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord);

protected:

    enum class Direction
    {
        Up,
        Down,
        Left,
        Right
    };

    int speed;
    Direction direction; 
    std::pair<int, int> gridCord; 
    std::pair<int, int> pixelCord; 
    QPixmap pixmap;
};