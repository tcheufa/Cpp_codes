#include <iostream>


void operate (float a, float b, char op)
{
    float result {};
    switch (op) {
        case '+' : result =  a + b; break;
        case '-' : result =  a - b; break;
        case '*' : result =  a * b; break;
        case '/' :
        case ':' :
            if (b) {result =  a / b; break;}
            else {std::cout <<"Erreur : '("<<a<<' '<<op<<' '<<b<<")' : Operation impossible"; return;}
        default :
            std::cout << op << " n'est pas un opérateur reconnu !";
            return;

    }
    std::cout << a << ' ' << op << ' ' << b << u8" = " << result << std::endl;
}

int main () {

    operate (1., 0, '+');
    operate (1., 0, '-');
    operate (1., 0, '*');
    operate (1., 0, '/');
    return 0;
}
