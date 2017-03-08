#pragma once // Pour ne pas inclure le fichier plusieurs fois

// On définit deux constantes ROWS et COLS pour que si après on veut les modifier
// On aura besoin de les modifier juste ici (dans le #define) et non partout dans notre code
#define ROWS 5
#define COLS 5

class Obj;
class Position;

class Matrix
{
private:
	Obj *mat[ROWS][COLS]; // Un matrice de ROWS lignes et de COLS colonnes
						  // Chaque case de la matrice contient un Obj *, c'est à dire un pointeur sur un Obj


public:
    Matrix();

    // Destructeur de la matrice pour suppriemr les objets qu'elle contient
    virtual ~Matrix();

	static bool is_position_valid(Position * p_pos);

    Obj * get_obj_at(Position * p_pos);

    void set_obj_at(Position * p_pos, Obj * p_obj);

    void delete_obj_at(Position * p_pos);

    virtual void show();

protected:
    virtual void set_obj_at(int p_row, int p_col, Obj * p_obj);
};
