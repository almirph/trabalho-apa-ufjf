#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Grafo.h"
#include <vector>

using namespace std;

void GeraGrafo_Q1(int nmrArestas, int nmrVertices)
{
    int i, j, contador;
    vector<vector<int>> arestas(nmrArestas, vector<int>(nmrVertices));
    i = 0;
    while(i < nmrArestas)
    {
        arestas.at(i).at(0) = rand()%nmrVertices+1;
        arestas.at(i).at(1) = rand()%nmrVertices+1;

        if(arestas.at(i).at(0) == arestas.at(i).at(1))
            continue;
        else
        {
            for(j = 0; j < i; j++)
            {
                if((arestas.at(i).at(0) == arestas.at(j).at(0) &&
                        arestas.at(i).at(1) == arestas.at(j).at(1)) || (arestas.at(i).at(0) == arestas.at(j).at(1) &&
                                arestas.at(i).at(1) == arestas.at(j).at(0)))
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
            if(arestas.at(j).at(0) == i+1)
            {
                cout<<arestas.at(j).at(1)<<" ";
                contador++;
            }
            else if(arestas.at(j).at(1) == i+1)
            {
                cout<<arestas.at(j).at(0)<<" ";
                contador++;
            }
            else if(j== nmrArestas-1 && contador == 0)
                cout<<"Vertice sem arestas";
        }
        cout<<" ]";
    }
}

void Questao1()
{
    srand((unsigned int)time(NULL));
    int a, v;
    v= 100;
    //Geração de 100 a 1000 vertices
    a = v + (v * (rand() % 9));
    GeraGrafo_Q1(a, v);
}

void Questao2() {}
void Questao3() {}
void Questao4() {}
void Questao5() {}
void Questao6() {}
void Questao7() {}
void Questao8() {}

int main()
{
    char questao;
    cout<<"Selecione a questao de 1 a 8: ";
    cin >> questao;

    switch (questao)
    {
    case '1':
        Questao1();
        break;

    case '2':
        Questao2();
        break;

    case '3':
        Questao3();
        break;

    case '4':
        Questao4();
        break;

    case '5':
        Questao5();
        break;

    case '6':
        Questao6();
        break;

    case '7':
        Questao7();
        break;

    case '8':
        Questao8();
        break;
    default :
        cout << "Questao invalida" << endl;
    }
}
