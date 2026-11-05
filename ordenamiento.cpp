
/*
// bubble sort tipo a
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void impre(int *v);
int main(int argc, char *argv[])
{
    int i, j, pos, aux, b, m = 0, c = 0;
    int a[MAX]; //={50,40,30,20,10};//
    for (i = 0; i < MAX; i++)
    {
        a[i] = int(rand());
    }
    // impre(a);
    puts("\n--------------------------------");
    // variables de control (desde 20 a 23)
    i = 0;     // cuantos elementos quedaron fijos al final (los mayores)
    b = 1;     // bandera, hubo cambios en la pasada, si no hubo cambios, el arreglo ya esta ordenado
    int k = 0; // cuantos elementos quedaron fijos al inicio (los menores)

    while (b == 1) // repite pasadas mientras la ultima haya hecho algun intercambio
    {
        b = 0; // al inicio de cada vuelta se supone no hay cambios, si los hay, se vuelve a poner en 1

        for (j = k; j < MAX - 1 - i; j++) // pasada hacia adelante
        {
            c++;
            if (a[j] > a[j + 1]) // si el par esta en desorden, se intercambian con aux
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                m = m + 3; // bandera de que hubo cambios en la pasada
                b = 1;     // hubo cambios, se vuelve a repetir la pasada
            }
        } // fin de la pasada

        for (j = MAX - 1 - i; j > k; j--) // leo el arreglo de derecha a izquierda
        {                                 // metodo shaker o pasada hacia atras
            c++;
            if (a[j] < a[j - 1]) // si el elemento de la derecha es menor que el de la izq estamos en desorden
            {
                aux = a[j];      // swap
                a[j] = a[j - 1]; // swap
                a[j - 1] = aux;  // swap
                m = m + 3;
            }
        }
        i++;
        k++;
        impre(a);
    }
    impre(a);

    printf("\n cantidad de comparaciones = %d movimientos= %d", c, m);
    printf("\n\n");
    return 0;
}
void impre(int *v)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("\n %3d    %3d", i, v[i]);
}
*/

/*
// seleccion sort tipo b
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 10000

void impre(int *v);

int main(int argc, char *argv[])
{
    int i, j, pos, men, m = 0, c = 0;
    int a[MAX];
    for (i = 0; i < MAX; i++)
    {
        a[i] = int(rand());
    }

    impre(a);
    cout << ("\n--------------------------------") << endl;
    for (i = 0; i < MAX - 1; i++) // ciclo externo,i es la pos. que se va a llenar en la vuelta con el menor elemento que quede
    {
        men = a[i]; // supongo que el menor es [i] y guardo su valor, men es el valor menor encontrado hasta el momento
        pos = i;    // posicion de ese menor elemento encontrado
        m++;
        for (j = i + 1; j < MAX; j++) // j recorre todo lo que queda a la derecha de i
        {
            c++;
            if (a[j] < men) // si encuentro un elemento menor que men, actualizo men y pos
            {
                men = a[j];
                m++;
                pos = j;
            }
        }
        a[pos] = a[i]; // swapeo el menor elemento encontrado con el que estaba en la posicion i
        m++;
        a[i] = men;
        m++;
    }
    impre(a);

    printf("\n cantidad de comparaciones = %d movimientos= %d", c, m);
    printf("\n\n");
    system("PAUSE");
    return 0;
}

void impre(int *v)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("\n %3d    %3d", i, v[i]);
}
*/

/*
// insertion sort tipo c (se mueve de 1 en 1 no de de k en k como shell)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 10000

void impre(int *v);

int main(int argc, char *argv[])
{
    int i, j, k, di, m = 0, c = 0;
    int a[MAX];

    for (i = 0; i < MAX; i++)
    {
        a[i] = int(rand());
    }

    impre(a);

    for (i = 1; i < MAX; i++) // parto de la posicion 1 el recorrido
    {
        j = i - 1; // j es la posicion del elemento anterior al que voy a insertar
        di = a[i]; // guarda el valor a insertar en una variable temporal
        m++;
        c++;
        while (j >= 0 && di < a[j]) // mientras que di sea menor que el elemento a la izquierda y no se salga del arreglo, se sigue moviendo
        {                           // swapeo y cuento los movimientos y comparaciones
            a[j + 1] = a[j];
            m++;
            c++;
            j--;
        }
        a[j + 1] = di; // inserto el elemento en la posicion correcta
        m++;
    }
    impre(a);

    printf("\n cantidad de comparaciones = %d movimientos= %d", c, m);
    printf("\n\n");
    system("PAUSE");
    return 0;
};

void impre(int *v)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("\n %3d    %3d", i, v[i]);
}
*/

