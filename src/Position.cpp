#include "Position.hpp"
#include "EnumDirection.hpp"

#include <iostream>

using std::cout;
using std::endl;

Position::Position(int pRow, int pCol)
{
    row = pRow;
    col = pCol;
}

void Position::move_to(int p_dir)
{
    switch(p_dir)
	{
	case DIR_UP:
		row--;
		break;
	case DIR_DOWN:
		row++;
		break;
	case DIR_LEFT:
		col--;
		break;
	case DIR_RIGHT:
		col++;
		break;
    default:
		break;
    }
}
