#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <memory>

#include "include/entities/Entity.hpp"
#include "include/entities/PacMan.hpp"
#include "include/entities/Pellet.hpp"
#include "include/entities/ghosts/Ghost.hpp"
#include "include/entities/ghosts/Blinky.hpp"
#include "include/entities/ghosts/Clyde.hpp"
#include "include/entities/ghosts/Inky.hpp"
#include "include/entities/ghosts/Pinky.hpp"

// Origin point of the pacman map  
constexpr std::pair<int, int> ORIGIN_POINT = {20, 20};
// Tile size in pixels 
constexpr int TILE_SIZE = 24; 

// Map grid dimensions 
constexpr int GRID_W = 28;
constexpr int GRID_H = 30;


struct Node
{
    bool isWall; 
    bool isSpace; 
    std::pair<int, int> gridCordinate;
    std::pair<int,int> pixelCordinate; 
    std::vector<Node*> neighbors;
};


class Map
{
public:
    Map(const std::string& mapFilePath);
    // Public interface  
    // ... 

    const std::vector<std::unique_ptr<Node>>& getGraph()
    {
        return gameMapGraph;
    }

private:
    std::vector<std::unique_ptr<Node>> gameMapGraph;

};