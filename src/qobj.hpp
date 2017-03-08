#pragma once

#include "Obj.hpp"

#include <QWidget>


#include <string>

// std est l'espace de nom (namespace) contenant les classes standard du C++
// en C toutes les fonctions sont accessibles sans espace de nom
// En C++ c'est mieux organisé, et le mot clé using permet de ramener
// uniquement la classe string du namespace std
// au lieu d'utiliser: using namespace std;
// qui permet de ramener toutes classes du namespace std et ralentir ainsi la compilation
// Le compilateur est assez intelligent pour ne ramener que les classes dont on a besoin
// Mais le fait de le faire travailler alors qu'on sait qu'on aura besoin que de la classe string
// ralentira la compilation
// La classe string gére les chaine de caractères et définie certains opérateurs
// par exemple on ne peut pas faire "salut" + " " + "ca" + " " + "va"
// car "salut" est une chaine de caractères de type char *
// une chaine de caractère est l'adresse du premier caractères dans le tableau |s|a|l|u|t|\0|
// le caractère |\0| est le caractère qui indique la fin de la chaine de caractères
// donc en gros si on fait "salut" + " " + "ca" + " " + "va"
// C'est comme si on calculait la somme de l'adresse du premier caractère dans "salut" plus
// l'adresse du premier caractère dans " " + l'adresse du premier caractère dans "ca" ..etc
// Mais bien evidement ce n'est pas ce qu'on veut. La classe string fait plusieurs choses dont la
// surcharge de l'opérateur + et au lieu de calculer la somme des adresses elle concatènent les chaines
// de caractères. Ainsi "salut" + " " + "ca" + " " + "va" donnera comme résultat "salut ca va"
using std::string;

class QObj : public QWidget
{
public:
    // Pour construire un QObj il faut indiquer le chemin de l'image correspondant au QObj
    QObj(string p_path_image);

    // Un destructeur qui ne fait rien mais on le déclare quand même pour préciser qu'il est virtual
    // Car plusieurs objet hériteront de QObj, et on veut quand on détruit un QObj qui est en fait un QPlayer
    // qu'on puisse détuire aussi la partie spécifique à QPlayer
    virtual ~QObj();
};
