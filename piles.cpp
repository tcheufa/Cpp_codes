#include <iostream>
#include <stdexcept>

class pile_entier {
    static int references;
    size_t lvl;
    size_t maxSize;
public:
    int * p;

    pile_entier() : p(new int[20]), lvl(0), maxSize(20) { std::cout << "\nNew !\n"; references++; }

    pile_entier(const size_t t) : p(new int[t]), lvl(0), maxSize(t) { std::cout << "\nNew !\n"; references++; }

    pile_entier(pile_entier & pile) : lvl(pile.lvl), maxSize(pile.maxSize) {
        std::cout << "\nCopie trouvée !!\n";
    }

    const pile_entier operator+(const pile_entier & b) { return pile_entier(maxSize+ b.maxSize); }

    ~pile_entier()
        {   if (--references == 1) {
                std::cout << "\nDeleted object with (lvl, maxSize) = (" << lvl << ", " << maxSize << ")\n";
                delete[] p;
            }
            maxSize = lvl = 0;
        }
    void empiler(int n);
    int depiler();
    bool pleine();
    bool vide();
};

int pile_entier::references = 0;

void pile_entier::empiler (int n)
{
    if (lvl >= maxSize) throw std::runtime_error("stack overflow");
    p[lvl++] = n;
}

int pile_entier::depiler ()
{
    if (lvl == 0) throw std::runtime_error("stack underflow");
    return p[--lvl];
}

bool pile_entier::pleine () { return maxSize == lvl; }

bool pile_entier::vide () { return lvl == 0; }



int main ()
{
    size_t  t = -1;
    pile_entier pile (4);
    pile_entier okaysom = pile + pile_entier();
    //pile_entier pilou (pile);//(pile_entier(7));
    pile_entier p2 = pile_entier(1);
    //pile = pilou;
    pile.empiler(3);
    pile.empiler(17);
    pile.empiler(5);
    pile.empiler(7);
//    pile.empiler(7);
//    pile.empiler(7);
//    pile.empiler(7);
//    pile.depiler();
//    pile.depiler();
//    pile.depiler();
    for(int i =0; i < 14; i++) {
        std::cout << pile.p[i] << ' ';
    }
    std::cout << std::boolalpha << "vide ? " << pile.vide() << " pleine ? " << pile.pleine();
    return 0;
}
