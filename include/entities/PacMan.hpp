#pragma once 

#include "include/entities/Entity.hpp"

namespace PacmanAssets 
{
    inline constexpr const char* DOWN[]  = {"assets/pacman-down/1.png",  "assets/pacman-down/2.png",  "assets/pacman-down/3.png"};
    inline constexpr const char* UP[]    = {"assets/pacman-up/1.png",    "assets/pacman-up/2.png",    "assets/pacman-up/3.png"};
    inline constexpr const char* LEFT[]  = {"assets/pacman-left/1.png",  "assets/pacman-left/2.png",  "assets/pacman-left/3.png"};
    inline constexpr const char* RIGHT[] = {"assets/pacman-right/1.png", "assets/pacman-right/2.png", "assets/pacman-right/3.png"};
}

class PacMan : public Entity
{
public:
    PacMan(int speed, std::pair<int, int> gridCord, std::pair<int, int> pixelCord);

    void movePacman();
    
private: 
    std::vector<QPixmap> pacmanDown;
    std::vector<QPixmap> pacmanUp;
    std::vector<QPixmap> pacmanLeft;
    std::vector<QPixmap> pacmanRight;
};