#include "scenes/MenuScene.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <random>
#include <string>

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
    gameTitle->setAttribute(Qt::WA_TranslucentBackground);

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

    // Connect signals to the buttons
    connect(exitButton, &QPushButton::clicked, this, [this](){emit exitGame();});
    connect(startButton, &QPushButton::clicked, this, [this](){emit openGameScene();});

    setLayout(mainLayout);
}

void MenuScene::paintEvent(QPaintEvent *event)
{
    const int objectsNum = 350; // number of random objects to draw
    QPainter painter(this);

    // Set colors for the painter 
    painter.setBrush(Qt::white); 
    painter.setPen(Qt::white);

    // Setup random genrator 
    std::random_device rd; 
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> rand_x_cord(1, this->width());
    std::uniform_int_distribution<int> rand_y_cord(1, this->height());

    for(int i = 0; i < objectsNum; i++)
    {
        int random_x = rand_x_cord(gen); 
        int random_y = rand_y_cord(gen);
        painter.drawEllipse(random_x, random_y, 1, 1);
    }
}