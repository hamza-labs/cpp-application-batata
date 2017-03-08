#pragma once

#include "Obstacle.hpp"
#include "qobj.hpp"

class QObstacle: public QObj, public Obstacle
{
public:
    // Un constructeur par défaut qui va construire le QObj en lui passant le chemin de l'image d'un obstacle
    QObstacle();

    // La classe Obstacle contient une méthode show, et la classe QObj contient aussi une méthode show
    // Il faut donc redéfinir la méthode show dans QObstacle et dire quel show on va utiliser
    virtual void show();
};
