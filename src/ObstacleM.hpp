#pragma once

#include "Movable.hpp"


class ObstacleM: public Movable
{
public:
    ObstacleM(Position * pPos, Matrix * pMat);

    virtual void show();
};
