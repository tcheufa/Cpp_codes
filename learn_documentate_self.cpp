#include <cassert>
#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int x { 5 };
    int y { 12 };
    int norme { 0 };

    norme = sqrt(x*x + y*y);
    // no display no error !! :)
    assert(norme == 13 && "La norme d'un vecteur v(5;12) vaut 13.");
    return 0;
}
