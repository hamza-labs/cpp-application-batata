#include "qplayer.hpp"

#include "Position.hpp"
#include "Matrix.hpp"

#include <iostream>

using std::cout;
using std::endl;

QPlayer::QPlayer(Position *p_pos, Matrix *p_mat)
    :QObj(":/ObjImages/images/player.png"), Player(p_pos, p_mat)
{

}

void QPlayer::show()
{
    this->QObj::show();
}

bool QPlayer::try_move_to(int p_dir)
{
    bool is_moved = this->Player::try_move_to(p_dir);

    // Si le player est bougé
    if(is_moved)
    {
        // alors émettre le signal correspondant au déplacement du joueur
        emit signal_player_moved();
    }

    return is_moved;
}
