#include <iostream>
#include <QApplication>

#include "include/manager/GameManager.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameManager pacMan; // run the game 

    pacMan.runPacMan();
    
    return app.exec();
}