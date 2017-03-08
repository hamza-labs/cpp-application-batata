#include "Monster.hpp"
#include "Position.hpp"
#include "Matrix.hpp"
#include "Player.hpp"

#include <stdio.h>

#include <iostream>

using std::cout;
using std::endl;

Monster::Monster(Position * pPos, Matrix * pMat)
: Movable(pPos, pMat)
{

}

Monster::~Monster()
{
}

void Monster::show()
{
    printf(" M ");
}

bool Monster::can_replace(Obj * p_obj)
{
    Player * player = dynamic_cast<Player *>(p_obj);

    if(player != nullptr)
    {
        return true; 
    }
	return false;
}
