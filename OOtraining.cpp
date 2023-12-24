#include <iostream>

class A {
    int i;
public:
    A(int i_) : i(i_){ std::cout << "sous-membre ("<< i << ")\n";}
    ~A() { std::cout << "Aurevoir objet " << i << '\n'; }
};

class Vector {
    double x;
    double y;
    double z;
    A a;
    void printInstanciationInfo() {
        std::cout << "\nNouvel objet créé : ";
        this->afficher();
        std::cout << "\t\t(count2 = " << count2 << ")\n\n";
    }
public:
    static int count2;
    Vector() : x(0), y(0), z(0), a(++count2) { std::cout << "\ncount = " << count2 << '\n'; };
    Vector(const Vector &);

    Vector(double x_, double y_, double z_) : x(x_), y(y_), z(z_), a(++count2)
        {
            printInstanciationInfo();
        };


    void homothetie(double);
    double prod_scal(const Vector &) const;
    Vector somme(const Vector & v) const;
    void afficher() const;
    ~Vector() { std::cout << "Suppression de l'objet : "; afficher(); std::cout << ". \t" << --count2 << " objet(s) restant(s)\n";};
};

// copy constructor
Vector::Vector(const Vector & src) : x(src.x), y(src.y), z(src.z), a(++count2)
{
    std::cout << "\n(a copy one)";
    printInstanciationInfo();
}

//Vector::Vector(double a, double b, double z) : x(a), y(b), z(z) {}
int Vector::count2 = 0;

void Vector::homothetie(double mult)
{
    x *= mult;    y *= mult;    z *= mult;
}


double Vector::prod_scal(const Vector & v) const
{
    return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector Vector::somme(const Vector & v) const
{
    return Vector(x + v.x, y + v.y, z + v.z);
}

void Vector::afficher() const
{
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}




Vector newVector(Vector v) { return Vector(255, 255, 255); }



int main ()
{
    Vector v1 { 1, 2, 13 } ;
    //v1.homothetie(3);

    const Vector v2 = Vector(1, 1, 1);
    std::cout << "\nSomme de v1 et v2 = ";
    Vector s = v1.somme(v2);
    std::cout << "\n";

    Vector v4(v2);
    v4 = Vector(1, 44, 444);

    newVector(Vector(500, 500, 500));

    Vector * pV = new Vector(15, 5, 5);

    delete pV;

    return 0;
}

