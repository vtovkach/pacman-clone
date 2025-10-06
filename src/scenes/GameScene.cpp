#include "include/scenes/GameScene.hpp"
#include "QPainter"
#include <QPaintEvent>
#include <QPixmap>
#include <QPen>
#include <QColor>
#include <QHBoxLayout>
#include <QVBoxLayout>


constexpr const char* MAP_PATH = "assets/maps/level1.map";

GameScene::GameScene(const std::string& sceneName, int width, int height, QWidget* parent, int& curScore, int& highScore) : Scene(sceneName, width, height, parent), gameMap(MAP_PATH), curScore(curScore), highScore(highScore)
{
    // Set up lifes labels 
    int initX = 20;
    int initY = 35;
    for(int i = 0; i < 3; i++)
    {
        QLabel *life = new QLabel(this);
        life->setPixmap(QPixmap("assets/pacman-left/1.png"));
        life->setScaledContents(true);
        life->setFixedSize(32, 32);
        life->move(initX, initY);
        initX += 40;
    }

    // Set up highest score  
    highestScoreLabel = new QLabel("High Score:", this);
    highestScoreNum = new QLabel("0", this);
    highestScoreLabel->setStyleSheet("color: white; font-size: 25px;");
    highestScoreNum->setStyleSheet("color: white; font-size: 25px;");
    highestScoreLabel->move(285, 40);
    highestScoreNum->move(430, 40);

    // Setup current score 
    currentScoreLabel = new QLabel("Score:", this);
    currentScoreNum = new QLabel("0", this);
    currentScoreLabel->setStyleSheet("color: white; font-size: 25px;");
    currentScoreNum->setStyleSheet("color: white; font-size: 25px;");
    currentScoreLabel->move(600, 40);
    currentScoreNum->move(680, 40);
}

void GameScene::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPen wallPen(Qt::blue);

    wallPen.setWidth(1);
    painter.setPen(wallPen);
    painter.setBrush(Qt::NoBrush);

    // Retrieve map graph 
    const std::vector<std::unique_ptr<Node>>& mapGraph = this->gameMap.getGraph();
    
    for(auto& node : mapGraph)
    {
        if(node.get()->isWall)
        {
            painter.drawRect(node.get()->pixelCordinate.first, node.get()->pixelCordinate.second, TILE_SIZE - 12, TILE_SIZE - 12);
        }
    }
}