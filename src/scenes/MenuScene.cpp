#include "scenes/MenuScene.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

constexpr int BUTTON_WIDTH = 370;
constexpr int BUTTON_HEIGHT = 150;
constexpr int LABEL_FONT_SIZE = 115;
constexpr int BUTTON_FONT_SIZE = 50; 

MenuScene::MenuScene(std::string sceneName, int width, int height, QWidget *parent) : Scene(sceneName, width, height, parent)
{
    // Title label
    gameTitle = new QLabel("PAC-MAN", this);
    gameTitle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QFont titleFont("Tangerine", LABEL_FONT_SIZE, QFont::Bold);
    gameTitle->setFont(titleFont);
    gameTitle->setAlignment(Qt::AlignCenter);
    gameTitle->setStyleSheet("background-color: black; color: yellow;");

    // Buttons
    startButton = new QPushButton("Start Game", this);
    exitButton  = new QPushButton("Exit Game", this);

    startButton->setStyleSheet("background-color: blue; color: yellow;");
    exitButton->setStyleSheet("background-color: blue; color: yellow;");

    startButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    exitButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    // Set buttons font style 
    QFont buttonFont("Arial", BUTTON_FONT_SIZE, QFont::Bold);
    startButton->setFont(buttonFont);
    exitButton->setFont(buttonFont);
    
    // Setup main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(gameTitle, 0, Qt::AlignHCenter | Qt::AlignTop);
    mainLayout->addSpacing(130);

    // Setup buttons' layout 
    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(startButton, 0, Qt::AlignHCenter);
    buttonsLayout->addSpacing(100);
    buttonsLayout->addWidget(exitButton, 0, Qt::AlignHCenter);

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addStretch();

    connect(exitButton, &QPushButton::clicked, this, [this]() {emit exitGame();});
    
    setLayout(mainLayout);
}