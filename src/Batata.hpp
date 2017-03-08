#pragma once

#include "Obj.hpp"

class Batata: public virtual Obj
{
private:
    static int nb_batata; // compteur des Banane encore présente

public:
    Batata(); 

    Batata(const Batata & p_batata); 
    
    virtual ~Batata(); 

    virtual void show(); 
    
};
