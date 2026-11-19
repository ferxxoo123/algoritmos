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
/*template <class T>
Nodo<T>* ABB<T>::lowerBoundHelper(Nodo<T>* p, T x){
    Nodo<T>* best = nullptr;

    while (p != nullptr){
        if(x < p->dato){
            best = p;
            p=p->izq;
        }else {
            p = p->der;
        }
    }
    return best;

}*/

/*template <class T>
int ABB<T>::tamRec(const Nodo<T>* p) const{
    if (p == nullptr){
        return 0;
    }

    if(!tamRec(p->izq)){
        return 1;
    }
    return tamRec(p->der) + tamRec(p->izq) + 1;

}

template <class T>
int ABB<T>::size() const{
    return tamRec(raiz);
}
*/
/*template <class T>
const Nodo<T>* ABB<T>::minNode(const Nodo<T>* p) const{
    if (p == nullptr){
         throw std::runtime_error("Arbol vacio");
        }
        const Nodo<T>* actual = p;
        while(actual->izq != nullptr){
            actual=actual->izq;
        }
        return actual;

}

template <class T>
const Nodo<T>* ABB<T>::maxNode(const Nodo<T>* p) const{
    if (p == nullptr){
          throw std::runtime_error("Arbol vacio");
        }
       const Nodo<T>* actual = p;
        while(actual->der != nullptr){
            actual=actual->der;
        }
        return actual;

}

// Wrappers públicos que devuelven referencias a T
template <class T>
const T& ABB<T>::min() const{
    return minNode(raiz)->dato;
}

template <class T>
const T& ABB<T>::max() const{
    return maxNode(raiz)->dato;
}
*/
/*template <class T>
void ABB<T>::inordenRec(const Nodo<T>* p, std::vector<T>& out) const{
    if(p != nullptr){

        inordenRec(p->izq, out);
        out.push_back(p->dato);
        inordenRec(p->der, out);
    }
}

template <class T>
std::vector<T> ABB<T>::inorden() const{
    std::vector<T> u;
    u.reserve(size());
    inordenRec(raiz, u);
    return u;
}
*/
/*template <class T>
int ABB<T>::alturaRec(const Nodo<T>* p) const{
    if (p == nullptr){
        return 0;
    }
    return 1 + std::max(alturaRec(p->izq), alturaRec(p->der));


}

template <class T>
int ABB<T>::height() const{
    return alturaRec(raiz);
}
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

    for (int v = 0; v < V; v++){
        if(v == u) continue;
        if(matrizAdj[u][v] == 1){
            for(int w = 0; w < V; w++){
                if (w == u || w == v) continue;
                if(matrizAdj[v][w] == 1 && matrizAdj[w][u] == 1){
                    return true;
                }
            }
        }
    }
    return false;


}
*/
/*
#include <iostream>
#include <vector>

class RedDeSensores {
public:
    RedDeSensores(int cantidadModulos) {
        cantidad = cantidadModulos;
        adyacencias.resize(cantidad, std::vector<int>(cantidad, 0));
    }

    void agregarConexion(int a, int b) {
        if (a >= 0 && a < cantidad && b >= 0 && b < cantidad){
            adyacencias[a][b]++;
            if(a!= b){
            adyacencias[b][a]++;
            }
        }
    }

    void imprimirConexion(int a, int b) {
        if (a >= 0 && a < cantidad && b >= 0 && b < cantidad) {
            std::cout << "Conexion directa (" << a << " - " << b << "): " << adyacencias[a][b] << std::endl;
        } else {
            std::cout << "módulo fuera de rango" << std::endl;
        }
    }

    void imprimirAlcanzables(int desde) {
        if (desde < 0 || desde >= cantidad){
            std::cout << "modulo fuera de rango" << std::endl;
            return;
        }
        std::vector<bool> visitado (cantidad,false);
        std::vector<int> alcanzables;
        DFS(desde, visitado, alcanzables);
        std::cout << "Módulos alcanzables desde " << desde << ": ";
        for (int mod : alcanzables){
            std::cout << mod << " ";
        }
        std::cout << std::endl;
    }

private:
    int cantidad;
    std::vector<std::vector<int>> adyacencias;
    void DFS(int nodo, std::vector <bool>& visitado, std::vector<int>& alcanzables){

        visitado[nodo] = true;
        alcanzables.push_back(nodo);
        for(int i = 0; i < cantidad; i++){
            if (adyacencias[nodo][i] > 0&& !visitado[i]){
                DFS(i, visitado, alcanzables);
            }
        }
    }
};
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>    // Para BFS

// Clase para representar el grafo de ciudades
class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id; // Mapea nombres de ciudades a IDs numéricos
    std::vector<std::string> id_a_ciudad;   // Mapea IDs numéricos a nombres de ciudades
    std::vector<std::vector<int>> adj;      // Lista de adyacencia

    GrafoCiudades() {}

    // Agrega una ciudad al grafo
    void agregarCiudad(const std::string& ciudad) {
        if(ciudad_a_id.find(ciudad) != ciudad_a_id.end()){
            return;
        }

        if (ciudad_a_id.find(ciudad) == ciudad_a_id.end()){
            int id = ciudad_a_id.size();
            ciudad_a_id[ciudad]=id;
            id_a_ciudad.push_back(ciudad);
            adj.push_back(std::vector<int>());
        }
    }

    // Agrega una carretera (arista) no dirigida entre dos ciudades
    void agregarCarretera(const std::string& ciudad1, const std::string& ciudad2) {
        agregarCiudad(ciudad1);
        agregarCiudad(ciudad2);

        int id1 = ciudad_a_id[ciudad1];
        int id2 = ciudad_a_id[ciudad2];
        adj[id1].push_back(id2);
        if (id1 != id2){
            adj[id2].push_back(id1);
        }

    }
    // Encuentra el camino más corto (en cantidad de saltos) usando BFS
    // Devuelve la cantidad de saltos. Si no hay conexión, devuelve -1.
    int obtenerCaminoMasCorto(const std::string& ciudadA, const std::string& ciudadB) {
        auto itA = ciudad_a_id.find(ciudadA);
        auto itB = ciudad_a_id.find(ciudadB);

        // si alguna ciudad no existe
        if(itA == ciudad_a_id.end() || itB == ciudad_a_id.end()){
            return -1;
        }

        int origen = itA->second;
        int destino = itB->second;

        if(origen == destino) {
            return 0;
        }

        std::vector<int> distancia(adj.size(), -1);
        std::queue<int> cola;

        distancia[origen] = 0;
        cola.push(origen);

        while(!cola.empty()){
            int actual = cola.front();
            cola.pop();

            for (int vecino : adj[actual]){
                if (distancia[vecino] == -1){
                    distancia[vecino] = distancia[actual] + 1;
                    if(vecino == destino)
                    {
                      return distancia[vecino];
                    }
                    cola.push(vecino);
                 }
            }
        }

    return -1;
};

};
*/
/*
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

const int INF = 1e9; // Representación de infinito

class Grafo {
private:
    int V;
    vector<list<pair<int, int>>> listaAdj;

    // Función auxiliar privada
    int dijkstraAux(int origen, int destino) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[origen] = 0;
        pq.push({0, origen});

        while (!pq.empty()) {
            int costoActual = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == destino) return costoActual;
            if (costoActual > dist[u]) continue;

            for (auto arista : listaAdj[u]) {
                int v = arista.first;
                int peso = arista.second;

                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[destino] == INF ? -1 : dist[destino];
    }

public:
    Grafo(int vertices) {
        V = vertices;
        listaAdj.resize(vertices);
    }

    void agregarArista(int u, int v, int costo) {
        listaAdj[u].push_back({v, costo}); // Grafo dirigido
    }

    // Función principal a evaluar
    int viajeConEscalaObligatoria(int origen, int escala, int destino) {
        int costoOrigenAEscala = dijkstraAux(origen, escala);
        if(costoOrigenAEscala == -1){
            return -1;
        }
        int costoEscalaADestino = dijkstraAux(escala, destino);
        if(costoEscalaADestino == -1){
            return -1;
        }
        return costoOrigenAEscala + costoEscalaADestino;
}
};
*/
/*
#include <iostream>
#include <vector>

using namespace std;

enum Estado { VACIO, OCUPADO, BORRADO };

struct Celda {
    int clave;
    Estado estado;
};

class Hash {
private:
    int capacidad;
    vector<Celda> tabla;

    int funcionHash(int clave) {
        return clave % capacidad;
    }

public:
    Hash(int cap) {
        capacidad = cap;
        tabla.assign(capacidad, {0, VACIO});
    }

    void insertar(int clave) {
        int indice = funcionHash(clave);
        int inicio = indice;

        // Iteramos mientras la celda esté ocupada
        while (tabla[indice].estado == OCUPADO) {
            if (tabla[indice].clave == clave) return; // Evitar duplicados
            indice = (indice + 1) % capacidad;
            if (indice == inicio) return; // Tabla llena
        }

        tabla[indice].clave = clave;
        tabla[indice].estado = OCUPADO;
    }

    // Función miembro a evaluar
    bool eliminar(int clave);
};

// Implementación de la solución
bool Hash::eliminar(int clave) {
    int indice = funcionHash(clave);

    while(tabla[indice].estado != VACIO){
       if(tabla[indice].estado == OCUPADO && tabla[indice].clave == clave){
        tabla[indice].estado = BORRADO;
        return true;
       }
       indice = (indice +1) % capacidad;
    }
    return false;

}
*/
/*#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class RedDeSensores {
private:
    map<string, vector<string>> grafo;

public:
    // Agrega una conexión bidireccional entre dos módulos
    void agregarConexion(const string& a, const string& b) {
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    // Devuelve true si existe conexión directa entre a y b
    bool estanConectados(const string& a, const string& b) {
        auto it = grafo.find(a);
        if(it == grafo.end()){
            return false;
        }
    const vector<string>& vecinos = it->second;
    return find(vecinos.begin(), vecinos.end(),b) != vecinos.end();

    }

    // Devuelve cuántos módulos son alcanzables desde el módulo de inicio (incluido), usando DFS
    int alcanzablesDesde(const string& inicio) {
        if (grafo.find(inicio)==grafo.end()){
            return 1;
        }
        set<string> visitados;
        dfs(inicio,visitados);
        return visitados.size();

    }

private:
    void dfs(const string& actual, set<string>& visitados) {
        visitados.insert(actual);

        for(const string& vecino : grafo[actual]){
            if(visitados.find(vecino)==visitados.end()){
                dfs(vecino, visitados);
            }
        }
    }
};*/
/*std::vector<std::string> RedSocial::gradosDeSeparacion(const std::string& inicio, const std::string& fin) {
    std::vector<std::string> camino;

    if (adj.find(inicio) == adj.end() || adj.find(fin) == adj.end()) {
        return camino;                       // vacío si alguna no existe
    }

    if (inicio == fin) {
        camino.push_back(inicio);
        return camino;
    }

    std::map<std::string, std::string> padre;   // hijo -> quien lo descubrió (sirve también de visitados)
    std::queue<std::string> cola;

    padre[inicio] = "";
    cola.push(inicio);

    while (!cola.empty()) {
        std::string actual = cola.front();
        cola.pop();

        for (const std::string& vecino : adj[actual]) {
            if (padre.find(vecino) == padre.end()) {
                padre[vecino] = actual;
                if (vecino == fin) {
                    // reconstruir el camino hacia atrás
                    std::string p = fin;
                    while (p != "") {
                        camino.push_back(p);
                        p = padre[p];
                    }
                    std::reverse(camino.begin(), camino.end());
                    return camino;
                }
                cola.push(vecino);
            }
        }
    }

    return camino;                           // vacío: no hay conexión
}*/
/*
#include <iostream>
#include <vector>

class RedDeSensores {
public:
    RedDeSensores(int cantidadModulos) {
    cantidad = cantidadModulos;
    adyacencias.assign(cantidad,std::vector<int>(cantidad,0));
    }

    void agregarConexion(int a, int b) {
     if(a >= 0 && a < cantidad && b>=0 && b < cantidad){
         adyacencias[a][b]++;
         if(a!= b){
             adyacencias[b][a]++;
         }
     }
}

   void imprimirConexion(int a, int b) {
    if (a >= 0 && a < cantidad && b >= 0 && b < cantidad) {
        std::cout << "Conexion directa (" << a << " - " << b << "): "
                  << adyacencias[a][b] << std::endl;
    }
}

    void imprimirAlcanzables(int desde) {
        if( desde < 0 || desde >= cantidad ){
            return;
        }
        std::vector<bool> visitado(cantidad, false);
        std::vector<int> pila;
        int contador = 0;

        pila.push_back(desde);
        visitado[desde] = true;

        while(!pila.empty()){
            int nodo = pila.back();
            pila.pop_back();
            contador++;

            for(int w=0; w < cantidad; w++){
                if(adyacencias[nodo][w] > 0 && !visitado[w]){
                    visitado[w] = true;
                    pila.push_back(w);
                }
            }
        }

     std::cout << "Modulos alcanzables desde " << desde << ": "
              << contador << std::endl;


    }

private:
    int cantidad;
    std::vector<std::vector<int>> adyacencias;

};
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue> // Para BFS

// Clase para representar el grafo
class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id; // Mapea nombres de ciudades a IDs numéricos
    std::vector<std::string> id_a_ciudad;   // Mapea IDs numéricos a nombres de ciudades
    std::vector<std::vector<int>> adj;      // Lista de adyacencia

    GrafoCiudades() {}

    // Agrega una ciudad al grafo
    void agregarCiudad(const std::string& ciudad) {
        if (ciudad_a_id.find(ciudad) != ciudad_a_id.end()){
            return;
        }
        if(ciudad_a_id.find(ciudad) == ciudad_a_id.end()){
            int id = ciudad_a_id.size();
            ciudad_a_id[ciudad] = id;
            adj.push_back(std::vector<int>());
        }

    }

    // Agrega una carretera (arista) entre dos ciudades
    void agregarCarretera(const std::string& ciudad1, const std::string& ciudad2) {
           agregarCiudad(ciudad1);
           agregarCiudad(ciudad2);

           int id1= ciudad_a_id[ciudad1];
           int id2= ciudad_a_id[ciudad2];
           adj[id1].push_back(id2);
           if(id1 != id2){
               adj[id2].push_back(id1);
           }


    }

    // Verifica si dos ciudades están conectadas usando BFS
    bool estanConectadas(const std::string& ciudadA, const std::string& ciudadB) {
    auto itA = ciudad_a_id.find(ciudadA);
    auto itB = ciudad_a_id.find(ciudadB);

    if(itA == ciudad_a_id.end() || itB == ciudad_a_id.end()){
        return false;
    }
    int origen = itA->second;
    int destino = itB->second;

    if(origen == destino){
        return true;
    }
    std::queue<int> cola;
    std::vector<bool> visitados(adj.size(), false);

    visitados[origen] = true;
    cola.push(origen);

    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();
    for(int vecino : adj[actual]){
    if(vecino == destino){
        return true;
    }
    if (!visitados[vecino]){
        visitados[vecino] = true;
        cola.push(vecino);

       }

    }
    }
    return false;
    }
};
*/
/*#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

class GrafoCiudades {
public:
    std::map<std::string, int> ciudad_a_id;
    std::vector<std::string> id_a_ciudad;
    std::vector<std::vector<int>> adj;

    GrafoCiudades() {}

    void agregarCiudad(const std::string& ciudad) {
        if (ciudad_a_id.find(ciudad) != ciudad_a_id.end()) {
            return;
        }
        int id = id_a_ciudad.size();
        ciudad_a_id[ciudad] = id;
        id_a_ciudad.push_back(ciudad);
        adj.push_back(std::vector<int>());
    }

    void agregarCarretera(const std::string& ciudad1, const std::string& ciudad2) {
        agregarCiudad(ciudad1);
        agregarCiudad(ciudad2);

        int id1 = ciudad_a_id[ciudad1];
        int id2 = ciudad_a_id[ciudad2];
        adj[id1].push_back(id2);
        if (id1 != id2) {
            adj[id2].push_back(id1);
        }
    }

    int obtenerCaminoMasCorto(const std::string& ciudadA, const std::string& ciudadB) {
        auto itA = ciudad_a_id.find(ciudadA);
        auto itB = ciudad_a_id.find(ciudadB);

        if (itA == ciudad_a_id.end() || itB == ciudad_a_id.end()) {
            return -1;
        }

        int origen = itA->second;
        int destino = itB->second;

        if (origen == destino) {
            return 0;
        }

        std::vector<int> distancia(adj.size(), -1);
        std::queue<int> cola;

        distancia[origen] = 0;
        cola.push(origen);

        while (!cola.empty()) {
            int actual = cola.front();
            cola.pop();

            for (int vecino : adj[actual]) {
                if (distancia[vecino] == -1) {
                    distancia[vecino] = distancia[actual] + 1;
                    if (vecino == destino) {
                        return distancia[vecino];
                    }
                    cola.push(vecino);
                }
            }
        }

        return -1;
    }
};*/

