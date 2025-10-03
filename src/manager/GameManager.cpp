#include "include/manager/GameManager.hpp"
#include <QObject>
#include <QApplication>
#include <iostream>

constexpr int FRAME_WIDTH = 784; 
constexpr int FRAME_HEIGHT = 868;

GameManager::GameManager()
{
    // Create MenuScene 
    currentScene = std::make_unique<MenuScene>("Pac-Man Menu", FRAME_WIDTH, FRAME_HEIGHT, nullptr);

    // Connect current scene to signals  
    QObject::connect(currentScene.get(), &MenuScene::exitGame, [this]() { closeGame(); });
}

void GameManager::runPacMan()
{
    currentScene->show();
}

void GameManager::closeGame()
{
    currentScene->close();
}

void GameManager::changeScene()
{
    // Change Scene Logic 
    // 
}