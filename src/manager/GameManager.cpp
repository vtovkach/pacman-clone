#include "include/manager/GameManager.hpp"

constexpr int FRAME_WIDTH = 784; 
constexpr int FRAME_HEIGHT = 868;

GameManager::GameManager()
{
    currentScene = std::make_unique<MenuScene>("Pac-Man Menu", FRAME_WIDTH, FRAME_HEIGHT, nullptr);
}

void GameManager::runPacMan()
{
    currentScene->show();
}

void GameManager::changeScene()
{
    // ... 
}