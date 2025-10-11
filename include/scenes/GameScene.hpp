#pragma once 

#include "include/entities/PacMan.hpp"
#include "include/scenes/Scene.hpp"
#include "include/maps/Map.hpp"
#include <QLabel>
#include <QTimer>
#include <QKeyEvent>

constexpr int TIMER_TIME = 100;

class GameScene : public Scene
{
    Q_OBJECT
public:
    GameScene(const std::string& sceneName, int width, int height, QWidget* parent, int& curScore, int& highScore, Map& gameMap, PacMan& pacman);
    
    void paintEvent(QPaintEvent *event) override;

signals:
    void timerTick();

    void keyPressed(int inputChar);

private:
    
    void keyReleaseEvent(QKeyEvent *event) override;

    // Timer for screen refresh 
    QTimer *timer; 

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