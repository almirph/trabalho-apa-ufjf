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

int indiceRecursao_Q6(int linha, int coluna, int i, int j, int contador)
{
    if(j > i)
    {
        contador ++;
    }
    if(linha == i && coluna == j)
    {
        return contador;
    }
    if(j == 100)
    {
        return indiceRecursao_Q6(linha, coluna, i + 1, 0, contador);
    }
    else
    {
        return indiceRecursao_Q6(linha, coluna, i, j + 1, contador);
    }
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
void Questao6()
{
    int linha, coluna, i, j;
    int n = 100;
    int contadorIteracao = 0;
    bool chegou = false;

    cout<<"\nPara o tratamento do vetor de indices da matriz triangular superior o indice j deve ser maior que o indice i.";
    cout<<"\nInsira a linha i entre 1 e 100: ";
    cin>>linha;
    cout<<"\nInsira a coluna j entre 1 e 100: ";
    cin>>coluna;

    if(linha > coluna || linha < 1 || linha > 100 || coluna <1 || coluna > 100)
    {
        cout<<"Entrada invalida";
        return;
    }

    int calculo = linha * n - n - ((linha*(linha-1))/2) + (coluna-linha);
    cout<<"\nPosicao no vetor por CALCULO: "<< calculo;

    for(i = 1; i<= 100 && !chegou; i ++)
    {
        for(j = 1; j<= 100 && !chegou; j ++)
        {
            if(j > i && !chegou)
            {
                contadorIteracao ++;
            }
            if(linha == i && coluna == j)
            {
                chegou = true;
            }
        }
    }

    cout<<"\nPosicao no vetor por ITERACAO: "<< contadorIteracao;

    cout<<"\nPosicao no vetor por RECURSAO: "<< indiceRecursao_Q6(linha, coluna, 1,1,0);



}
void Questao7(vector<int> vetorCompactado)
{
    int i, j;
    int contador = 1;
    int posicao = 0;
    bool achou = false;

    cout<<"\n\nDigite a posicao do vetor de 0 a "<<vetorCompactado.size() - 1<<" : ";
    cin>>posicao;
    if(!(posicao >= 0 && posicao < vetorCompactado.size())){
        cout<<"\nPosicao invalida.";
        return;
    }

    for(i=0; i<100; i++)
    {
        for(j=0; j<100 && !achou; j++)
        {
            if(i<j)
            {
                contador ++;
            }
            if(contador == vetorCompactado.at(posicao))
            {
                cout<<"\n\nLinha e coluna da matriz na posicao "<<posicao<<" :";
                cout<<"\ni="<<i<<"\nj="<<j;
                achou = true;
            }

        }
    }

}
void Questao8()
{
    int i, j, k;
    int matrizSize = 10;
    int vetSize = 45;
    int vetCont = 0;
    vector<vector<int>> matriz1(matrizSize, vector<int>(matrizSize, 0));
    vector<vector<int>> matriz2(matrizSize, vector<int>(matrizSize, 0));
    vector<vector<int>> matrizProduto(matrizSize, vector<int>(matrizSize, 0));
    vector<int> vetorMat1(vetSize);
    vector<int> vetorMat2(vetSize);
    vector<int> vetorMatSoma(vetSize);


    for(i=0; i<matrizSize; i++)
    {
        for(j=0; j<matrizSize; j++)
        {
            if(i < j)
            {
                matriz1.at(i).at(j) = rand() % 100;
                matriz1.at(j).at(i) = matriz1.at(i).at(j);
                matriz2.at(i).at(j) = rand() % 100;
                matriz2.at(j).at(i) = matriz2.at(i).at(j);

                vetorMat1.at(vetCont) = matriz1.at(i).at(j);
                vetorMat2.at(vetCont) = matriz2.at(i).at(j);

                vetCont ++;
            }

        }
    }

    cout<<"\nMatriz 1: \n";
    for(i=0; i<matrizSize; i++)
    {
        for(j=0; j<matrizSize; j++)
        {
            cout<<" "<<matriz1.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nMatriz 2: \n";
    for(i=0; i<matrizSize; i++)
    {
        for(j=0; j<matrizSize; j++)
        {
            cout<<" "<<matriz2.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nVetor da Matriz 1: \n";
    for(i = 0; i< vetSize; i++)
    {
        cout<<" "<<vetorMat1.at(i)<<" ";
    }

    cout<<"\nVetor da Matriz 2: \n";
    for(i = 0; i< vetSize; i++)
    {
        cout<<" "<<vetorMat2.at(i)<<" ";
    }

    for(i = 0; i< vetSize; i++)
    {
        vetorMatSoma.at(i) = vetorMat1.at(i) + vetorMat2.at(i);
    }

    cout<<"\nSoma da Matriz 1 + 2: \n";

    for(i = 0; i< vetSize; i++)
    {
        cout<<" "<<vetorMatSoma.at(i)<<" ";
    }

    cout<<"\nProduto da Matriz 1 * 2: \n";

    for(i = 0; i< matrizSize; i++)
    {
        for(j = 0; j<matrizSize; j++)
        {
            for(k = 0; k< 10; k++)
            {
                matrizProduto.at(i).at(j) = matrizProduto.at(i).at(j) + (matriz1.at(i).at(k) * matriz2.at(k).at(j));
            }
        }
    }

    for(i = 0; i< matrizSize; i++)
    {
        for(j = 0; j<matrizSize; j++)
        {
            cout<<" "<<matrizProduto.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }
}

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
    {
        Questao7(Questao4(Questao3(Questao2(Questao1()))));
        break;
    }


    case '8':
        Questao8();
        break;
    default :
        cout << "Questao invalida" << endl;
    }
}
