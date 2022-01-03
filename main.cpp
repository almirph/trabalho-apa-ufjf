#include<iostream>
#include<stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

vector<vector<int>> GeraGrafo_Q1(int nmrArestas, int nmrVertices)
{
    int i, j, contador;
    vector<vector<int>> arestas(nmrArestas, vector<int>(2));
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

    cout<<"\nGrafo aleatorio: \n";

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
        cout<<" ]\n";
    }

    return arestas;
}

vector<vector<int>> Questao1()
{
    srand((unsigned int)time(NULL));
    int a, v;
    v= 100;
    //Geração de 100 a 1000 vertices
    a = v + (v * (rand() % 9));
    return GeraGrafo_Q1(a, v);
}

vector<vector<int>> Questao2(vector<vector<int>> arestas)
{
    cout<<"\nMatriz de adjacencias: \n";
    int i, j, contador;
    vector<vector<int>> matriz(100, vector<int>(100, 0));
    for(i = 0; i < arestas.size(); i++)
    {
        matriz.at(arestas.at(i).at(0) - 1 ).at(arestas.at(i).at(1) - 1 ) = 1;
        matriz.at(arestas.at(i).at(1) - 1 ).at(arestas.at(i).at(0) - 1 ) = 1;
    }

    for(i = 0; i < 100; i++)
    {
        cout << " \n";
        for(j = 0; j < 100; j++)
        {
            cout << " " << matriz.at(i).at(j) << " ";
        }
    }

    return matriz;
}

void Questao3(vector<vector<int>> matriz)
{
    vector<int> vetor(4950);
    int i, j;
    int contador = 0;

    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            if(i < j)
            {
                vetor.at(contador) = matriz.at(i).at(j);
                contador ++;
            }
        }
    }

    cout<<"\nVetor Binario: \n";

    for(i=0; i<4950; i++)
    {
        cout<<" "<< vetor[i] << " ";
    }

}
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
        Questao2(Questao1());
        break;

    case '3':
        Questao3(Questao2(Questao1()));
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
