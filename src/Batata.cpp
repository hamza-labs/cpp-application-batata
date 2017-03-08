#include "Batata.hpp"

#include <iostream>

using std::cout;
using std::endl;


Batata::Batata()
{
    nb_batata++;
}

Batata::Batata(const Batata & p_batata)
{
    nb_batata++;
}

Batata::~Batata()
{
    nb_batata--;
}

void Batata::show()
{
    cout <<" B ";
}

int Batata::nb_batata = 0; // On mets le compteur à 0