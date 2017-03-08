#include "qobj.hpp"

#include "Matrix.hpp"

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <iostream>

using std::cout;
using std::endl;

QObj::QObj(string path_image)
{
    // On créé un QLabel pour contenir l'image
    // On définit l'ojet de type QWidget dont hérite QObj en tant que parent du QLabel
    // this est un QObj qui est un QWidget, donc this est un QWidget, et pour définir le parent d'un label
    // On a besoin de préciser le QWidget parent qui sera donc 'this'
    QLabel * label = new QLabel(this);

    // Pour construire une image QPixmap on a besoin d'un objet QString correspondant au chemin de l'image
    // Le constructeur de la classe QString a besoin d'un char * c'est pour celà qu'on lui passe path_image.c_str()
    // la méthode c_str() de la classe string permet de retourner un char * qui correspond à la chaine de caractères
    // C'est ce qui permet d'établire le lien entre un string, un char *, et un QString

    // On construit un QString
    QString qstring = QString(path_image.c_str());

    // On construit un pixmap à partir du QString
    QPixmap pixmap = QPixmap(qstring);

    // Faire un resize de l'image chargée
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);

    // On affecte le pixmap au label
    label->setPixmap(pixmap);

    //label->setContentsMargins(0, 0, 0, 0);
    //label->setMargin(0);

    // On permet le resize du contenu du label (dans ce cas la pixmap)
    label->setScaledContents(true);
}

QObj::~QObj()
{

}
