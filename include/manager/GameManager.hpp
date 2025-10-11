#pragma once 

#include <memory>

#include "include/maps/Map.hpp"
#include "include/scenes/Scene.hpp"
#include "include/scenes/MenuScene.hpp"
#include "include/scenes/GameScene.hpp"
#include "include/entities/PacMan.hpp"

#include <Qt>

constexpr const char* MAP_PATH = "assets/maps/level1.map";

class GameManager
{
public:
    GameManager();

    void runPacMan();

    void openMenuScene();

    void openGameScene();

    void closeGame();

    void updateGame();
    
    void handleKeyInput(int keyCode);
    
private:

    std::unique_ptr<Scene> currentScene;

    Map gameMap;
    PacMan pacman;

    int curScore;
    int highScore;
};