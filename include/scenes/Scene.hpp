#pragma once

#include <QWidget>
#include <QString>
#include <string>

class Scene : public QWidget
{
    Q_OBJECT
public:
    Scene(const std::string& sceneName, int width, int height, QWidget* parent = nullptr);

protected:
    std::string sceneName;
    
signals:
    void exitGame();

    void openGameScene();
};