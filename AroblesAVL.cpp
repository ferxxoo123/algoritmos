#include <iostream>
#include <cstdlib>

using namespace std;

typedef int tarbol;

struct nodoAVL
{
    tarbol dato;
    int FB; // altura del subarbol izq menos altura del subarbol der
    nodoAVL *izq, *der;
};
typedef nodoAVL *pnodo;

class arbolAVL
{
    pnodo raiz;
    void Insert(int x, bool &aumento, nodoAVL *&A);
    void show(pnodo aux, int n);
    void rotarLL(nodoAVL *&A);
    void rotarRR(nodoAVL *&A);
    void rotarLRalter(nodoAVL *&A);
    void rotarRLalter(nodoAVL *&A);

public:
    arbolAVL() { raiz = NULL; }
    ~arbolAVL() {}
    void CreaArbolAVL(tarbol x);
    void VerArbol() { show(raiz, 0); }
};

void arbolAVL::CreaArbolAVL(tarbol x)
{
    bool aumento;
    aumento = false;
    Insert(x, aumento, raiz);
}

// Inserta x y rebalancea al volver de la recursion.
// aumento indica si el subarbol donde se inserto crecio en altura.
void arbolAVL::Insert(int x, bool &aumento, nodoAVL *&A)
{
    if (A == NULL)
    {
        A = new nodoAVL;
        A->dato = x;
        A->FB = 0;
        A->izq = NULL;
        A->der = NULL;
        aumento = true;
    }
    else
    {
        if (x < A->dato)
        {
            Insert(x, aumento, A->izq);
            if (aumento)
            {
                switch (A->FB)
                {
                case -1:
                {
                    A->FB = 0;
                    aumento = false;
                    break;
                }
                case 0:
                {
                    A->FB = 1;
                    aumento = true;
                    break;
                }
                case 1:
                {
                    // hijo izq con FB 1 necesita LL, si es -1 necesita LR
                    if (A->izq->FB == 1)
                    {
                        rotarLL(A);
                    }
                    else
                    {
                        rotarLRalter(A);
                    }
                    aumento = false;
                    break;
                }
                } // fin switch
            } // fin aumento
        } // fin subarbol izquierdo
        else
        {
            Insert(x, aumento, A->der);
            if (aumento)
            {
                switch (A->FB)
                {
                case -1:
                {
                    // hijo der con FB 1 necesita RL, si es -1 necesita RR
                    if (A->der->FB == 1)
                    {
                        rotarRLalter(A);
                    }
                    else
                    {
                        rotarRR(A);
                    }
                    aumento = false;
                    break;
                }
                case 0:
                {
                    A->FB = -1;
                    aumento = true;
                    break;
                }
                case 1:
                {
                    A->FB = 0;
                    aumento = false;
                    break;
                }
                } // fin switch
            } // fin aumento
        } // fin subarbol derecho
    } // fin A != NULL
}

// Rotacion simple a la derecha
void arbolAVL::rotarLL(nodoAVL *&A)
{
    cout << " LL>> " << A->dato << endl
         << endl;
    nodoAVL *aux = A->izq->der;
    A->izq->der = A;
    A->izq->FB = 0;
    nodoAVL *aux2 = A->izq;
    A->izq = aux;
    A->FB = 0;
    A = aux2;
}

// Rotacion simple a la izquierda
void arbolAVL::rotarRR(nodoAVL *&A)
{
    cout << " RR>> " << A->dato << endl
         << endl;
    nodoAVL *aux = A->der->izq;
    A->der->izq = A;
    A->der->FB = 0;
    nodoAVL *aux2 = A->der;
    A->der = aux;
    A->FB = 0;
    A = aux2;
}

// Rotacion doble: primero RR sobre el hijo izq, despues LL sobre A
void arbolAVL::rotarLRalter(nodoAVL *&A)
{
    cout << " Rotacion Doble RR+LL" << endl;
    rotarRR(A->izq);
    VerArbol();
    rotarLL(A);
}

// Rotacion doble: primero LL sobre el hijo der, despues RR sobre A
void arbolAVL::rotarRLalter(nodoAVL *&A)
{
    cout << " Rotacion Doble LL+RR" << endl;
    rotarLL(A->der);
    VerArbol();
    rotarRR(A);
}

// Recorrido derecha-raiz-izquierda: el arbol se ve girado 90 grados
void arbolAVL::show(pnodo aux, int n)
{
    int i;
    if (aux != NULL)
    {
        show(aux->der, n + 1);
        for (i = 1; i <= n; i++)
            cout << "        ";
        cout << "(" << aux->dato << " " << aux->FB << ")" << "\n";
        show(aux->izq, n + 1);
    }
}

int main(int argc, char *argv[])
{
    int i;
    tarbol x;
    arbolAVL T;
    int vec[15] = {50, 120, 180, 240, 270, 360, 410, 425, 445, 495, 510, 260, 530, 540, 550};
    for (i = 0; i < 15; i++)
    {
        cout << "Se inserta " << vec[i] << endl;
        T.CreaArbolAVL(vec[i]);
        T.VerArbol();
        cout << endl;
    }

    T.VerArbol();

    cout << endl;
    return EXIT_SUCCESS;
}