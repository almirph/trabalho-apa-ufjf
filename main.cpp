#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std;

void GeraGrafo_Q1(int nmrArestas, int nmrVertices)
{
    int i, j, aresta[nmrArestas][2], contador;
    i = 0;
    while(i < nmrArestas)
    {
        aresta[i][0] = rand()%nmrVertices+1;
        aresta[i][1] = rand()%nmrVertices+1;
        if(aresta[i][0] == aresta[i][1])
            continue;
        else
        {
            for(j = 0; j < i; j++)
            {
                if((aresta[i][0] == aresta[j][0] &&
                        aresta[i][1] == aresta[j][1]) || (aresta[i][0] == aresta[j][1] &&
                                                      aresta[i][1] == aresta[j][0]))
                    i--;
            }
        } i
        ++;
    }
    for(i = 0; i < nmrVertices; i++)
    {
        contador = 0;
        cout<<"\n\t"<<i+1<<"-> [ ";
        for(j = 0; j < nmrArestas; j++)
        {
            if(aresta[j][0] == i+1)
            {
                cout<<aresta[j][1]<<" ";
                contador++;
            }
            else if(aresta[j][1] == i+1)
            {
                cout<<aresta[j][0]<<" ";
                contador++;
            }
            else if(j== nmrArestas-1 && contador == 0)
                cout<<"Vertice sem arestas";
        }
        cout<<" ]";
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    int a, v;
    v= 100;
    //Geração de 100 a 1000 vertices
    a = v + (v * (rand() % 9));
    GeraGrafo_Q1(a, v);
}
