#pragma once 

#include "include/entities/Entity.hpp"

class PacMan : public Entity
{
public:
    PacMan(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord);
    
private: 
    std::vector<QPixmap> pacmanDown;
    std::vector<QPixmap> pacmanUp;
    std::vector<QPixmap> pacmanLeft;
    std::vector<QPixmap> pacmanRight;
};