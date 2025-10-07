#pragma once 

#include <utility>
#include <QPixmap>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Entity 
{
public:
    Entity(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord);

    Direction getDirection(){
        return this->direction;
    }

    std::pair<int, int> getGridCord(){
        return this->gridCord;
    }

    std::pair<int, int> getPixelCord(){
        return this->pixelCord;
    }

    QPixmap getActivePixMap(){
        return this->activePixmap;
    }
    
protected:
    int speed;
    Direction direction; 
    std::pair<int, int> gridCord; 
    std::pair<int, int> pixelCord; 
    QPixmap activePixmap;
};