#pragma once

#include "Monster.hpp"
#include "qobj.hpp"

class QMonster: public QObj, public Monster
{
public:
    QMonster(Position * p_pos, Matrix * p_mat);

    virtual void show();
};
