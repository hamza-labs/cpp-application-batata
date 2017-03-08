#include "qmonster.hpp"

#include "Position.hpp"
#include "Matrix.hpp"

#include <iostream>

using std::cout;
using std::endl;

QMonster::QMonster(Position * p_pos, Matrix * p_mat)
    : QObj(":/ObjImages/images/monster.png"), Monster(p_pos, p_mat)
{

}

void QMonster::show()
{
    this->QObj::show();
}
