#pragma once

class Matrix;
class Player;

class Batata;
class Obstacle;

class Position;
class ObstacleM;
class Monster;

class Game
{
private:
    Matrix * matrix;
	Player * player;

public:
    Game();
    
	virtual ~Game();

    virtual bool try_move_to(int p_dir);

    virtual void show();

    virtual void start();

protected:
    virtual Batata * create_batata();
    
	virtual Obstacle * create_obstacle();

    virtual ObstacleM * create_obstacleM(Position * p_pos, Matrix * p_mat);
    
	virtual Player * create_player(Position * p_pos, Matrix * p_mat);
    
	virtual Monster * create_monster(Position * p_pos, Matrix * p_mat);

    virtual Matrix * create_matrix();

    virtual void place_objects();
};


