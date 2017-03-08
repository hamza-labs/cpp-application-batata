#pragma once

#include "Game.hpp"

#include <QObject>
#include <QWidget>

class QWidget;
class QLayout;
class QLCDNumber;
class QVBoxLayout;
class QHBoxLayout;

class LKQMatrix;

class QGame : public QWidget, public Game
{
    // Une macro qui permet d'étendre le langage C++ afin qu'il accepte les mots clés:
    // signals: les signaux que l'objet emet
    // slots: les handlers, ou les méthodes qui seront à l'écoute de ces signaux
    // On a besoin de définir des slots pour gérer les signaux émis par un QBatata détruit et par un QPlayer
    // déplacé afin de modifier l'affichage du nombre de batata et de pas (steps) dans l'interface graphique
    // Pour que la macro Q_OBJECT fonctionne, il est nécessaire que QGame hérite d'abord directement ou
    // indirectement de QWidget, ensuite on peut ajouter l'héritage de Game
    Q_OBJECT

private:
    LKQMatrix * m_matrix;
    QLCDNumber * m_lcdNumber_steps;
    QLCDNumber * m_lcdNumber_batatas;
    QLCDNumber * m_lcdNumber_seconds;
    bool m_is_destroyed;
public:

    QGame();
    ~QGame();

    Matrix * create_matrix();

    // Quand un batata est créé il faut connecter son signal 'signal_batata_destroyed();'
    // avec le slot 'slot_batata_destroyed();' de QGame
    Batata * create_batata();
    Obstacle * create_obstacle();

    ObstacleM * create_obstacleM(Position * p_pos, Matrix * p_mat);

    // Quand un player est créé il faut connecter son signal 'signal_player_moved();'
    // avec le slot 'slot_player_moved();' de QGame
    Player * create_player(Position * p_pos, Matrix * p_mat);
    Monster * create_monster(Position * p_pos, Matrix * p_mat);

    virtual void show();

    // Pour appeler la méthode protégée place_objects sans faire la boucle infinie de Game::start(); voir Game.cpp
    virtual void start();

    // Méthode appelée quand on gagne au jeu
    virtual void win();

public slots:
    void slot_batata_destroyed();
    void slot_player_moved();
    void slot_timer_timeout();
};



