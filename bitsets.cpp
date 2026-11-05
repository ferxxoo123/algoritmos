
/*
// bitset 1
#include <iostream>
#include <string>
#include <bitset> // libreria stl
using namespace std;
// se lee de izq a derecha
int main()
{
    bitset<10> a; // crea a con todos ceros (0,0,0,0,0,0,0,0,0,0)

    bitset<10> b(0xAA); // crea b con 10101010

    bitset<10> c(string("01011")); // crea c con 01011

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << "----------------------" << endl;
    a.set(2); // pone en 1 el bit 2
    a[5] = 1; // pone en 1 el bit 5
    cout << a << endl;

    b.set(); // pone todo en 1
    cout << b << endl;
    a.reset(); // pone todo en 0
    cout << a << endl;

    cout << "----------------------" << endl;
    cout << c << endl;
    cout << c.test(2) << endl; // test retorna 1 o 0
    cout << c.size() << endl;  // cantidad de bits del objeto
    cout << c.count() << endl; // cantidad de unos
    cout << c.any() << endl;   // retorna 1 si hay algun 1
    cout << c.none() << endl;  // retorna 1 si todos 0
    cout << "----------------------" << endl;
    a = 0xAF;
    b = 0xAA;
    cout << a << endl;
    cout << b << endl;
    cout << (a | b) << endl; // OR Union
    cout << (a & b) << endl; // AND Interseccion
    cout << (a ^ b) << endl; // XOR
    cout << "----------------------" << endl;
    cout << a << endl;
    cout << (a <<= 2) << endl; // corre dos lugares izq
    cout << (a >>= 1) << endl; // corre un lugar der

    cout << endl
         << endl;
    system("PAUSE");
    return 0;
}
*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;
class xx
{
public:
    bitset<7> M[7]; // matriz de bits 7x7
    void impre();
    // definiendo and de conjuntos
    friend xx operator&(xx c1, xx c2);
    // definiendo or de conjuntos
    friend xx operator|(xx c1, xx c2);    // operador or de conjunto
    int contar();                         // cuenta los 1
    friend xx operator<<(xx c1, int n);   // shift a la izquierda
    friend bool operator==(xx c1, xx c2); // compara si son iguales
};

xx operator&(xx c1, xx c2)
{
    xx c3;
    for (int i = 0; i < 7; i++)
        c3.M[i] = c1.M[i] & c2.M[i];
    return c3;
}
void xx::impre()
{
    int i, j;
    for (i = 0; i < 7; i++)
    {
        cout << endl;
        for (j = 6; j >= 0; j--)
            cout << this->M[i][j] << "  ";
    }
    cout << endl;
}

int main()
{
    xx a, b, c;
    cout << "a==b " << (a == b) << endl;
    a.M[0][3] = 1;
    a.M[1][2] = 1;
    cout << "a==b " << (a == b) << endl;
    cout << "a.contar=" << a.contar() << endl;
    a.impre();
    cout << "----------------------" << endl;
    b = a;
    b.impre();

    b.M[1].set();
    b.M[3].set();
    b.M[0].reset();
    cout << "b.contar=" << b.contar() << endl;
    b.impre();
    c = a & b;
    c.impre();
    c = a | b;
    c.impre();
    c = c << 2;
    c.impre();
    // b.impre();
    // cout<<endl;
    // c.impre();

    cout << endl
         << endl;
    system("PAUSE");
    return 0;
}

int xx::contar()
{
    int c = 0;
    for (int i = 0; i < 7; i++)
        c = c + M[i].count();
    return c;
}

xx operator|(xx c1, xx c2)
{
    xx c3;
    for (int i = 0; i < 7; i++)
        c3.M[i] = c1.M[i] | c2.M[i];
    return c3;
}

xx operator<<(xx c1, int n)
{
    for (int i = 0; i < 7; i++)
        c1.M[i] <<= n;
    return c1;
}

bool operator==(xx c1, xx c2)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (c1.M[i][j] != c2.M[i][j])
                return false;
        }
    }
    return true;
}