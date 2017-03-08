#include "mainwindow.h"

#include "qgame.hpp"
#include "EnumDirection.hpp"

#include <QGridLayout>
#include <QString>
#include <QPixmap>
#include <QBitmap>
#include <QLabel>

#include <QObject>

#include <QMessageBox>

#include <QKeyEvent>
#include <QResizeEvent>

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // On crée un layout
    QVBoxLayout * layout = new QVBoxLayout();

    // On affecte le layout à la fenêtre principale
    this->setLayout(layout);

    // On crée un objet QGame
    this->m_game = new QGame();

    // On démarre le jeu (initialisation des objets dans la matrice du jeu et la grille de l'interface graphique)
    this->m_game->start();

    // On ajout le widget du jeu dans le layout de la fenêtre principale
    layout->addWidget(this->m_game);
}

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    int dir = 0;

    if(e->text() == "c")
    {
        dir = DIR_RIGHT;
    }

    else if(e->text() == "w")
    {
        dir = DIR_LEFT;
    }

    else if(e->text() == "s")
    {
        dir = DIR_UP;
    }

    else if(e->text() == "x")
    {
        dir = DIR_DOWN;
    }

    this->m_game->try_move_to(dir);
}
