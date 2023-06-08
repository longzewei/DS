#include <iostream>
#include <vector>

#include "MinHeap.h"

/*
gcc -I./ \
-o test_MinHeap \
test_MinHeap.cc \
-lstdc++ -std=c++14
*/
int main()
{
    // 测试构造函数：建立空堆
    MinHeap<int> emptyHeap;
    std::cout << "Empty Heap: ";
    if (emptyHeap.IsEmpty())
    {
        std::cout << "Empty" << std::endl;
    }
    else
    {
        std::cout << "Not Empty" << std::endl;
    }

    // 测试构造函数：通过一个数组建堆
    std::vector<int> arr = {9, 4, 7, 2, 5};
    MinHeap<int> arrHeap(arr);
    std::cout << "Array Heap: ";
    if (arrHeap.IsEmpty())
    {
        std::cout << "Empty" << std::endl;
    }
    else
    {
        std::cout << "Not Empty" << std::endl;
    }

    // 测试插入元素
    arrHeap.Insert(3);
    arrHeap.Insert(1);
    arrHeap.Insert(8);
    std::cout << "After Insertion: ";
    while (!arrHeap.IsEmpty())
    {
        int min;
        arrHeap.RemoveMin(min);
        std::cout << min << " ";
    }
    std::cout << std::endl;

    // 测试MakeEmpty()
    arrHeap.MakeEmpty();
    std::cout << "After MakeEmpty: ";
    if (arrHeap.IsEmpty())
    {
        std::cout << "Empty" << std::endl;
    }
    else
    {
        std::cout << "Not Empty" << std::endl;
    }

    return 0;
}
