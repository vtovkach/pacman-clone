#include "include/entities/Entity.hpp"


Entity::Entity(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord) : direction(Direction::Left) 
{  
    this->speed = speed;
    this->gridCord = gridCord;
    this->pixelCord = pixelCord;
}