#include "Grafo.h"

using namespace std;
Grafo::Grafo(int nmrAresta, int nmrVertice)
{
    this->nmrAresta = nmrAresta;
    this->nmrVertice = nmrVertice;
}

int Grafo::getNmrAresta()
{
    return this->nmrAresta;
}

int Grafo::getNmrVertice()
{
    return this->nmrVertice;
}

void Grafo::setNmrAresta(int _nmrAresta)
{
    this->nmrAresta = _nmrAresta;
}

void Grafo::setNmrVertice( int _nmrVertice)
{
    this->nmrVertice = _nmrVertice;
}

Grafo::~Grafo()
{
    //dtor
}
