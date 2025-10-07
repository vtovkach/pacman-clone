TEMPLATE = app
CONFIG += c++17 console
QT += core gui widgets

# Where to find headers
INCLUDEPATH += include

# Source files
SOURCES += \
    src/main.cpp \
    src/manager/GameManager.cpp \
    src/scenes/Scene.cpp \
    src/scenes/GameScene.cpp \
    src/scenes/MenuScene.cpp \
    src/scenes/EndScene.cpp \
    src/maps/Map.cpp \
    src/entities/Entity.cpp \
    src/entities/PacMan.cpp
    
# Headers
HEADERS += \
    include/manager/GameManager.hpp \
    include/scenes/Scene.hpp \
    include/scenes/GameScene.hpp \
    include/scenes/MenuScene.hpp \
    include/scenes/EndScene.hpp \
    include/maps/Map.hpp \
    include/entities/Entity.hpp \
    include/entities/PacMan.hpp \
    include/entities/Pellet.hpp \
    include/entities/ghosts/Blinky.hpp \
    include/entities/ghosts/Clyde.hpp \
    include/entities/ghosts/Inky.hpp \
    include/entities/ghosts/Pinky.hpp \
    include/entities/PacMan.hpp

# Output binary
DESTDIR = bin
TARGET = pacman

# --- All dependencies in qmake-assets/
OBJECTS_DIR = qmake-assets/obj
MOC_DIR     = qmake-assets/moc
RCC_DIR     = qmake-assets/rcc
UI_DIR      = qmake-assets/ui
QMAKE_STASH_FILE = qmake-assets/.qmake.stash   # qmake ignores this, but harmless

# --- Extra targets ---
QMAKE_EXTRA_TARGETS += run clear rebuild

# Run target
run.target = run
run.depends = $(TARGET)
run.commands = ./bin/pacman

# Clear target (wipe everything including stash + Makefile)
clear.target = clear
clear.commands = rm -rf qmake-assets bin Makefile .qmake.stash

# Rebuild target
rebuild.target = rebuild
rebuild.commands = $(MAKE) clear && qmake && $(MAKE) all