#pragma once

#include "Player.hpp"
#include "QObj.hpp"

#include <QObject>

class QPlayer: public QObj, public Player
{
    // Une macro qui permet d'étendre le langage C++ afin qu'il accepte les mots clés:
    // signals: les signaux que l'objet emet
    // slots: les handlers, ou les méthodes qui seront à l'écoute de ces signaux
    // On a besoin d'emettre un signal à chaque fois qu'un QPlayer est bougé afin de modifier l'affichage
    // du nombre de pas dans l'interface graphique du jeu
    // Pour que la macro Q_OBJECT fonctionne, il est nécessaire que QPlayer hérite d'abord directement ou
    // indirectement de QWidget, ensuite on peut ajouter l'héritage de Player
    Q_OBJECT

public:
    QPlayer(Position * p_pos, Matrix * p_mat);

    virtual void show();

    // Il faut redéfinir try_move_to pour emettre le signal 'signal_player_moved();' si le player est bougé
    virtual bool try_move_to(int p_dir);

signals:
    void signal_player_moved();
};
