#include "include/maps/Map.hpp"


// Helper function to get index of tile in graph vector 
namespace {
    int index(int x, int y)
    {
        return y * GRID_W + x;
    }
}


    std::ifstream file(mapFilePath);

    if(!file)
    {
        throw std::runtime_error("Could not open map file: " + mapFilePath);
    }

    std::string line;
    int y_grid = 0;
    while(std::getline(file, line) && y_grid < GRID_H)
    {
        int x_grid = 0;
        for(char ch : line)
        {
            auto newNode = std::make_unique<Node>();
            if(ch == '#')
            {
                newNode->isWall = true; 
                newNode->isSpace = false;
            }
            else
            {
                newNode->isSpace = true; 
                newNode->isWall = false; 
            }

            // Assign cordinates 
            newNode->gridCordinate = {x_grid, y_grid};
            newNode->pixelCordinate = {ORIGIN_POINT.first + (TILE_SIZE * x_grid), ORIGIN_POINT.second + (TILE_SIZE * y_grid)};

            // Push new node to the graph 
            gameMapGraph.push_back(std::move(newNode));
            x_grid++;
        }
        y_grid++;
    }

    // Establish neigbours 
    for(int x = 0; x < GRID_W; x++)
    {
        for(int y = 0; y < GRID_H; y++)
        {
            
        }
    }
}