// Página 217 - Alfred V. Aho, 1988, Addison Wesley
// Búsqueda en Profundidad (DFS)
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const int INFI = 9000;
const int MAXNODOS = 5;
const int NO_VISITADO = 0;
const int VISITADO = 1;

void DFS(int v, int peso[][MAXNODOS], int marca[]);

int main()
{
    int peso[MAXNODOS][MAXNODOS] = {
        {INFI, 1, 1, 1, INFI},
        {INFI, INFI, 1, 1, INFI},
        {INFI, INFI, INFI, 1, INFI},
        {INFI, INFI, INFI, INFI, 1},
        {INFI, INFI, INFI, INFI, INFI}};
    int marca[MAXNODOS];

    for (int i = 0; i < MAXNODOS; i++)
        marca[i] = NO_VISITADO;

    DFS(0, peso, marca);

    cout << endl
         << "Matriz de pesos";
    for (int i = 0; i < MAXNODOS; i++)
    {
        cout << "\n";
        for (int j = 0; j < MAXNODOS; j++)
        {
            cout << " " << setw(5) << peso[i][j];
        }
    }

    cout << endl
         << "Arreglo de marcas" << endl;
    for (int i = 0; i < MAXNODOS; i++)
    {
        cout << i << "  " << marca[i] << endl;
    }

    cout << endl;
    return EXIT_SUCCESS;
}

void DFS(int v, int peso[][MAXNODOS], int marca[])
{
    marca[v] = VISITADO;
    cout << "v=" << v << endl;

    for (int w = 0; w < MAXNODOS; w++)
    {
        if (peso[v][w] == 1 && marca[w] == NO_VISITADO)
            DFS(w, peso, marca);
    }
}