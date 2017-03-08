#pragma once

#include "Batata.hpp"
#include "qobj.hpp"

#include <QObject>

class QBatata : public QObj, public Batata
{
    // Une macro qui permet d'étendre le langage C++ afin qu'il accepte les mots clés:
    // signals: les signaux que l'objet emet
    // slots: les handlers, ou les méthodes qui seront à l'écoute de ces signaux
    // On a besoin d'emettre un signal à chaque fois qu'un QBatata est détruit afin de modifier l'affichage
    // du nombre de Batatas dans l'interface graphique du jeu
    Q_OBJECT

public:
    // Un constructeur par défaut qui va construire le QObj en lui passant le chemin de l'image d'un Batata
    QBatata();

    // Implémentation du destructeur car celui là doit emettre le signal 'signal_qbatata_destroyed' afin qu'une
    // méthode à l'écoute de ce signal puisse exécuter l'action correspondante à la destruction d'un QBatata
    // dans ce cas ca sera la modification du nombre de batatas affiché dans l'interface graphique
    virtual ~QBatata();

    // QBatata hérite de Batata possédant une méthode show, et de QObj qui est un QWidget possédant la méthode show
    // QBatata doit donc implémenté la méthode show pour éviter le conflit
    virtual void show();

signals:
    void signal_qbatata_destroyed();
};
