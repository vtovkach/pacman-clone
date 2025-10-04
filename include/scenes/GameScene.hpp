#pragma once 

#include "include/scenes/Scene.hpp"
#include "include/maps/Map.hpp"

class GameScene : public Scene
{
public:
    GameScene(const std::string& sceneName, int width, int height, QWidget* parent = nullptr);
    
    void paintEvent(QPaintEvent *event) override;

private:
    // Game objects 

    Map gameMap;
};