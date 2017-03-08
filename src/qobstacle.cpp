#include "qobstacle.hpp"

#include <iostream>

using std::cout;
using std::endl;

QObstacle::QObstacle()
    :QObj(":/ObjImages/images/obstacle.png")
{

}

void QObstacle::show()
{
    // On utilise la méthode show de QObj pour afficher l'objet dans une interface graphique
    this->QObj::show();
}
