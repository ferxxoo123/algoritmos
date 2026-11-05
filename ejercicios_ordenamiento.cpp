// adaptar un bubble sort a un shell sort e implementarlo en una lista

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <utility>
#define MAX 1000
using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void shellSort(Nodo *inicio);

void impre(Nodo *actual);

int main(int argc, char *argv[])
{
    Nodo *inicio = nullptr;
    Nodo *actual = nullptr;
    Nodo *nuevo = nullptr;

    srand(time(nullptr));

    for (int i = 0; i < MAX; i++)
    {
        nuevo = new Nodo;

        nuevo->dato = rand() % 100;

        nuevo->sig = nullptr;

        if (inicio == nullptr)
        {
            inicio = nuevo;
            actual = nuevo;
        }
        else
        {
            actual->sig = nuevo;
            actual = nuevo;
        }
    }

    cout << "\n--------------------------\n";
    cout << "Lista generada:\n";
    impre(inicio);

    shellSort(inicio);
    cout << "\n--------------------------\n";
    cout << "Lista ordenanda:\n";
    impre(inicio);

    // libero memoria
    actual = inicio;
    while (actual != nullptr)
    {
        Nodo *aux = actual;
        actual = actual->sig;
        delete aux;
    }

    return 0;
};

void impre(Nodo *actual)
{
    while (actual != nullptr)
    {
        cout << actual->dato << " -> ";
        actual = actual->sig;
    }

    cout << "NULL\n";
}

void shellSort(Nodo *inicio)
{
    int k, b, n = 0, c = 0, m = 0, aux;

    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        actual = actual->sig;
        n++;
    }

    if (n < 2)
    {
        return;
    }
    k = 1;
    while (k < n / 3)
    {
        k = 3 * k + 1;
    }

    while (k >= 1)
    {
        do
        {
            b = 0;
            Nodo *p = inicio;
            Nodo *q = inicio;

            for (int i = 0; i < k; i++)
            {
                q = q->sig;
            }
            while (q != nullptr)
            {
                c++;
                if (p->dato > q->dato)
                {
                    aux = q->dato;
                    q->dato = p->dato;
                    p->dato = aux;

                    m += 3;
                    b = 1;
                }
                p = p->sig;
                q = q->sig;
            }

        } while (b == 1);

        k = (k - 1) / 3;
    }
    cout << "\nComparaciones = " << c << "  Movimientos = " << m << endl;
}