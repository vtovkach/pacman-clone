#pragma once 

#include <QPushButton>
#include <QLabel>
#include <string>
#include <vector>
#include <utility>

#include "scenes/Scene.hpp"

class MenuScene : public Scene
{
public:
    MenuScene(std::string sceneName, int width, int height, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::pair<int, int>> menuSceneStars; 
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel      *gameTitle;
};