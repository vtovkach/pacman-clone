#pragma once 

#include "include/entities/PacMan.hpp"
#include "include/scenes/Scene.hpp"
#include "include/maps/Map.hpp"
#include <QLabel>

class GameScene : public Scene
{
public:
    GameScene(const std::string& sceneName, int width, int height, QWidget* parent, int& curScore, int& highScore, Map& gameMap, PacMan& pacman);
    
    void paintEvent(QPaintEvent *event) override;

private:
    // References to game objects 
    Map& gameMap;
    PacMan& pacman;
    
    QLabel *highestScoreLabel;
    QLabel *highestScoreNum;
    QLabel *currentScoreLabel;
    QLabel *currentScoreNum;
    std::vector<QLabel*> lifes; 
    
    int& curScore;
    int& highScore;  
};