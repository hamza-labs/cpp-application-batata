#include "Game.hpp"
#include "Matrix.hpp"
#include "Position.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "ObstacleM.hpp"
#include "Monster.hpp"
#include "Batata.hpp"
#include "EnumDirection.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Game::Game()
{

}

Game::~Game()
{
    if(matrix != nullptr)
    {
        delete matrix;

        matrix = nullptr;

        player = nullptr;
    }
}


void Game::show()
{
    matrix->show();
}

bool Game::try_move_to(int p_dir)
{
    return player->try_move_to(p_dir);
}

void Game::start()
{
    char choix;

    place_objects();

    do 
    {
        show();

        cout << endl;
        cin >> choix;

        try_move_to(choix);

    }
    while(choix != 0);
}

Batata * Game::create_batata()
{
    return new Batata();
}

Obstacle * Game::create_obstacle()
{
    return new Obstacle();
}

ObstacleM * Game::create_obstacleM(Position * p_pos, Matrix * p_mat)
{
    return new ObstacleM(p_pos, p_mat);
}

Player * Game::create_player(Position * p_pos, Matrix * p_mat)
{
    return new Player(p_pos, p_mat);
}

Monster * Game::create_monster(Position * p_pos, Matrix * p_mat)
{
    return new Monster(p_pos, p_mat);
}

Matrix * Game::create_matrix()
{
    return new Matrix();
}

void Game::place_objects()
{
    Position * pos;
    Obj * obj;

    matrix = create_matrix();

    pos = new Position(0, 0);
    player = create_player(pos, matrix);

    matrix->set_obj_at(pos, player);

    pos = new Position(1, 0);
    obj = create_obstacle();
    matrix->set_obj_at(pos, obj);

    pos = new Position(1, 1);
    obj = create_monster(pos, matrix);
    matrix->set_obj_at(pos, obj);

    pos = new Position(0, 2);
    obj = create_obstacleM(pos, matrix);
    matrix->set_obj_at(pos, obj);

    pos = new Position(1, 3);
    obj = create_obstacleM(pos, matrix);
    matrix->set_obj_at(pos, obj);

    pos = new Position(2, 3);
    obj = create_obstacleM(pos, matrix);
    matrix->set_obj_at(pos, obj);

    pos = new Position(1, 2);
    obj = this->create_batata();
    matrix->set_obj_at(pos, obj);

    pos = new Position(2, 2);
    obj = create_batata();
    matrix->set_obj_at(pos, obj);
}
