// Busqueda en Amplitud BFS y Ordenamiento Topologico
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#define INFI 9000
#define MAXNODOS 5
#define no_visitado 0
#define visitado 1
#define MAX 10

using namespace std;

// almacena MAX-1 elementos
// cola circular
class Cola
{
private:
    int Q[MAX];
    int pi, pf;

public:
    Cola(void)
    {
        pi = 0;
        pf = MAX - 1;
    };
    int tope() { return Q[pi]; };
    bool colavacia() { return pi == (pf + 1) % MAX; };
    bool colallena() { return pi == (pf + 2) % MAX; };
    void encolar(int a);
    void desencolar();
    int ultimo();
    string imprimir(string s);
};

//-------- Metodos de Cola --------------------
void Cola::encolar(int a)
{
    if (!colallena())
    {
        pf = (pf + 1) % MAX;
        Q[pf] = a;
    }
    else
        cout << "Cola llena" << endl;
}

void Cola::desencolar(void)
{
    if (!colavacia())
        pi = (pi + 1) % MAX;
    else
        cout << "Cola vacia" << endl;
}

int Cola::ultimo(void)
{
    return Q[pf];
}

string Cola::imprimir(string s)
{
    if (!colavacia())
    {
        // by Martin
        for (int i = pi; i != pf + 1; i = (i + 1) % MAX)
            cout << Q[i] << "--";
    }

    return " <<< Q";
}
//------------------------------------------------------

void BFS(int x, int peso[][MAXNODOS], int marca[]);
bool TLS(int peso[][MAXNODOS], int orden[]);

int main()
{
    int peso[MAXNODOS][MAXNODOS] = {
        {INFI, 1, 1, 1, INFI},
        {INFI, INFI, 1, 1, INFI},
        {INFI, INFI, INFI, 1, INFI},
        {INFI, INFI, INFI, INFI, 1},
        {INFI, INFI, INFI, INFI, INFI}};
    int marca[MAXNODOS];
    int orden[MAXNODOS];

    for (int i = 0; i < MAXNODOS; i++)
        marca[i] = no_visitado;

    BFS(3, peso, marca);

    cout << endl
         << "Matriz de pesos";
    for (int i = 0; i < MAXNODOS; i++)
    {
        cout << "\n";
        for (int j = 0; j < MAXNODOS; j++)
        {
            printf(" %5i", peso[i][j]);
        }
    }

    cout << endl
         << "Arreglo de marcas" << endl;
    for (int i = 0; i < MAXNODOS; i++)
    {
        cout << i << "  " << marca[i] << endl;
    }

    cout << endl
         << "Ordenamiento topologico:";
    if (TLS(peso, orden))
    {
        for (int i = 0; i < MAXNODOS; i++)
            cout << " " << orden[i];
        cout << endl;
    }
    else
    {
        cout << " el grafo tiene un ciclo" << endl;
    }

    cout << endl
         << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

// algoritmo como el del pseudocodigo
void BFS(int x, int peso[][MAXNODOS], int marca[])
{
    int y;
    Cola Q;

    marca[x] = visitado;
    Q.encolar(x);
    while (!Q.colavacia())
    {
        x = Q.tope();
        Q.desencolar();
        cout << "x=" << x << endl;
        for (y = 0; y < MAXNODOS; y++)
        {
            if ((peso[x][y] == 1) && (marca[y] == no_visitado))
            { // si tengo arista y marca como que no lo visite
                marca[y] = visitado;
                Q.encolar(y);
            }
        } // fin for y
    } // fin while
}

// Devuelve true si se pudo ordenar, false si hay ciclo.
// El orden queda guardado en orden[].
bool TLS(int peso[][MAXNODOS], int orden[])
{
    int gradoEntrada[MAXNODOS];
    Cola Q;
    int v = 0; // cantidad de vertices ya ordenados

    // calcula el grado de entrada
    for (int j = 0; j < MAXNODOS; j++)
    {
        gradoEntrada[j] = 0;
        for (int i = 0; i < MAXNODOS; i++)
        {
            if (peso[i][j] == 1)
                gradoEntrada[j]++;
        }
    }

    // encola los de grado 0
    for (int i = 0; i < MAXNODOS; i++)
    {
        if (gradoEntrada[i] == 0)
            Q.encolar(i);
    }

    while (!Q.colavacia())
    {
        int x = Q.tope();
        Q.desencolar();
        orden[v] = x;
        v++;

        for (int y = 0; y < MAXNODOS; y++)
        {
            if (peso[x][y] == 1)
            {
                gradoEntrada[y]--;
                if (gradoEntrada[y] == 0)
                    Q.encolar(y);
            }
        }
    }
    return v == MAXNODOS;
}