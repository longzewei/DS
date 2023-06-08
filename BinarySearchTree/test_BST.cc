#include <iostream>
#include <memory>
#include "BST.h"

/*
gcc -I./ \
-o test_BST \
test_BST.cc \
-lstdc++ -std=c++14
*/

int main()
{
    std::unique_ptr<BinarySearchTree<int, std::string>> bst = std::make_unique<BST<int, std::string>>();

    // Insert nodes
    bst->Insert(5, "Five");
    bst->Insert(3, "Three");
    bst->Insert(7, "Seven");
    bst->Insert(2, "Two");
    bst->Insert(4, "Four");
    bst->Insert(6, "Six");
    bst->Insert(8, "Eight");

    // Search for a node
    int key = 4;
    std::string value;
    if (bst->Search(key, value))
    {
        std::cout << "Node with key " << key << " found: " << value << std::endl;
    }
    else
    {
        std::cout << "Node with key " << key << " not found." << std::endl;
    }

    // Remove a node
    key = 7;
    if (bst->Remove(key))
    {
        std::cout << "Node with key " << key << " removed." << std::endl;
    }
    else
    {
        std::cout << "Node with key " << key << " not found." << std::endl;
    }

    // Get minimum and maximum keys
    std::cout << "Minimum key: " << bst->Min() << std::endl;
    std::cout << "Maximum key: " << bst->Max() << std::endl;

    // Make the tree empty
    bst->MakeEmpty();

    return 0;
}