/*
// shell sort tipo d (variante del ordenamiento por insercion)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

void impre(int *v);

int main(int argc, char *argv[])
{
    int i, j, x, k;
    int m = 0, c = 0;
    int a[MAX];

    for (i = 0; i < MAX; i++)
    {
        a[i] = int(rand());
    }

    impre(a);
    puts("\n--------------------------------");
    // calculo de salto incial (de 198 a 203)
    k = 1;
    while (k < MAX / 3)
    {
        k = 3 * k + 1;
    }

    // ciclos de salto decreciente (de 206 a 225)
    while (k >= 1)
    {
        for (i = k; i < MAX; i++) // recorre los elementos desde la posicion  hasta el final
        {
            x = a[i]; // es el elemento que voy a insertar en su lugar dentro de su sublista
            j = i - k;
            m++;
            c++;
            while ((j >= 0) && (x < a[j])) //meintras que no salga del arreglo y el elemento de atras sea mayor que x
            { // swapeo y cuento los movimientos y comparaciones
                a[j + k] = a[j];
                j = j - k;
                m++;
                c++;
            }
            a[j + k] = x; // termina el while y esta posicion es la correcta para x
            m++;
        }
        k = (k - 1) / 3; // al final de cada vuelta se reduce el salto a un tercio del valor anterior
    }

    impre(a);

    printf("\n cantidad de comparaciones= %d  movimientos= %d", c, m);
    printf("\n\n");
    system("PAUSE");
    return 0;
}

void impre(int *v)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
        printf("\n %3d   %3d", i, v[i]);
}
*/

// merge sort tipo e
// comparando metodos
// N=5000 elementos
//        Insercion  Seleccion  Burbuja  Shell    QS     MS   Heap
// Compara    6M       12M        12M       96K   53K    55K   107K
// Movimie    6M       50K        18M      140K   46K   123K    72K
/*
#include <cstdlib>
#include <iostream>
#define MAX 10 // cantidad de elementos a ordenar

using namespace std;

void ordenaMS(int a[], int low, int high);
void merge(int a[], int low, int high, int mid);
void impre(int v[], int n);

int cc, cm; // cc = contador de comparaciones, cm = contador de movimientos

int main()
{
    int A[MAX];

    // Lleno el arreglo con numeros aleatorios
    for (int i = 0; i < MAX; i++)
        A[i] = rand();

    cc = cm = 0;               // inicializo los contadores antes de ordenar
    ordenaMS(A, 0, MAX - 1);   // el ultimo indice valido es MAX - 1

    cout << "\nArreglo ordenado:";
    impre(A, MAX);

    cout << "\n\n-----------------------------\n";
    cout << "comparaciones= " << cc << endl;
    cout << "movimientos= " << cm << endl;
    return 0;
}

// Merge Sort: ordena a[low..high] dividiendo el tramo por la mitad, ordenando
// cada mitad de forma recursiva y luego mezclando (merge) las dos mitades
// ya ordenadas en un solo tramo ordenado.
void ordenaMS(int a[], int low, int high)
{
    // Caso base: si el tramo tiene 0 o 1 elementos ya esta ordenado
    if (low < high)
    {
        int mid = (low + high) / 2; // punto medio del tramo

        ordenaMS(a, low, mid);      // ordeno la mitad izquierda: a[low..mid]
        ordenaMS(a, mid + 1, high); // ordeno la mitad derecha: a[mid+1..high]
        merge(a, low, high, mid);   // mezclo ambas mitades ya ordenadas
    }
}

// Mezcla las dos mitades ordenadas a[low..mid] y a[mid+1..high]
// en un unico tramo ordenado a[low..high], usando un arreglo auxiliar c.
void merge(int a[], int low, int high, int mid)
{
    int i = low;     // recorre la mitad izquierda
    int j = mid + 1; // recorre la mitad derecha
    int k = low;     // posicion donde escribo en el arreglo auxiliar
    int c[MAX];      // arreglo auxiliar (por eso Merge Sort usa memoria extra)

    // Mientras queden elementos en ambas mitades, paso al auxiliar el menor
    while (i <= mid && j <= high)
    {
        cc++; // una comparacion entre a[i] y a[j]
        cm++; // una copia al arreglo auxiliar
        if (a[i] < a[j])
            c[k++] = a[i++]; // el menor esta en la mitad izquierda
        else
            c[k++] = a[j++]; // el menor esta en la mitad derecha
    }

    // Si sobraron elementos en la mitad izquierda, los copio tal cual
    while (i <= mid)
    {
        c[k++] = a[i++];
        cm++;
    }

    // Si sobraron elementos en la mitad derecha, los copio tal cual
    while (j <= high)
    {
        c[k++] = a[j++];
        cm++;
    }

    // Copio el tramo ya mezclado del auxiliar de vuelta al arreglo original
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
        cm++;
    }
}

// Imprime los n elementos del arreglo, uno por linea
void impre(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << endl
             << v[i];
}
 */

