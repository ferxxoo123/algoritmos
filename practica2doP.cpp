/*
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

class BST {
private:
    Nodo* raiz;

    // Retorna la altura si está balanceado, o -1 si no lo está
    int esBalanceadoRecursivo(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzquierda = esBalanceadoRecursivo(nodo->izquierdo);
        if(alturaIzquierda == -1) {
            return -1;
        }
        int alturaDerecha = esBalanceadoRecursivo(nodo->derecho);
        if(alturaDerecha == -1){
            return -1;
        }
        int diferencia = abs(alturaIzquierda - alturaDerecha);
        if(diferencia > 1) {
            return -1;
        }
        return max(alturaIzquierda, alturaDerecha) + 1;
    }

public:
    BST() : raiz(nullptr){};

    bool esBalanceado(Nodo* raiz) {
        return esBalanceadoRecursivo(raiz) !=-1;

    }
};
*/

/*
#include <iostream>
#include <vector>

using namespace std;

class Grafo
{
private:
    int V;                         // Número de vértices
    vector<vector<int>> matrizAdj; // Matriz de adyacencia (1 si hay arista, 0 si no)

public:
    Grafo(int vertices)
    {
        V = vertices;
        matrizAdj.assign(vertices, vector<int>(vertices, 0));
    }

    void agregarArista(int u, int v)
    {
        matrizAdj[u][v] = 1; // Grafo DIRIGIDO (u apunta a v)
    }

    // Función miembro a probar
    bool formaParteDeTriangulo(int u);
};

// Implementación de la solución
bool Grafo::formaParteDeTriangulo(int u)
{
    if (u < 0 || u >= V)
    {
        return false;
    }

    for (int v = 0; v < V; ++v)
    {
        if (matrizAdj[u][v] == 1)
        {
            for (int w = 0; w < V; ++w)
            {
                if (matrizAdj[v][w] == 1 && matrizAdj[w][u] == 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
};

int main()
{
    Grafo g(4);
    g.agregarArista(0, 1);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0); // Forma un triángulo con 0, 1, 2
    g.agregarArista(2, 3);

    cout << "El vértice 0 forma parte de un triángulo: " << (g.formaParteDeTriangulo(0) ? "Sí" : "No") << endl;
    cout << "El vértice 3 forma parte de un triángulo: " << (g.formaParteDeTriangulo(3) ? "Sí" : "No") << endl;

    return 0;
}
*/

/*
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo);
    int contarHojas(nodo<T>* aux);

public:
    arbol() { raiz = NULL; };
    ~arbol() {};
    void CreaArbolBus(T x);
    int ContarHojas() { return contarHojas(raiz); }

};

template <class T> void arbol<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}
template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo)
{
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}
// SOLUCION AL PROBLEMA ------------------------------------------------
template <class T>
int arbol<T>::contarHojas(nodo<T>* aux)
{
    if (aux == NULL){
        return 0;
    }
    if (aux->izq == NULL && aux->der == NULL){
        return 1;
    }
    return contarHojas(aux->izq) + contarHojas(aux->der);
}
*/
/*
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

class BST {
    Nodo* raiz;
    bool esBSTValidoRecursivo(Nodo* nodo, Nodo*& prev);

public:
    BST(Nodo* r) : raiz(r) {}
    bool esBSTValido() {
        Nodo* prev = nullptr;
        return esBSTValidoRecursivo(raiz, prev);
    }
};

bool BST::esBSTValidoRecursivo(Nodo* nodo, Nodo*& prev) {
    if (nodo == nullptr) { // caso base: un árbol vacío es un BST válido
        return true;
    }

    if (!esBSTValidoRecursivo(nodo->izquierdo,prev)){ // recorrer el subárbol izquierdo
        return false;
    }

    if(prev != nullptr && nodo->valor <= prev->valor){ // verificar la propiedad del BST
        return false;
    }
    prev = nodo; // actualizar el nodo previo
    return esBSTValidoRecursivo(nodo->derecho,prev); // recorrer el subárbol derecho

}
*/

/*
#include <iostream>
#include <limits> // Para std::numeric_limits
using namespace std;

// Estructura para representar un nodo del ABB
struct Nodo
{
    int valor;
    Nodo *izquierda;
    Nodo *derecha;

    // Constructor de Nodo
    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para representar el Árbol Binario de Búsqueda (ABB)
class ABB
{
public:
    Nodo *raiz;

    // Constructor del ABB
    ABB() : raiz(nullptr) {}

    // Destructor del ABB para liberar la memoria
    ~ABB()
    {
        destruirArbol(raiz);
    }

    // Función auxiliar recursiva para liberar la memoria de los nodos
    void destruirArbol(Nodo *nodo)
    {
        if (nodo)
        {
            destruirArbol(nodo->izquierda);
            destruirArbol(nodo->derecha);
            delete nodo;
        }
    }

    // --- 1. Inserción de un nuevo valor en el ABB ---
    void insertar(int valor)
    {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Función auxiliar recursiva para insertar un valor
    Nodo *insertarRecursivo(Nodo *nodo, int valor)
    {
        // Si el subárbol está vacío, creamos un nuevo nodo aquí
        if (nodo == nullptr)
        {
            return new Nodo(valor);
        }

        // Si el valor es menor, vamos a la izquierda
        if (valor < nodo->valor)
        {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        }
        // Si el valor es mayor, vamos a la derecha
        else if (valor > nodo->valor)
        {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        // Si el valor es igual, ya existe y no lo insertamos (no permitimos duplicados)
        return nodo; // Retorna el nodo actual sin cambios si es un duplicado
    }

    // --- 2. Encontrar el valor mínimo en el ABB ---
    int encontrarMinimo()
    {
        if (raiz == nullptr)
        {
            throw std::runtime_error("El árbol está vacío");
        }
        Nodo *actual = raiz;
        while (actual->izquierda != nullptr)
        {
            actual = actual->izquierda;
        }
        return actual->valor;
    }

    // --- 3. Encontrar el valor máximo en el ABB ---
    int encontrarMaximo()
    {

        if (raiz == nullptr)
        {
            throw std::runtime_error("El árbol está vacío");
        }
        Nodo *actual = raiz;
        while (actual->derecha != nullptr)
        {
            actual = actual->derecha;
        }
        return actual->valor;
    }

    // Función auxiliar para imprimir el árbol en orden (opcional, para verificación)
    void recorrerInorden()
    {
        std::cout << "Elementos del ABB (Inorden): ";
        recorrerInordenRecursivo(raiz);
        std::cout << std::endl;
    }

    void recorrerInordenRecursivo(Nodo *nodo)
    {
        if (nodo != nullptr)
        {
            recorrerInordenRecursivo(nodo->izquierda);
            std::cout << nodo->valor << " ";
            recorrerInordenRecursivo(nodo->derecha);
        }
    }
};
*/

/*
template <class T>
Nodo<T>* ABB<T>::predecessorHelper(Nodo<T>* p, T x){
    Nodo<T>* best = nullptr;

    while(p != nullptr){
    if(p->dato < x){
        best = p;
        p = p->der;
    } else {
        p = p->izq;
    }
}
return best;
}
*/
/*
template <class T>
void ABB<T>::rangoRec(Nodo<T> *p, T a, T b, vector<T> &out)
{
    if (p == nullptr)
        return;

    if (a < p->dato)
    {
        rangoRec(p->izq, a, b, out);
    }
    if (!(p->dato < a) && !(b < p->dato))
    {
        out.push_back(p->dato);
    }
    if (p->dato < b)
    {
        rangoRec(p->der, a, b, out);
    }
}
*/