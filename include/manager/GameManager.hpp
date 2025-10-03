#pragma once 

#include <memory>

#include "include/scenes/Scene.hpp"
#include "include/scenes/MenuScene.hpp"
#include "include/scenes/GameScene.hpp"

class GameManager
{
public:
    GameManager();

    void changeScene();

    void runPacMan();

private:
    std::unique_ptr<Scene> currentScene;
};