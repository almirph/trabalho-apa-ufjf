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

vector<int> Questao3(vector<vector<int>> matriz)
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

    cout<<"\n\nVetor Binario: \n\n";

    for(i=0; i<4950; i++)
    {
        cout<<" "<< vetor[i] << " ";
    }

    return vetor;

}
vector<int> Questao4(vector<int> vetorBinario)
{
    int i;
    int contador = 0;
    int vetorCompactadoSize = 0;

    for(i=0; i<4950; i++)
    {
        vetorCompactadoSize =  vetorCompactadoSize + vetorBinario.at(i);
    }

    vector<int> vetorCompactado(vetorCompactadoSize);

    for(i=0; i<4950; i++)
    {
        if(vetorBinario.at(i) == 1)
        {
            vetorCompactado.at(contador) = i + 1;
            contador++;
        }
    }

    cout<<"\n\nVetor Compactado: \n\n";

    for(i = 0; i< vetorCompactadoSize; i++)
    {
        cout<<" "<< vetorCompactado.at(i) << " ";
    }

    return vetorCompactado;

}

void Questao5(vector<int> vetorCompactado)
{
    int i, j;
    int contadorValVetorCompactado = 0;
    int contadorPosVetorCompactado = 0;
    vector<vector<int>> matriz(100, vector<int>(100, 0));

    for(i = 0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            if(i < j)
            {
                contadorValVetorCompactado ++;
            }
            if(contadorPosVetorCompactado > vetorCompactado.size() - 1)
            {
                break;
            }
            if(vetorCompactado.at(contadorPosVetorCompactado) == contadorValVetorCompactado)
            {
                matriz.at(i).at(j) = 1;
                matriz.at(j).at(i) = 1;
                contadorPosVetorCompactado ++;
            }

        }
        if(contadorPosVetorCompactado > vetorCompactado.size())
        {
            break;
        }
    }

    cout<<"\n\nNova Matriz: \n";

    for(i = 0; i < 100; i++)
    {
        cout << " \n";
        for(j = 0; j < 100; j++)
        {
            cout << " " << matriz.at(i).at(j) << " ";
        }
    }

}
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
        Questao4(Questao3(Questao2(Questao1())));
        break;

    case '5':
        Questao5(Questao4(Questao3(Questao2(Questao1()))));
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
