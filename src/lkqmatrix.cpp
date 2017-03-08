#include "lkqmatrix.hpp"

#include "Position.hpp"
#include "Obj.hpp"
#include "qobj.hpp"
#include "qempty.hpp"

#include <QWidget>
#include <QGridLayout>

#include <QPalette>
#include <QColor>

#include <iostream>

using std::cout;
using std::endl;

LKQMatrix::LKQMatrix()
{
    int i, j;
    QEmpty * qempty;

    // Un objet QPalette permet de gérer les couleurs d'un QWidget: couleur et couleur de fond
    QPalette palette = QPalette();

    // Plusieurs façons sont possibles pour initialiser une QColor,
    // la plus simple est d'utiliser une couleur constante
    QColor color(Qt::blue);

    // On affecte la couleur color à la palette pour la propriété background
    palette.setColor(QPalette::Background, color);

    // On affecte la palette au LKQMatrix qui est en fait un QWidget
    this->setPalette(palette);

    // Pour indiquer que le widget possède un background et il n'est pas transparent
    this->setAutoFillBackground(true);

    // On crée un gridlayout qui est un layout sous forme d'une matrice dynamique
    // permettant d'ajouter des widget à n'importe quelle ligne et colonne qu'on veut
    this->m_layout_grid = new QGridLayout();

    //*
    this->m_layout_grid->setHorizontalSpacing(0);
    this->m_layout_grid->setVerticalSpacing(0);
    this->m_layout_grid->setSpacing(0);

    this->m_layout_grid->setContentsMargins(0, 0, 0, 0);
    this->m_layout_grid->setMargin(0);
    //*/

    // On affecte le layout matriciel à LKQMatrix qui est un QWidget
    this->setLayout(this->m_layout_grid);

    // On initialise le layout par des widget affichant le vide: QEmpty
    for(i = 0; i < ROWS; ++i)
    {
        for(j = 0; j < COLS; ++j)
        {
            qempty = new QEmpty();
            this->m_layout_grid->addWidget(qempty, i , j);
        }
    }
}

void LKQMatrix::set_obj_at(int p_row, int p_col, Obj *p_obj)
{
    // On essaye de faire un cast de p_obj vers le type QObj *
    QObj * qobj = dynamic_cast<QObj *>(p_obj);

    // Si p_obj est effectivement un pointeur sur QObj
    if(qobj != 0)
    {
        // On ajoute l'objet à la grille de l'interface graphique
        this->m_layout_grid->addWidget(qobj, p_row, p_col);
    }

    // On place l'objet p_obj dans la matrice du jeu
    this->Matrix::set_obj_at(p_row, p_col, p_obj);
}



