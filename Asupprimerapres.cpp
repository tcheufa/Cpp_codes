#include <iostream>
using namespace std;


int & fonctionKetR (int & a);
int & f1 ();
int & f2 ();
int & f3 ();
int & f4 ();


class A
{
public :
    int p;
private :
    static int stat;
    int m;
    int n;

public:
    A(const int & v) : p(v) {};
    static A create();
    ~A();
private:
    A();

friend A operator+(const A & a, const int & b);
};

A operator+(const A & a, const int & b) {
    A c(a.p + b);
    return c;
}

int A::stat;

A::A() : p(5) {

    cout << "nouvel objet" << stat << " crée !\n";
}


A A::create() {
    ++stat;
    return A();
}

A::~A() {
    --stat;
    cout << "destruction d'un objet. Il en reste " << stat << "!\n";
}

int main (void) {
    float a = 9;
    int bar(int = 8);

//    std::cout << (f1() = f2() + f3() * f4());
//    std::cout << "r1 = " << (fonctionKetR(a) += fonctionKetR(a) + fonctionKetR(a) + fonctionKetR(a) + fonctionKetR(a) * fonctionKetR(a)) << "fin" <<std::endl;
//    fonctionKetR(a) = fonctionKetR(a) + 5;
//    std::cout << '\n' << a;
//    fonctionKetR(7);
//      auto foo = [](std::string a = " avec foo !") -> void { std::cout << a; };
//      bar();
//      foo();
        A var = A::create();
        A var2 = A::create();
        A d = A::create();
        d = 5 + d;

        for (int i { 0 }; i < 55  ; i++) cout << ' ';
        cout << '\n';
        cout << "Bon on a... " << d.p << '\n';
}

void bar (int n) {
    std::cout << "drôle de bar si ça marche : " << n;
}

int & fonctionKetR (int & a)
{
    static int count = 0;
    int * p {&a};
    (*p)++;
    std::cout << "tour " << ++count << " : " << *p <<'\n' ;
    return a;

}

int & f1 () {
    static int a = 0;
    std::cout << "\nf1 ";
    return a;
}


int & f2 () {
    static int a = 1;
    std::cout << "f2 ";
    return a;
}


int & f3 () {
    static int a = 2;
    std::cout << "f3 ";
    return a;
}


int & f4 () {
    std::cout << "f4\n";
    static int a = 3;
    return a;
}
