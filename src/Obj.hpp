#pragma once

class Obj // Classe abstraite car contient une méthode virtuelle pure
{
public:
    virtual void show() = 0; // Méthode virtuelle pure car non implémentée
    virtual ~Obj(); // Destructeur virtuel car si on fait 'delete' d'un Obj qui est en fait un Batata
    // on voudrait supprimer Batata en entier et non seulement la partie Obj de Batata
    // Si toujours une bonne pratique de mettre son destructeur virtuel
};


