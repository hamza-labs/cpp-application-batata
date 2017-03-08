#pragma once

#include "Matrix.hpp"
#include <QWidget>

class QGridLayout;

// La classe s'appèle LKQMatrix car la classe QMatrix existe déjà dans la bibliothèque Qt
// Son ajout entraînera des conflits qu'il est préférable d'éviter
class LKQMatrix: public Matrix, public QWidget
{
private:
    QGridLayout * m_layout_grid;

public:
    LKQMatrix();
    // On n'a pas besoin d'un destructeur car quand un QWidget est détruit, il détruit ses enfants
    // La variable m_layout_grid sera affecté à un QWidget parent qui se chargera de la détruire

    // Quand on appelle la méthode set_obj_at il faut en plus de mettre l'objet dans la matrice du jeu,
    // le mettre dans la grille de l'interface graphique pour l'afficher
    // C'est pour celà qu'on réimplémente la méthode set_obj_at de la classe Matrix dans la classe LKQMatrix
    void set_obj_at(int p_row, int p_col, Obj * p_obj);
};
