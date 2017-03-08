#include "qbatata.hpp"

#include <QWidget>

#include <iostream>

using std::cout;
using std::endl;

QBatata::QBatata()
    :QObj(":/ObjImages/images/batata.png")
{

}

QBatata::~QBatata()
{
    // Emettre le signal de destruction d'un QBatata pour qu'il soit intercepté
    emit this->signal_qbatata_destroyed();
}

void QBatata::show()
{
    this->QObj::show();
}
