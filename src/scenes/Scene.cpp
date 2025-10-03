#include "scenes/Scene.hpp"

Scene::Scene(const std::string& sceneName, int width, int height, QWidget* parent) : QWidget(parent), sceneName(sceneName)
{
    setWindowTitle(QString::fromStdString(sceneName));
    setFixedSize(width, height);
    setStyleSheet("background-color: black");
}