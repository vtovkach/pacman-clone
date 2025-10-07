#include "include/maps/Map.hpp"


// Helper function to get index of tile in graph vector 
namespace {
    int index(int x, int y)
    {
        return y * GRID_W + x;
    }
}


Map::Map(const std::string& mapFilePath) 
{
    // Open map file 
    std::ifstream file(mapFilePath);

    if(!file)
    {
        throw std::runtime_error("Could not open map file: " + mapFilePath);
    }

    // Reserve space for a vector in advance 
    gameMapGraph.reserve(GRID_H * GRID_W);


    // Establish gameMapGraph 
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
    for(int y = 0; y < GRID_H; y++)
    {
        for(int x = 0; x < GRID_W; x++)
        {
            int idx = index(x, y);
            if(!gameMapGraph.at(idx)->isWall)
            {
                // Right neighbor
                if (x < GRID_W - 1) 
                {
                    int rightIdx = index(x + 1, y);
                    if (gameMapGraph.at(rightIdx)->isSpace) 
                    {
                        gameMapGraph.at(idx)->neighbors.push_back(gameMapGraph.at(rightIdx).get());
                    }
                }

                // Left neighbor
                if (x > 0) 
                {
                    int leftIdx = index(x - 1, y);
                    if (gameMapGraph.at(leftIdx)->isSpace) 
                    {
                        gameMapGraph.at(idx)->neighbors.push_back(gameMapGraph.at(leftIdx).get());
                    }
                }

                // Down neighbor
                if (y < GRID_H - 1) 
                {
                    int downIdx = index(x, y + 1);
                    if (gameMapGraph.at(downIdx)->isSpace) 
                    {
                        gameMapGraph.at(idx)->neighbors.push_back(gameMapGraph.at(downIdx).get());
                    }
                }

                // Up neighbor
                if (y > 0) 
                {
                    int upIdx = index(x, y - 1);
                    if (gameMapGraph.at(upIdx)->isSpace) 
                    {
                        gameMapGraph.at(idx)->neighbors.push_back(gameMapGraph.at(upIdx).get());
                    }
                }
            }
        }
    }
}

std::pair<int, int> Map::gridToPixel(int gridX, int gridY) 
{
    return {gridX * TILE_SIZE + ORIGIN_POINT.first, gridY * TILE_SIZE + ORIGIN_POINT.second};
}

std::pair<int, int> Map::pixelToGrid(int pixelX, int pixelY) 
{
    return {pixelX / TILE_SIZE, pixelY / TILE_SIZE};
}