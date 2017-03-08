#include "Matrix.hpp"
#include "Position.hpp"
#include "Obj.hpp"

#include <iostream>

using std::cout;
using std::endl;

Matrix::Matrix()
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; ++i) // On parcourt toutes les lignes de la matrice
	{
		for (j = 0; j < COLS; ++j) // On parcourt toutes les colonnes de la matrice
		{
			// Pour chaque case de la matrice, qui doit contenir normalement une adresse d'un objet, on l'initialise à 0
			// Les adresse mémoires commence en fait à partir de 1 jusqu'à le nombre de d'octet que nous avons dans la RAM
			// L'adresse 0 ou NULL indique que la case d'indice [i][j] ne pointe en fait sur aucun Obj valide
			// Ce qui est le cas, car initialement la matrice est vide
			this->mat[i][j] = nullptr;
		}
	}

	// Le mot clé new en C++ est comme la fonction malloc (memory allocation) en langage C.
	// Il permet d'allouer la mémoire dynamiquement, et comme c'est le développeur qui a alloué cette mémoire,
	// Il est responsable de sa libération, ce qui correspond à un free en langage C, ou un delete en C++
	// dans la case d'indice [0][1], j'ai utilisé un new pour créer un objet
	// Donc quand j'aurais fini de ma matrice, et que je suis sur le point de la détruire, je dois d'abord détruire l'objet
	// que j'ai créé avec new pour libérer la mémoire.
	// Et avant de détruire l'objet Obj, je dois d'abord détruire la position que j'ai créé avec new dans Obj afin de libérer
	// la mémoire. Donc il me faut un destructeur pour la classe Matrix, et un destructeur pour la classe Obj
	//this->mat[0][1] = new Obj(new Position(1,2));

}

Matrix::~Matrix()
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLS; ++j)
		{
			if (this->mat[i][j] != 0) // Si la case d'indice [i][j] contient une adresse d'un Obj valide qu'il faut libérer
			{
				delete this->mat[i][j];
				this->mat[i][j] = nullptr;
			}
		}
	}

	//printf("\n byebye matrix \n"); // Pour vérifier que le destructeur a été appelé quand la variable Matric est détruite
	// Cet affichage sera supprimé plus tard
}

bool Matrix::is_position_valid(Position * p_pos)
{
    return ((p_pos->row >= 0) && (p_pos->row < ROWS) && (p_pos->col >= 0) && (p_pos->col < COLS));
}

Obj * Matrix::get_obj_at(Position * p_pos)
{
    return mat[p_pos->row][p_pos->col];
}

void Matrix::set_obj_at(Position * p_pos, Obj * p_obj)
{
    set_obj_at(p_pos->row, p_pos->col, p_obj);
}

void Matrix::delete_obj_at(Position * p_pos)
{
    if(this->mat[p_pos->row][p_pos->col] != nullptr)
    {
        delete mat[p_pos->row][p_pos->col];

        mat[p_pos->row][p_pos->col] = nullptr;
    }
}

void Matrix::set_obj_at(int p_row, int p_col, Obj * p_obj)
{
    this->mat[p_row][p_col] = p_obj;
}

void Matrix::show()
{
    int i = 0, j = 0;

    for(i = 0; i < ROWS; ++i)
    {
        for(j = 0; j < ROWS; ++j)
        {
			if (this->mat[i][j] != nullptr)
				mat[i][j]->show();
        }
    }
}

