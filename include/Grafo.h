#ifndef GRAFO_H
#define GRAFO_H


class Grafo
{
public:
    Grafo(int nmrAresta, int nmrVertice);

    int getNmrAresta();

    void setNmrAresta(int nmrAresta);

    int getNmrVertice();

    void setNmrVertice(int nmrVertice);

    virtual ~Grafo();

protected:

private:

    int nmrAresta;
    int nmrVertice;
};

#endif // GRAFO_H
