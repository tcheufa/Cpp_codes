#include <stdio.h>

namespace espace {
    float val = 7.999;
};


void f(float a) { printf("\n\nInvoked %.1f\nSimple function in C++\n\n", a);}

int main()
{
    void (*pf)(float);
    pf = f;
    pf(5);
    float n[2] = {9, 20};
    char S[10]  = "Hello !";
    float * p = n;
    int val = 0;
    (n[0] = (int)(espace::val)) && (n[1] *= 2);

    printf("(%f, %f)", n[0], n[1]);

    return 0;
}

