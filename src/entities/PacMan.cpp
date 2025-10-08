#include "include/entities/PacMan.hpp"


// Use parent's pixmap as the active one that will be used in drawing on the screen 

PacMan::PacMan(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord) : Entity(speed, gridCord, pixelCord)
{
    // Load Down 
    for(auto& asset : PacmanAssets::DOWN)
    {
        QPixmap pacmanPixMap(asset);
        pacmanPixMap = pacmanPixMap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->pacmanDown.push_back(pacmanPixMap);
    }
    
    // Load Up
    for(auto& asset : PacmanAssets::UP)
    {
        QPixmap pacmanPixMap(asset);
        pacmanPixMap = pacmanPixMap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->pacmanUp.push_back(pacmanPixMap);
    }

    // Load Left 
    for(auto& asset : PacmanAssets::LEFT)
    {
        QPixmap pacmanPixMap(asset);
        pacmanPixMap = pacmanPixMap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->pacmanLeft.push_back(pacmanPixMap);
    }

    // Load Right
    for(auto& asset : PacmanAssets::RIGHT)
    {
        QPixmap pacmanPixMap(asset);
        pacmanPixMap = pacmanPixMap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->pacmanRight.push_back(pacmanPixMap);
    }

    // Load left pacman into active pixmap 
    activePixmap = pacmanLeft[0];

    direction = Direction::Left;
}

void PacMan::movePacman()
{
    if(direction == Direction::Left)
    {
        pixelCord.first -= speed;
    }
}