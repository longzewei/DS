#include <iostream>
#include "UFSets.h"

/*
gcc -I./ \   
-o test_UFSets \
test_UFSets.cc \
-lstdc++ -std=c++14
*/
int main()
{
    UFSets<int> sets;

    sets.Union(1, 2);
    sets.Union(3, 4);
    sets.Union(5, 6);
    sets.Union(7, 8);
    // sets.Union(1, 3);
    sets.Union(5, 7);
    sets.Union(1, 5);

    std::cout << "Root of 2: " << sets.Find(2) << std::endl;
    std::cout << "Root of 4: " << sets.Find(4) << std::endl;
    std::cout << "Root of 6: " << sets.Find(6) << std::endl;
    std::cout << "Root of 8: " << sets.Find(8) << std::endl;

    return 0;
}