/*
#include <iostream>
#include <initializer_list>
using namespace std;

class ListaPaquetes
{
private:
    struct Nodo
    {
        int secuencia;
        Nodo *siguiente;

        explicit Nodo(int numero)
            : secuencia(numero), siguiente(nullptr)
        {
        }
    };

    Nodo *cabeza;
    int cantidad;

public:
    ListaPaquetes()
        : cabeza(nullptr), cantidad(0)
    {
    }

    ~ListaPaquetes()
    {
        while (cabeza != nullptr)
        {
            Nodo *borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }

        cantidad = 0;
    }

    void agregarAlFinal(int secuencia)
    {
        Nodo *nuevo = new Nodo(secuencia);

        if (cabeza == nullptr)
        {
            cabeza = nuevo;
        }
        else
        {
            Nodo *actual = cabeza;

            while (actual->siguiente != nullptr)
            {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        cantidad++;
    }

    int size() const
    {
        return cantidad;
    }

    bool estaVacia() const
    {
        return cabeza == nullptr;
    }

    void imprimir() const
    {
        if (cabeza == nullptr)
        {
            std::cout << "VACIA";
        }
        else
        {
            Nodo *actual = cabeza;

            while (actual != nullptr)
            {
                std::cout << actual->secuencia;

                if (actual->siguiente != nullptr)
                {
                    std::cout << " ";
                }

                actual = actual->siguiente;
            }
        }

        std::cout << '\n';
    }

    int confirmarHasta(int secuencia)
    {

        Nodo *actual = cabeza;
        int confirmado = 0;

        while (actual != nullptr && actual->secuencia != secuencia)
        {
            actual = actual->siguiente;
        }
        if (actual == nullptr)
        {
            return 0;
        }
        else
        {
            Nodo *borrar = cabeza;
            Nodo *stop = actual->siguiente;

            while (borrar != stop)
            {
                Nodo *temp = borrar;
                borrar = borrar->siguiente;
                delete temp;
                confirmado++;
            }
            cabeza = stop;
            cantidad -= confirmado;
            return confirmado;
        }
    }
};

void probar(const char *nombre, std::initializer_list<int> valores, int buscar)
{
    ListaPaquetes l;
    for (int v : valores)
        l.agregarAlFinal(v);

    cout << nombre << ": ";
    int eliminados = l.confirmarHasta(buscar);
    cout << eliminados << " " << l.size() << " ";
    l.imprimir();
}

int main()
{
    probar("vacia          ", {}, 10);                         // esperado: 0 0 VACIA
    probar("no existe      ", {10, 20, 30}, 99);               // esperado: 0 3 10 20 30
    probar("primer nodo    ", {10, 20, 30}, 10);               // esperado: 1 2 20 30
    probar("intermedio     ", {101, 102, 103, 104, 105}, 103); // esperado: 3 2 104 105
    probar("ultimo nodo    ", {10, 20, 30}, 30);               // esperado: 3 0 VACIA
    probar("un solo nodo   ", {10}, 10);                       // esperado: 1 0 VACIA
    probar("un nodo, no est", {10}, 5);                        // esperado: 0 1 10
    probar("enunciado ej. 2", {201, 202, 203}, 999);           // esperado: 0 3 201 202 203
}
*/
/*
#include <iostream>
#include <queue>
#include <stack>

enum TipoEvento
{
    PAQUETE,            // contiene el numero de secuencia de un paquete
    CAIDA_ENLACE,       // indica que la comunicacion con la nave se interrumpio
    RECUPERACION_ENLACE // indica que la comunicacion vuelve a estar disponible
};

struct Evento
{
    TipoEvento tipo;
    int secuencia;

    Evento(TipoEvento tipoEvento = PAQUETE, int numero = 0)
        : tipo(tipoEvento), secuencia(numero) {}
};

void procesarEventos(std::queue<Evento> &eventos, std::queue<int> &transmitidos)
{

    bool enlaceActivo = true;
    std::stack<int> retenidos; // guarda cuando el enlace esta caido pero en orden invertido
    std::stack<int> temp; // revierte el orden de los paquetes retenidos para enviarlos correctamente a transmitidos

    while (!eventos.empty())
    {
        Evento e = eventos.front();
        eventos.pop();

        if (e.tipo == PAQUETE)
        {
            if (!enlaceActivo)
            {
                retenidos.push(e.secuencia);
            }
            else
            {
                transmitidos.push(e.secuencia);
            }
        }
        else if (e.tipo == CAIDA_ENLACE)
        {
            enlaceActivo = false;
        }
        else if (e.tipo == RECUPERACION_ENLACE)
        {
            enlaceActivo = true;
            while (!retenidos.empty())
            {
                temp.push(retenidos.top());
                retenidos.pop();
            }
            while (!temp.empty())
            {
                transmitidos.push(temp.top());
                temp.pop();
            }
        }
    }
}

#include <initializer_list>

void imprimirCola(std::queue<int> q)
{ // copia a propósito, para no vaciar la original
    if (q.empty())
        std::cout << "(vacia)";
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << '\n';
}

void probar(const char *nombre, std::initializer_list<Evento> lista)
{
    std::queue<Evento> e;
    for (const Evento &ev : lista)
        e.push(ev);

    std::queue<int> t;
    procesarEventos(e, t);

    std::cout << nombre << ": eventos=" << e.size() << " transmitidos=";
    imprimirCola(t);
}

int main()
{
    Evento P10(PAQUETE, 10), P20(PAQUETE, 20), P30(PAQUETE, 30), P40(PAQUETE, 40);
    Evento C(CAIDA_ENLACE), R(RECUPERACION_ENLACE);

    probar("vacia           ", {});                                    // esperado: eventos=0 transmitidos=(vacia)
    probar("todo activo     ", {P10, P20, P30});                       // esperado: 10 20 30
    probar("caida sin paq.  ", {P10, C, R, P20});                      // esperado: 10 20
    probar("un paq. en caida", {C, P10, R});                           // esperado: 10
    probar("ejemplo enunc.  ", {P10, C, P20, P30, R, P40});            // esperado: 10 20 30 40
    probar("varias caidas   ", {P10, C, P20, R, P30, C, P40, P10, R}); // esperado: 10 20 30 40 10
    probar("repetidos       ", {C, P10, P10, P20, R});                 // esperado: 10 10 20
}
*/
/*
#include <iostream>

class ListaPaquetes
{
private:
    struct Nodo
    {
        int secuencia;
        Nodo *siguiente;

        explicit Nodo(int numero)
            : secuencia(numero), siguiente(nullptr)
        {
        }
    };

    Nodo *cabeza;
    int cantidad;

public:
    ListaPaquetes()
        : cabeza(nullptr), cantidad(0)
    {
    }

    ~ListaPaquetes()
    {
        while (cabeza != nullptr)
        {
            Nodo *borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }

        cantidad = 0;
    }

    void agregarAlFinal(int secuencia)
    {
        Nodo *nuevo = new Nodo(secuencia);

        if (cabeza == nullptr)
        {
            cabeza = nuevo;
        }
        else
        {
            Nodo *actual = cabeza;

            while (actual->siguiente != nullptr)
            {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        cantidad++;
    }

    int size() const
    {
        return cantidad;
    }

    bool estaVacia() const
    {
        return cabeza == nullptr;
    }

    void imprimir() const
    {
        if (cabeza == nullptr)
        {
            std::cout << "VACIA";
        }
        else
        {
            Nodo *actual = cabeza;

            while (actual != nullptr)
            {
                std::cout << actual->secuencia;

                if (actual->siguiente != nullptr)
                {
                    std::cout << " ";
                }

                actual = actual->siguiente;
            }
        }

        std::cout << '\n';
    }

    int cancelarDesde(int secuencia)
    {
        Nodo *actual = cabeza;
        Nodo *anterior = nullptr;

        while (actual != nullptr && actual->secuencia != secuencia)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual == nullptr)
        {
            return 0;
        }
        if (anterior == nullptr)
        {
            cabeza = nullptr;
        }
        else
        {
            anterior->siguiente = nullptr;
        }
        int cancelados = 0;
        Nodo *borrar = actual;

        while (borrar != nullptr)
        {
            Nodo *temp = borrar;
            borrar = borrar->siguiente;
            delete temp;
            cancelados++;
        }
        cantidad -= cancelados;
        return cancelados;
    }
};
#include <initializer_list>

void probar(const char *nombre, std::initializer_list<int> valores, int buscar)
{
    ListaPaquetes l;
    for (int v : valores)
        l.agregarAlFinal(v);

    std::cout << nombre << ": ";
    int eliminados = l.cancelarDesde(buscar);
    std::cout << eliminados << " " << l.size() << " ";
    l.imprimir();

    l.agregarAlFinal(999); // se tiene que poder seguir agregando
    std::cout << "   tras agregar 999: " << l.size() << " ";
    l.imprimir();
}

int main()
{
    probar("vacia          ", {}, 10);                         // esperado: 0 0 VACIA
    probar("no existe      ", {10, 20, 30}, 99);               // esperado: 0 3 10 20 30
    probar("primer nodo    ", {10, 20, 30}, 10);               // esperado: 3 0 VACIA
    probar("intermedio     ", {301, 302, 303, 304, 305}, 303); // esperado: 3 2 301 302
    probar("ultimo nodo    ", {401, 402, 403}, 403);           // esperado: 1 2 401 402
    probar("un solo nodo   ", {10}, 10);                       // esperado: 1 0 VACIA
}
*/

