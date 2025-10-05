#pragma once 

#include <memory>

#include "include/scenes/Scene.hpp"
#include "include/scenes/MenuScene.hpp"
#include "include/scenes/GameScene.hpp"

class GameManager
{
public:
    GameManager();

    void runPacMan();

    void openMenuScene();

    void openGameScene();

    void closeGame();
    
private:
    std::unique_ptr<Scene> currentScene;

    int curScore;
    int highScore;
};