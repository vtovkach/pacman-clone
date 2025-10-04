#include "include/scenes/GameScene.hpp"
#include "QPainter"
#include <QPaintEvent>
#include <QPixmap>
#include <QPen>
#include <QColor>

GameScene::GameScene(const std::string& sceneName, int width, int height, QWidget* parent) : Scene(sceneName, width, height, parent), gameMap("assets/maps/level1.map")
{
    // TODO 
    // ... 
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