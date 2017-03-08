#pragma once

#include "Movable.hpp"

class Player: public Movable
{
private:
    int steps;

public:
    Player(Position * pPos, Matrix * pMat);

    virtual void show();

    virtual bool try_move_to(int p_dir);

protected:
    bool can_replace(Obj * p_obj);
};
