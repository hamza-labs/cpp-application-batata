#include "qobstaclem.hpp"

#include "Position.hpp"
#include "Matrix.hpp"

#include <iostream>

using std::cout;
using std::endl;

QObstacleM::QObstacleM(Position *p_pos, Matrix *p_mat)
    :QObj(":/ObjImages/images/obstacleM.png"), ObstacleM(p_pos, p_mat)
{

}

void QObstacleM::show()
{
    this->QObj::show();
}
