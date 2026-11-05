#include <iostream>
#include <set>

using namespace std;

// Tamaño máximo reservado para arreglos unidimensionales y matriz
const int MAX_V = 100;

// Constante para representar un valor infinito (ausencia de arista)
const int INF = 9999999;

/*
 V Número total de vértices.
 w Matriz de adyacencia de dimensión MAX_V x MAX_V.
 s Vértice inicial/raíz.
 d Arreglo unidimensional para almacenar el peso mínimo de entrada d[v].
 p Arreglo unidimensional para almacenar los predecesores p[v].
*/
void prim(int V, int w[MAX_V][MAX_V], int s, int d[MAX_V], int p[MAX_V])
{
    set<int> S;   // Conjunto S
    set<int> V_S; // Conjunto V - S

    // 1. Initialize S with the start vertex, s, and V - S with the remaining vertices.
    S.insert(s);
    d[s] = 0;  // costo o distancia
    p[s] = -1; // El nodo de inicio no tiene predecesor en el MST (predecesor)

    for (int v = 0; v < V; ++v)
    {
        if (v != s)
        {
            V_S.insert(v);
        }
    }

    // 2. for all v in V - S
    for (int v : V_S)
    {
        // 3. Set p[v] to s.
        p[v] = s;

        // 4. if there is an edge (s, v)
        if (w[s][v] != INF)
        {
            // 5. Set d[v] to w(s, v).
            d[v] = w[s][v]; // pongo las distancias si las tengo, si no las pongo en infinito
        }
        else
        {
            // 6. Set d[v] to infinity.
            d[v] = INF;
        }
    }

    // Impresión inicial de la tabla
    cout << "v\td[v]\tp[v]\n";
    cout << "-------------------\n";
    for (int v = 0; v < V; ++v)
    {
        cout << v << "\t";
        if (d[v] == INF)
        {
            cout << "INF";
        }
        else
        {
            cout << d[v];
        }
        cout << "\t" << p[v] << "\n";
    }
    cout << endl
         << endl;

    // 7. while V - S is not empty
    while (!V_S.empty())
    {
        // 8. for all u in V - S, find the smallest d[u].
        int u = -1;
        int min_d = INF;

        for (int v : V_S)
        {
            if (d[v] < min_d)
            {
                min_d = d[v];
                u = v;
            }
        }

        // Si los vértices restantes en V - S no son alcanzables, se interrumpe
        if (u == -1)
            break;

        // 9. Remove u from V - S and add it to S.
        V_S.erase(u);
        S.insert(u);

        // 10. Insert the edge (u, p[u]) into the spanning tree.
        // La arista (u, p[u]) ya queda representada permanentemente por p[u] y d[u]

        // 11. for all v in V - S
        for (int v : V_S)
        {
            // 12. if w(u, v) < d[v]
            if (w[u][v] < d[v])
            {
                // 13. Set d[v] to w(u, v).
                d[v] = w[u][v];
                // 14. Set p[v] to u.
                p[v] = u;
            } // fin if
        } // fin for

        /* // Impresión de la tabla
        cout << "v\td[v]\tp[v]\n";
        cout << u << "-------------------\n";
        for (int v = 0; v < V; ++v)
        {
            cout << v << "\t";
            if (d[v] == INF)
            {
                cout << "INF";
            }
            else
            {
                cout << d[v];
            }
            cout << "\t" << p[v] << "\n";
        }
        cout << endl
             << endl;
*/
    } // fin while
}

int main()
{
    int V = 6;
    int s = 5; // Vértice inicial

    // Inicialización de la matriz de pesos con INF o 0 en la diagonal
    int w[MAX_V][MAX_V];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            w[i][j] = INF; // (i == j) ? 0 : INF;
        }
    }

    // Grafo no dirigido (matriz simétrica)
    w[0][1] = w[1][0] = 6;
    w[0][2] = w[2][0] = 10;
    w[0][3] = w[3][0] = 5;
    w[1][2] = w[2][1] = 5;
    w[1][4] = w[4][1] = 3;
    w[2][3] = w[3][2] = 5;
    w[2][4] = w[4][2] = 6;
    w[2][5] = w[5][2] = 4;
    w[3][5] = w[5][3] = 2;
    w[4][5] = w[5][4] = 5;

    int d[MAX_V];
    int p[MAX_V];

    prim(V, w, s, d, p);

    // Impresión de las aristas del Árbol de Expansión Mínima (MST)
    cout << "Arista \t\tPeso\n";
    cout << "-------------------------\n";
    int peso_total = 0;
    for (int v = 0; v < V; ++v)
    {
        if (v == s)
        {
            cout << v << " (Raiz)\t-\n";
        }
        else
        {
            cout << "(" << v << ", " << p[v] << ")\t\t" << d[v] << "\n";
            if (d[v] != INF)
                peso_total += d[v];
        }
    }
    cout << "-------------------------\n";
    cout << "Peso total del MST: " << peso_total << "\n";

    return 0;
}