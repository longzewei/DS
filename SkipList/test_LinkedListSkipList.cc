#include <iostream>
#include "LinkedListSkipList.h"

/*
gcc -I./ \
-o test_LinkedListSkipList \
test_LinkedListSkipList.cc \
-lstdc++ -std=c++14
*/
int main()
{
    std::unique_ptr<SkipList<int, int>> list = std::make_unique<LinkedListSkipList<int, int>>(100);

    // Insertion
    int values[] = {5, 10, 3, 7, 1};
    int keys[] = {50, 100, 30, 70, 10};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++)
    {
        list->Insert(keys[i], values[i]);
    }

    // Search
    int searchKey = 30;
    int searchData;
    bool found = list->Search(searchKey, searchData);
    if (found)
    {
        std::cout << "Found data for key " << searchKey << ": " << searchData << std::endl;
    }
    else
    {
        std::cout << "Data not found for key " << searchKey << std::endl;
    }

    // Removal
    int removeKey = 70;
    int removedData;
    bool removed = list->Remove(removeKey, removedData);
    if (removed)
    {
        std::cout << "Removed data for key " << removeKey << ": " << removedData << std::endl;
    }
    else
    {
        std::cout << "Failed to remove data for key " << removeKey << std::endl;
    }

    return 0;
}
