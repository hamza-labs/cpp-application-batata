#pragma once

#include "Movable.hpp"

class Monster: public Movable
{
public:
    Monster(Position * pPos, Matrix * pMat);

	virtual ~Monster();

    virtual void show();
    
	virtual bool can_replace(Obj * p_obj); // On redéfinie can_replace car un monster peut manger un player
};
