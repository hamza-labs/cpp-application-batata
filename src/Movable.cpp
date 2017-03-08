#include "Movable.hpp"
#include "Position.hpp"
#include "Matrix.hpp"
#include "ObstacleM.hpp"

#include <iostream>

using std::cout;
using std::endl;

Movable::Movable(Position * p_pos, Matrix * p_mat)
{
    this->position = p_pos;
    this->matrix = p_mat;
}

Movable::~Movable()
{
    if(this->position != 0)
    {
        delete position;
        position = nullptr; 
    }
}

bool Movable::try_move_to(int p_dir)
{
	auto pos = *(position); 

    pos.move_to(p_dir);

    if(matrix->is_position_valid(&pos) == false)
    {
        return false; 
    }
	if(can_move_to(&pos))
    {
        move_to(&pos);

        return true; 
    }
	auto obj = matrix->get_obj_at(&pos);

	if(can_push(p_dir, &pos))
	{
		auto obsM = dynamic_cast<ObstacleM *>(obj);

		push(p_dir, obsM); 
		move_to(&pos); 

		return true; 
	}
	if(can_replace(obj))
	{
		move_to(&pos);

		return true; 
	}

    return false; 
}

bool Movable::can_replace(Obj * p_obj)
{
    return false;
}

bool Movable::can_move_to(Position * p_pos) const
{
    if(matrix->is_position_valid(p_pos))
        if(matrix->get_obj_at(p_pos) == nullptr)
            return true; 
	return false;
}

void Movable::move_to(Position * p_pos)
{
    matrix->set_obj_at(position, nullptr);

    matrix->delete_obj_at(p_pos);

    matrix->set_obj_at(p_pos, this);

    *(position) = *(p_pos);
}

bool Movable::can_push(int p_dir, Position * p_pos) const
{
	auto obj = matrix->get_obj_at(p_pos);

	auto obsM = dynamic_cast<ObstacleM *>(obj);

    if(obsM == nullptr)
    {
        return false;
    }
	auto pos(*(obsM->position));

	pos.move_to(p_dir);

	if(matrix->is_position_valid(&pos) == false)
	{
		return false;
	}

	auto obj_next = matrix->get_obj_at(&pos);

	if(obj_next == nullptr)
		return true;


	auto can_push_next = can_push(p_dir, &pos);

	return can_push_next;
}

void Movable::push(int p_dir, ObstacleM * p_obsM) const
{
	auto pos(*(p_obsM->position));

    pos.move_to(p_dir);

	auto obj_next = matrix->get_obj_at(&pos);

    if(obj_next != nullptr)
    {
	    auto obsM_next = dynamic_cast<ObstacleM *>(obj_next);

        push(p_dir, obsM_next);
    }

    p_obsM->move_to(&pos);
}
