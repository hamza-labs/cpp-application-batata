#pragma once

#include "ObstacleM.hpp"
#include "QObj.hpp"

class QObstacleM: public QObj, public ObstacleM
{
public:
    QObstacleM(Position * p_pos, Matrix * p_mat);

    virtual void show();
};
