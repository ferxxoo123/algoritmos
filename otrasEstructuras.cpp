#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#define MAX 17

using namespace std;

class Nodo
{
private:
    string dato;
    Nodo *next;

public:
    Nodo() { next = NULL; };
    Nodo(string d)
    {
        dato = d;
        next = NULL;
    };
    void set_dato(string d) { dato = d; };
    void set_next(Nodo *n) { next = n; };
    string get_dato() { return dato; };
    Nodo *get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

class Lista
{
private:
    Nodo *czo;

public:
    Lista() { czo = new Nodo(); };
    Lista(Nodo *n) { czo = n; };
    //~Lista(void);
    void add(string d);
    bool esvacia(void);
    string cabeza(void);
    Lista *resto(void);
    string toPrint(string p);
};

void Lista::add(string d)
{
    Nodo *nuevo = new Nodo(d);
    nuevo->set_next(czo);
    czo = nuevo;
}

bool Lista::esvacia(void)
{
    return czo->es_vacio();
}

string Lista::cabeza(void)
{
    if (esvacia())
    {
        cout << " Error, Cabeza de lista vacia";
        return "";
    }
    return czo->get_dato();
}

Lista *Lista::resto(void)
{
    Lista *l = new Lista(czo->get_next());
    return (l);
}

string Lista::toPrint(string p)
{
    if (this->esvacia())
    {
        return p;
    }
    else
    {
        std::ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p); // << endl;
        return stm.str();
    }
}

//-------------------- dispersion cerrada ------------------------------------
class Hash2
{
private:
    int Max;
    string D[MAX];

public:
    Hash2() // constructor, (llena todo con null como una bandera de posicion)
    {
        Max = MAX;
        for (int i = 0; i < Max; i++)
            D[i] = "NULL";
    };
    //~Lista(void);
    void add(string s);
    bool esta(string s);
    string get(string s);
    int fh(string s);
    void impre(void);
};

void Hash2::add(string s) // lineal y cuadratica
{
    int i, x, j; // toda esta parte es lineal
    i = this->fh(s);
    cout << s << "  i=" << i;
    x = 0;
    j = i;
    while (D[i].compare("NULL") != 0) // si la pos en el arreglo tiene null hago un rehash
    {                                 // toda esta parte es cuadratica
        i = i + 1;
        cout << " /i=" << i;
        x = x + 1;
        // i = j + x * x;
        // cout << " /i=" << i;
        // x=x+1; i=j+ 2*x-1;   cout<<" /i="<<i;
        i = i % Max; // asegura que se quede buscando siempre dentro del arreglo
    }
    cout << " /di=" << i << endl;
    D[i] = s;
}

/*
void Hash2::add(string s)// dispersion doble
{  int i,j,x;
   i=this->fh(s); cout<<s<<"  i="<<i;
   x=0; j=i;
   while (D[i].compare("NULL")!=0){
         x=x+1;i=j+(7-(j%7))*x;    cout<<" /i="<<i; // formula de dispersion doble
         i=i%Max;
   }
   cout<<" /di="<<i<<endl;
   D[i]=s;
}*/

int Hash2::fh(string s)
{
    int x = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        // x=x^s[i];
        x = x + s[i];
    }
    return x % Max;
}

void Hash2::impre(void)
{
    for (int i = 0; i < Max; i++)
        cout << i << " : " << D[i] << " <<<" << endl;
}

//--------------------- dispersion abierta -----------------------------------
class Hash
{
private:
    int Max;
    Lista D[MAX];

public:
    Hash() { Max = MAX; }; // constructor al entero max le doy el nro total de lugares
    void add(string s);
    bool esta(string s);
    string get(string s);
    int fh(string s); // funcion de hash (genera las direcciones)
    void impre(void);
};

void Hash::add(string s)
{
    int i;
    i = this->fh(s);
    cout << s << "  i= " << i << endl;
    D[i].add(s);
}

int Hash::fh(string s)
{
    int x = 0;
    for (size_t i = 0; i < s.length(); i++) // recorre el string y usa el codigo ASCII
    {
        x = x ^ s[i]; // or exclusivo sobre el int x (tiene su propia tabla de verdad)
        // x = x + s[i];
    }
    return x % Max;
}
// 1 orx 1 = 0
// 0     0 = 0
// 0     1 = 0
// 1     0 = 1

void Hash::impre(void)
{
    for (int i = 0; i < Max; i++)
        cout << i << " : " << D[i].toPrint("+") << " <<<" << endl;
}

int main()
{
    Hash2 h;

    h.add("hola");
    h.add("pedro");
    h.add("jose");
    h.add("miguel");
    h.add("pedrito");
    h.add("josefa");
    h.add("miguelete");
    h.add("pedra");
    h.add("ana");
    h.add("pedra");
    // h.add("pedra");
    cout << "------------------" << endl;
    h.impre();
    cout << "------------------" << endl;

    return EXIT_SUCCESS;
}