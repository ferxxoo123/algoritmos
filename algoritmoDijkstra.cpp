#include <iostream>
#include <set>

using namespace std;

// Tamaño máximo de vértices para los arreglos
const int MAX_V = 100;

// Valor grande definido manualmente para representar el infinito
const int INF = 9999999;

/*
 V Número total de vértices.
 w Matriz de pesos del grafo de dimensión MAX_V x MAX_V.
 s Vértice origen.
 d Arreglo para almacenar las distancias mínimas d[v].
 p Arreglo para almacenar los predecesores p[v].
*/
void dijkstra(int V, int w[MAX_V][MAX_V], int s, int d[MAX_V], int p[MAX_V])
{
    set<int> S;   // Conjunto S
    set<int> V_S; // Conjunto V - S

    // 1. Initialize S with the start vertex, s, and V - S with the remaining vertices.
    S.insert(s);
    d[s] = 0;
    p[s] = -1;

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
            d[v] = w[s][v];
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

        // Si los vértices restantes en V - S son inalcanzables, se interrumpe
        if (u == -1)
            break;

        // 9. Remove u from V - S and add u to S.
        V_S.erase(u);
        S.insert(u);

        // 10. for all v adjacent to u in V - S
        for (int v : V_S)
        {
            // Comprobar si existe arista entre u y v
            if (w[u][v] != INF)
            {
                // 11. if d[u] + w(u, v) is less than d[v]
                if (d[u] != INF && d[u] + w[u][v] < d[v])
                {
                    // 12. Set d[v] to d[u] + w(u, v).
                    d[v] = d[u] + w[u][v];
                    // 13. Set p[v] to u.
                    p[v] = u;
                } // fin if
            } // fin if
        } // fin for v
    } // fin while
}

void camino(int P[], int s, int t)
{
    if (t == s)
        cout << s << "  ";
    else
    {
        camino(P, s, P[t]);
        cout << t << "  ";
    }
}

int main()
{
    int V = 5;
    int s = 0; // Vértice inicial

    // Inicializamos la matriz de pesos con INF
    int w[MAX_V][MAX_V];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            w[i][j] = INF; //(i == j) ? 0 : INF;
        }
    }

    // Definición de las aristas del grafo
    w[0][1] = 10;
    w[0][3] = 30;
    w[0][4] = 100;
    w[1][2] = 50;
    w[2][4] = 10;
    w[3][2] = 20;
    w[3][4] = 60;

    int d[MAX_V];
    int p[MAX_V];

    dijkstra(V, w, s, d, p);

    // Impresión del resultado de la tabla
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
    int t = 4; // vertice final
    cout << "Camino para ir de " << s << " hasta " << t << endl;
    camino(p, s, t);

    return 0;
}