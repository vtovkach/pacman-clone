#pragma once 

#include "include/entities/Entity.hpp"

class PacMan : public Entity
{
public:
    PacMan();
    
private: 
    std::vector<QPixmap> pacmanDown;
    std::vector<QPixmap> pacmanUp;
    std::vector<QPixmap> pacmanLeft;
    std::vector<QPixmap> pacmanRight;
};