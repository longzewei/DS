#include <iostream>
#include <memory>
#include "ArraySet.h"

int main()
{
    // 创建 ArraySet 对象并使用智能指针进行管理
    std::unique_ptr<Set<int>> baseSet = std::make_unique<ArraySet<int>>();

    // 添加成员
    baseSet->addMember(1);
    baseSet->addMember(2);
    baseSet->addMember(3);
    baseSet->addMember(4);

    // 打印当前集合
    std::cout << "Current Set: ";
    for (int i = 1; i <= 4; i++)
    {
        if (baseSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 删除成员
    baseSet->delMember(3);

    // 打印当前集合
    std::cout << "Current Set after deleting 3: ";
    for (int i = 1; i <= 4; i++)
    {
        if (baseSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 创建另一个集合
    std::unique_ptr<Set<int>> otherSet = std::make_unique<ArraySet<int>>();
    otherSet->addMember(2);
    otherSet->addMember(4);
    otherSet->addMember(6);

    // 求两个集合的交集
    std::unique_ptr<Set<int>> intersectSet = std::unique_ptr<ArraySet<int>>(dynamic_cast<ArraySet<int> *>(baseSet->intersectWith(*otherSet)));
    std::cout << "Intersection Set: ";
    for (int i = 1; i <= 4; i++)
    {
        if (intersectSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 求两个集合的并集
    std::unique_ptr<Set<int>> unionSet = std::unique_ptr<ArraySet<int>>(dynamic_cast<ArraySet<int> *>(baseSet->unionWith(*otherSet)));
    std::cout << "Union Set: ";
    for (int i = 1; i <= 6; i++)
    {
        if (unionSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 求两个集合的差集
    std::unique_ptr<Set<int>> differenceSet = std::unique_ptr<ArraySet<int>>(dynamic_cast<ArraySet<int> *>(baseSet->differenceFrom(*otherSet)));
    std::cout << "Difference Set: ";
    for (int i = 1; i <= 4; i++)
    {
        if (differenceSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    // 判断是否为子集
    bool isSubset = baseSet->subSet(*otherSet);
    std::cout << "Is baseSet a subset of otherSet? " << (isSubset ? "Yes" : "No") << std::endl;

    // 判断集合相等
    bool isEqual = (*baseSet) == (*otherSet);
    std::cout << "Are baseSet and otherSet equal? " << (isEqual ? "Yes" : "No") << std::endl;

    // 清空集合
    baseSet->makeEmpty();

    // 打印当前集合
    std::cout << "Current Set after makeEmpty: ";
    for (int i = 1; i <= 4; i++)
    {
        if (baseSet->Contains(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
