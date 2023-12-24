#include <iostream>
#include <tuple>


std::tuple<std::string, int> f (int age)
{
    using namespace std::literals;
    return {"Moi "s, age};
}

int main () {
    int c = 1;
    auto [moi, age] = f(19);
    std::cout << moi << age << '\n';
    auto res = f(30);
    // moi cannot be reused
    auto &[moie, agee] = res;
    agee++;
    std::cout << moie << agee << '\n';
    c++;
    std::cout << c << '\n';
    std::cout << moi << age << '\n';
//    std::cout << << '\n';
    return 0;
}
