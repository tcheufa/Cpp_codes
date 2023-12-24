#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

#define TYPE(T) \
    boost::typeindex::type_id_with_cvr<T>().pretty_name()

#define TYPE_EXPR(expr) \
    boost::typeindex::type_id_with_cvr<decltype(expr)>().pretty_name()

template <typename T>
constexpr void foo (T && p)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
    std::cout << "using Boost : \n\tT = " << TYPE(T) << '\n';
    std::cout << "\tparam = " << TYPE_EXPR(p) << '\n';
    std::cout << std::endl;
}

template <typename T>
decltype(auto) bar (T a)
{
    return (a+1);
}

class A {
    float f;
};

int main () {
    const auto i {1};
    const int * j {0};
    auto k = A{};
    foo(1);
    foo(9.0);
    foo(i);
    foo(j);
    foo(std::string{});
    foo(std::vector<float>{});
    foo(A{});
    foo(k);
    foo(bar(1));

    auto lambida = []()-> double { return 10; };
    foo(lambida);

}
