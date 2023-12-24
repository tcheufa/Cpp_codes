#include <iostream>
#include <boost/type_index.hpp>


int main ()
{
    int n = 6;
    const int * const a = &n;
//    *a += 8;
    int * b = const_cast<int *>(a) ;
//    int * b = a ;
    std::cout << *b;

    return 0;
}
