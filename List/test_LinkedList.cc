#include <iostream>
#include <memory>

#include <LinkedList.h>

void printElem(int &elem)
{
    std::cout << elem << " ";
}
/*
gcc -I./ \
-o test_LinkedList \
test_LinkedList.cc \
-lstdc++ -std=c++14
*/
int main()
{
    std::unique_ptr<List<int>> L = std::make_unique<LinkedList<int>>();

    int index = 1, temp = 0;
    while (true)
    {
        std::cout << "输入第" << index << "个元素:\n";
        std::cin >> temp;
        if (temp == -1)
            break;
        L->ListInsert(index, temp);
        index++;
    }

    std::cout << "线性表元素个数为：" << L->ListLength() << std::endl;
    std::cout << "线性表的元素为：";
    L->TraverseList(printElem);
    std::cout << std::endl;

    int e, i;
    std::cout << "请输入要获取元素的位置：";
    std::cin >> i;
    if (L->GetElem(i, e))
    {
        std::cout << "第" << i << "个元素的值为：" << e << std::endl;
    }
    else
    {
        std::cout << "位置无效" << std::endl;
    }

    std::cout << "请输入要插入元素的位置和值（以空格分隔）：";
    std::cin >> i >> e;
    if (L->ListInsert(i, e))
    {
        std::cout << "插入成功，插入后的线性表为：";
        L->TraverseList(printElem);
        std::cout << std::endl;
    }
    else
    {
        std::cout << "插入失败，位置无效" << std::endl;
    }

    L->ClearList();

    return 0;
}