/*
// heap sort tipo f
#include <iostream>
#include <utility>

using namespace std;

int cc, cm; // cc = contador de comparaciones, cm = contador de movimientos

// Intercambia dos elementos y suma 3 movimientos al contador
void intercambiar(int &a, int &b)
{
   swap(a, b);
   cm += 3;
}

// Acomoda el subarbol con raiz en i para que cumpla la propiedad de heap maximo
// (el padre siempre es mayor o igual que sus hijos). n es el tamano del heap.
void heapify(int arr[], int n, int i)
{
   int largest = i;       // raiz
   int left = 2 * i + 1;  // hijo izquierdo
   int right = 2 * i + 2; // hijo derecho

   // Comparo el hijo izquierdo con el mayor actual (la raiz)
   if (left < n)
   {
       cc++;
       if (arr[left] > arr[largest])
           largest = left; // si es mayor, ahora el mas grande es el hijo izquierdo
   }

   // Comparo el hijo derecho con el mayor actual
   if (right < n)
   {
       cc++;
       if (arr[right] > arr[largest])
           largest = right; // si es mayor, ahora el mas grande es el hijo derecho
   }

   // Si el mayor no es la raiz, los intercambio y sigo acomodando hacia abajo
   if (largest != i)
   {
       intercambiar(arr[i], arr[largest]);
       heapify(arr, n, largest); // el valor que bajo puede romper el heap en el subarbol
   }
}

void heapSort(int arr[], int n)
{
   // Fase 1: construir el heap maximo.
   // Arranco desde el ultimo nodo que tiene hijos (n/2 - 1) y subo hasta la raiz.
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);

   // Fase 2: extraer el maximo.
   // La raiz (arr[0]) es el mayor: lo mando al final y reduzco el heap en 1.
   for (int i = n - 1; i > 0; i--)
   {
       intercambiar(arr[0], arr[i]);
       heapify(arr, i, 0); // la nueva raiz puede romper el heap, la acomodo
   }
}

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << endl;
}

int main()
{
   int arr[] = {12, 11, 13, 5, 6, 7};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Arreglo original: ";
   printArray(arr, n);

   cc = cm = 0; // inicializo los contadores antes de ordenar
   heapSort(arr, n);

   cout << "Arreglo ordenado: ";
   printArray(arr, n);

   cout << "\n-----------------------------\n";
   cout << "comparaciones= " << cc << endl;
   cout << "movimientos= " << cm << endl;

   return 0;
}
*/
/*
// quick sort tipo g (divide y venceras)
#include <cstdlib>
#include <iostream>
#define MAX 5000 // cantidad de elementos a ordenar

using namespace std;

void ordenaQS(int v[], int primero, int ultimo);

int cc, cm; // cc = contador de comparaciones, cm = contador de movimientos

int main()
{
    int A[MAX];

    // Lleno el arreglo con numeros aleatorios
    for (int i = 0; i < MAX; i++)
        A[i] = rand();

    cc = cm = 0;             // inicializo los contadores antes de ordenar
    ordenaQS(A, 0, MAX - 1); // el ultimo indice valido es MAX - 1

    cout << "\n-----------------------------\n";
    cout << "comparaciones= " << cc << endl;
    cout << "movimientos= " << cm << endl;
    return 0;
}

// Quick Sort: ordena v[primero..ultimo] eligiendo un pivote, dejando a su
// izquierda los menores y a su derecha los mayores, y repitiendo el proceso
// de forma recursiva en cada mitad.
void ordenaQS(int v[], int primero, int ultimo)
{
    // Caso base: si el tramo tiene 0 o 1 elementos ya esta ordenado
    if (ultimo > primero)
    {
        int pivot = v[ultimo]; // el pivote es el ultimo elemento del tramo
        cm++;                  // leer el pivote cuenta como un movimiento
        int i = primero - 1;   // i recorre de izquierda a derecha
        int j = ultimo;        // j recorre de derecha a izquierda

        // Particion: busco un elemento grande a la izquierda y uno chico a la
        // derecha, y los intercambio, hasta que i y j se cruzan
        for (;;)
        {
            // Avanzo i mientras los elementos sean menores que el pivote
            while (v[++i] < pivot)
                cc++;

            // Retrocedo j mientras los elementos sean mayores que el pivote
            // (j > primero evita leer fuera del tramo si el pivote es el menor)
            while (j > primero && v[--j] > pivot)
                cc++;

            // Si i y j se cruzaron, termina la particion
            if (i >= j)
                break;

            // Intercambio v[i] (>= pivote) con v[j] (<= pivote)
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            cm += 3; // un intercambio son 3 movimientos
        }

        // Coloco el pivote en su posicion final (la posicion i):
        // lo intercambio con el elemento que esta en v[i]
        int aux = v[i];
        v[i] = v[ultimo];
        v[ultimo] = aux;
        cm += 3;

        // El pivote ya quedo en su lugar definitivo; ordeno cada lado por separado
        ordenaQS(v, primero, i - 1); // elementos menores al pivote
        ordenaQS(v, i + 1, ultimo);  // elementos mayores al pivote
    }
}
*/