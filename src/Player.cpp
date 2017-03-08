#include "Player.hpp"
#include "Position.hpp"
#include "Matrix.hpp"
#include "Batata.hpp"

#include <iostream>

using std::cout;
using std::endl;

Player::Player(Position * p_pos, Matrix * p_mat)
: Movable(p_pos, p_mat)
{
    steps = 0;
}

void Player::show()
{
    cout <<" P ";
}

bool Player::try_move_to(int p_dir)
{
	auto is_moved = Movable::try_move_to(p_dir);

    if(is_moved)
        steps++;

    return is_moved;
}

bool Player::can_replace(Obj * p_obj)
{
	auto batata = dynamic_cast<Batata *>(p_obj);

    if(batata != nullptr)
		return true;

    return false;
}
