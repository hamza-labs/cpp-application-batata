#pragma once

class Position
{
	friend class Matrix;
private: // Les attributs sont toujours privés, c'est à dire non accessible en dehors de la classe
	int row;
	int col;
public:
    Position(int pRow, int pCol);

    void move_to(int p_dir);
};
