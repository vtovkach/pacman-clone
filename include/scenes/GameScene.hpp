#pragma once 

#include "include/scenes/Scene.hpp"

class GameScene : public Scene
{
public:
    GameScene(const std::string& sceneName, int width, int height, QWidget* parent = nullptr);
    
private:
    // Game Objects are going to be here 
    
};