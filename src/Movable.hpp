#pragma once // Pour ne pas inclure le fichier plusieurs fois

#include "Obj.hpp"
#include "Position.hpp"

class ObstacleM;
class Obstacle;
class Matrix;
class Position;


class Movable: public virtual Obj
{
private: 
	// Une implémentation en singleton (https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Singleton)
	// de la classe Matrix, nous aurais epagrgnié le besoin d'avoir 
	// un attribut matrix dans chaque objet Movable.

	//!!!!!!!!!!!!!!!! (Commentaire a supprimer avant rendu)  !!!!!!!!!!!!!!!!\\


	Matrix * matrix; // La classe movable permet de se déplacer, on a donc besoin en plus de la position d'un objet Movable,
					 // de la matrice afin de savoir ce qui se trouve dans la case où on veut aller, s'il y a une batata il faut la manger,
					 // S'il y a un obstacle mobile il faut le déplacer d'abord et ensuite prendre sa place, ... etc.

	Position *position; // On doit modifier position mais celle hérité de Obj est private et pas de setteur existant

public: 
    Movable(Position * pPos, Matrix * pMat);
    
	virtual ~Movable();

    virtual bool try_move_to(int p_dir);

protected: 
	virtual bool can_replace(Obj * p_obj);

private:
    bool can_move_to(Position * p_pos) const;

    void move_to(Position * p_pos);

    bool can_push(int p_dir, Position * p_pos) const;

    void push(int p_dir, ObstacleM * p_obsM) const;
};
