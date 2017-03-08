#pragma once

#include "qobj.hpp"

class QEmpty: public QObj
{
public:
    // Un constructeur par défaut qui va construire le QObj en lui passant le chemin de l'image du vide
    QEmpty();

    // La classe QEmpty n'a pas besoin de redéfinir la méthode show car il n'y a pas d'ambiguité
};

