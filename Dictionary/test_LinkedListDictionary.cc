#include <iostream>

#include "LinkedListDictionary.h"

/*
gcc -I./ \
-o test_LinkedListdictionary \
test_LinkedListdictionary.cc \
-lstdc++ -std=c++14
*/
int main()
{
    std::unique_ptr<Dictionary<std::string, int>> dictionary = std::make_unique<LinkedListDictionary<std::string, int>>();

    // 测试 Member 和 Search
    std::cout << "Member 'John': " << (dictionary->Member("John") ? "true" : "false") << std::endl;
    std::cout << "Search 'John': " << (dictionary->Search("John") != nullptr ? "found" : "not found") << std::endl;

    // 测试 Insert
    dictionary->Insert("John", 25);
    dictionary->Insert("Jane", 30);
    dictionary->Insert("Alice", 20);

    std::cout << "Member 'John': " << (dictionary->Member("John") ? "true" : "false") << std::endl;
    std::cout << "Search 'John': " << (dictionary->Search("John") != nullptr ? "found" : "not found") << std::endl;

    // 测试 Remove
    dictionary->Remove("John");

    std::cout << "Member 'John': " << (dictionary->Member("John") ? "true" : "false") << std::endl;
    std::cout << "Search 'John': " << (dictionary->Search("John") != nullptr ? "found" : "not found") << std::endl;

    return 0;
}