/*
#include <iostream>
#include <queue>
#include <stack>

struct Paquete
{
    int secuencia;
    bool urgente;

    Paquete(int numero = 0, bool esUrgente = false)
        : secuencia(numero), urgente(esUrgente) {}
};

void priorizarTelemetria(std::queue<Paquete> &entrada, std::queue<int> &salida)
{

    std::stack<int> normal;
    std::stack<int> temp;

    while (!entrada.empty())
    {
        if (entrada.front().urgente == false)
        {
            normal.push(entrada.front().secuencia);
            entrada.pop();
        }
        else
        {
            salida.push(entrada.front().secuencia);
            entrada.pop();
        }
    }
    while (!normal.empty())
    {
        temp.push(normal.top());
        normal.pop();
    }
    while (!temp.empty())
    {
        salida.push(temp.top());
        temp.pop();
    }
}
#include <initializer_list>

void imprimirCola(std::queue<int> q)
{ // copia a propósito, para no vaciar la original
    if (q.empty())
        std::cout << "(vacia)";
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << '\n';
}

void probar(const char *nombre, std::initializer_list<Paquete> lista)
{
    std::queue<Paquete> e;
    for (const Paquete &p : lista)
        e.push(p);

    std::queue<int> s;
    priorizarTelemetria(e, s);

    std::cout << nombre << ": entrada=" << e.size() << " salida=";
    imprimirCola(s);
}

int main()
{
    probar("vacia          ", {});                                                              // esperado: entrada=0 salida=(vacia)
    probar("todos urgentes ", {{10, true}, {20, true}, {30, true}});                            // esperado: 10 20 30
    probar("todos normales ", {{10, false}, {20, false}, {30, false}});                         // esperado: 10 20 30
    probar("enunciado      ", {{10, false}, {20, true}, {30, false}, {40, true}, {50, false}}); // esperado: 20 40 10 30 50
    probar("otro ejemplo   ", {{81, true}, {25, false}, {17, true}, {60, false}});              // esperado: 81 17 25 60
    probar("un solo paquete", {{7, false}});                                                    // esperado: 7
    probar("repetidos      ", {{5, false}, {5, true}, {5, false}, {9, true}});                  // esperado: 5 9 5 5
}
*/