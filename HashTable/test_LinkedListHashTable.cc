#include <iostream>

#include "LinkedListHashTable.h"

/*
gcc -I./ \
-o test_LinkedListHashTable \
test_LinkedListHashTable.cc \
-lstdc++ -std=c++14
*/
int main()
{

    std::unique_ptr<HashTable<int, int>> hashTable = std::make_unique<LinkedListHashTable<int, int>>();

    // 插入元素
    for (int i = 0; i < 1001; i++)
    {
        hashTable->Insert(i);
    }

    // 搜索元素
    int value;
    if (hashTable->Search(10, value))
    {
        std::cout << "找到元素：" << value << std::endl;
    }
    else
    {
        std::cout << "未找到元素" << std::endl;
    }
    

    // 删除元素
    if (hashTable->Remove(10, value))
    {
        std::cout << "已删除元素：" << value << std::endl;
    }
    else
    {
        std::cout << "删除元素失败" << std::endl;
    }

    // 再次搜索已删除的元素
    if (hashTable->Search(10, value))
    {
        std::cout << "找到元素：" << value << std::endl;
    }
    else
    {
        std::cout << "未找到元素:10" << std::endl;
    }

    // 清空散列表
    hashTable->makeEmpty();

    return 0;
}
