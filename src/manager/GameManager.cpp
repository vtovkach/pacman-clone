#include "include/manager/GameManager.hpp"
#include "include/scenes/GameScene.hpp"

#include <QObject>
#include <QApplication>
#include <iostream>

constexpr int FRAME_WIDTH = 784; 
constexpr int FRAME_HEIGHT = 868;

GameManager::GameManager()
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
    currentScene = std::make_unique<GameScene>("Pac-Man Game", FRAME_WIDTH, FRAME_HEIGHT, nullptr, curScore, highScore);
    
    // display the scene 
    currentScene->show();
}

void GameManager::closeGame()
{
    currentScene->close();
}