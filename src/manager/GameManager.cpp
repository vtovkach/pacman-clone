#include "include/manager/GameManager.hpp"
#include "include/scenes/GameScene.hpp"

#include <QObject>
#include <QApplication>
#include <iostream>
#include <utility>

constexpr int FRAME_WIDTH = 784; 
constexpr int FRAME_HEIGHT = 868;

constexpr int PACMAN_SPEED = 10;
constexpr std::pair<int, int> PACMAN_INIT_GRID_CORD = {3, 3};
constexpr std::pair<int, int> PACMAN_INIT_PIXEL_CORD = {100, 100};

GameManager::GameManager() : gameMap(MAP_PATH), 
    pacman(PACMAN_SPEED, PACMAN_INIT_GRID_CORD, PACMAN_INIT_PIXEL_CORD)
{
    // Create MenuScene
    this->highScore = 0;
    this->curScore = 0; 
    openMenuScene();
}

void GameManager::runPacMan()
{
    currentScene->show();
}

void GameManager::openMenuScene()
{
    currentScene = std::make_unique<MenuScene>("Pac-Man Menu", FRAME_WIDTH, FRAME_HEIGHT, nullptr);
    QObject::connect(currentScene.get(), &MenuScene::exitGame, [this]() {closeGame();});
    QObject::connect(currentScene.get(), &MenuScene::openGameScene, [this](){openGameScene();});
}

void GameManager::openGameScene()
{
    // close old scene 
    currentScene->close();
    // define new scene 
    currentScene = std::make_unique<GameScene>("Pac-Man Game", FRAME_WIDTH, FRAME_HEIGHT, nullptr, curScore, highScore, gameMap, pacman);
    
    // display the scene 
    currentScene->show();
}

void GameManager::closeGame()
{
    currentScene->close();
}