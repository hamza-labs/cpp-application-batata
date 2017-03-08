#include "ObstacleM.hpp"

#include <iostream>

using std::cout;
using std::endl;

ObstacleM::ObstacleM(Position * p_pos, Matrix * p_mat)
: Movable(p_pos, p_mat)
{

}

void ObstacleM::show()
{
    cout <<" E ";
}
