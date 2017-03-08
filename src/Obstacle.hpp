#pragma once

#include "Obj.hpp"



/*
L'héritage virtual empèche le fait d'avoir plus d'une class de base de type Obj dans le cas d'héritage multiple
Exemple:

Obstacle:Obj // Obstacle non mobile qui hérite de Obj
ObstacleM:Movable:Obj // Obstacle mobile qui hérite de Movable qui hérite de Obj
ObstacleS:Obstacle, ObstacleM // Obstacle spécial qui passe de l'état non mobile à l'état mobile et vice versa
chaque 10 secondes.
Obstacle S aura dans ce cas deux classes de base de type Obj, l'une vient de Obstacle et l'autre de Obstacle M.
Pour éviter ce problème il faut utiliser l'héritage virtual:

Obstacle: virtual Obj
ObstacleM:Movable:virtual Obj
ObstacleS: Obstacle, ObstacleM

Dans l'héritage virtual la classe de la plus haute hiérarchie doit redéfinir les méthodes virtual des classes de base
pour éviter le conflit
*/

class Obstacle: public virtual Obj
{
public:
    virtual void show(); // On redéfinie la fonction show car un Obstacle a sa propre façon de s'afficher
};
