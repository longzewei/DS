#pragma once

// 抽象类 List
template <typename T>
class List
{
public:
    // 构造函数
    List() {}

    // 析构函数
    virtual ~List() {}

public:
    // 纯虚函数，用于置空线性表
    virtual void ClearList() = 0;

    // 纯虚函数，用于判断线性表是否为空
    virtual bool ListIsEmpty() const = 0;

    // 纯虚函数，用于获取线性表的元素个数
    virtual int ListLength() const = 0;

    // 纯虚函数，用于获取线性表的第 i 个元素的值
    virtual bool GetElem(int i, T &e) const = 0;

    // 纯虚函数，用于确定元素 e 在线性表中的位置
    virtual int LocateElem(const T &e) const = 0;

    // 纯虚函数，用于获取指定元素的前驱
    virtual bool PriorElem(const T &cur_e, T &pre_e) const = 0;

    // 纯虚函数，用于获取指定元素的后继
    virtual bool NextElem(const T &cur_e, T &next_e) const = 0;

    // 纯虚函数，用于在指定位置插入元素
    virtual bool ListInsert(int i, const T &e) = 0;

    // 纯虚函数，用于删除指定位置的元素
    virtual bool ListDelete(int i) = 0;

    // 纯虚函数，用于遍历线性表
    virtual void TraverseList(void (*)(T &)) const = 0;
};
