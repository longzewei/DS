#include <iostream>
#include "AVLTree.h"

/*
gcc -I./ \
-o test_AVLTree \
test_AVLTree.cc \
-lstdc++ -std=c++14
*/

int main()
{
    AVLTree<int, std::string> avl;
    // Insert nodes
    avl.Insert(5, "Apple");
    avl.Insert(3, "Banana");
    avl.Insert(7, "Cherry");
    avl.Insert(2, "Durian");
    avl.Insert(4, "Elderberry");
    avl.Insert(6, "Fig");
    avl.Insert(8, "Grape");

    // Search for a key
    int key = 6;
    std::string value;
    if (avl.Search(key, value))
    {
        std::cout << "Key " << key << " found: " << value << std::endl;
    }
    else
    {
        std::cout << "Key " << key << " not found." << std::endl;
    }

    // Remove a key
    key = 3;
    if (avl.Remove(key))
    {
        std::cout << "Key " << key << " removed." << std::endl;
    }
    else
    {
        std::cout << "Key " << key << " not found." << std::endl;
    }

    // Print the minimum and maximum keys
    std::cout << "Minimum key: " << avl.Min() << std::endl;
    std::cout << "Maximum key: " << avl.Max() << std::endl;

    return 0;
}