#pragma once
#include <List.h>

#define DEFAULTCAPACITY 3

// 具体实现的顺序表类
template <typename T>
class SeqList : public List<T>
{
private:
    T *elem;      // 存储线性表元素的数组
    int length;   // 线性表的长度
    int capacity; // 数组的容量

public:
    // 构造函数
    SeqList(int n = DEFAULTCAPACITY);

    // 析构函数
    ~SeqList();

    // 置空线性表
    void ClearList() override;

    // 判断线性表是否为空
    bool ListIsEmpty() const override;

    // 获取线性表的元素个数
    int ListLength() const override;

    // 获取线性表的第 i 个元素的值
    bool GetElem(int i, T &e) const override;

    // 确定元素 e 在线性表中的位置
    int LocateElem(const T &e) const override;

    // 获取指定元素的前驱
    bool PriorElem(const T &cur_e, T &pre_e) const override;

    // 获取指定元素的后继
    bool NextElem(const T &cur_e, T &next_e) const override;

    // 在指定位置插入元素
    bool ListInsert(int i, const T &e) override;

    // 删除指定位置的元素
    bool ListDelete(int i) override;

    // 遍历线性表
    virtual void TraverseList(void (*)(T &)) const override;

protected:
    bool expand();
    bool shrink();
};

// 构造函数
template <typename T>
SeqList<T>::SeqList(int n)
{
    this->elem = new T[n];
    this->length = 0;
    this->capacity = n;
}

// 析构函数
template <typename T>
SeqList<T>::~SeqList()
{
    delete[] this->elem;
}

// 置空线性表
template <typename T>
void SeqList<T>::ClearList()
{
    this->length = 0;
}

// 判断线性表是否为空
template <typename T>
bool SeqList<T>::ListIsEmpty() const
{
    return (this->length == 0);
}

// 获取线性表的元素个数
template <typename T>
int SeqList<T>::ListLength() const
{
    return this->length;
}

// 获取线性表的第 i 个元素的值
template <typename T>
bool SeqList<T>::GetElem(int i, T &e) const
{
    if (i < 1 || i > this->length)
        return false;

    e = this->elem[i - 1];
    return true;
}

// 确定元素 e 在线性表中的位置
template <typename T>
int SeqList<T>::LocateElem(const T &e) const
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 获取指定元素的前驱
template <typename T>
bool SeqList<T>::PriorElem(const T &cur_e, T &pre_e) const
{
    int i = 0;
    while (i < this->length && this->elem[i] != cur_e)
    {
        i++;
    }

    if (i == 0 || i == this->length)
        return false;

    pre_e = this->elem[i - 1];
    return true;
}

// 获取指定元素的后继
template <typename T>
bool SeqList<T>::NextElem(const T &cur_e, T &next_e) const
{
    int i = 0;
    while (i < this->length && this->elem[i] != cur_e)
    {
        i++;
    }

    if (i == this->length - 1 || i == this->length)
        return false;

    next_e = this->elem[i + 1];
    return true;
}

// 在指定位置插入元素
template <typename T>
bool SeqList<T>::ListInsert(int i, const T &e)
{
    this->expand();
    if (i < 1 || i > this->length + 1)
        return false;

    for (int j = this->length; j >= i; j--)
    {
        this->elem[j] = this->elem[j - 1];
    }

    this->elem[i - 1] = e;
    this->length++;
    return true;
}

// 删除指定位置的元素
template <typename T>
bool SeqList<T>::ListDelete(int i)
{
    if (i < 1 || i > this->length)
        return false;

    for (int j = i; j < this->length; j++)
    {
        this->elem[j - 1] = this->elem[j];
    }

    this->length--;
    this->shrink();
    return true;
}

// 遍历线性表
template <typename T>
void SeqList<T>::TraverseList(void (*visit)(T &)) const
{
    for (int i = 0; i < this->length; i++)
    {
        visit(this->elem[i]);
    }
    std::cout << std::endl;
}

template <typename T>
bool SeqList<T>::expand()
{
    if (this->length == this->capacity)
    {
        T *oldElem = this->elem;
        this->elem = new T[this->capacity <<= 1];
        for (int i = 0; i < this->length; i++)
        {
            this->elem[i] = oldElem[i];
        }
        delete[] oldElem;
    }

    return true;
}

template <typename T>
bool SeqList<T>::shrink()
{
    if (this->length << 2 < this->capacity && this->capacity >> 1 >= DEFAULTCAPACITY)
    {
        T *oldElem = this->elem;
        this->elem = new T[this->capacity >>= 1];
        for (int i = 0; i < this->length; i++)
        {
            this->elem[i] = oldElem[i];
        }

        delete[] oldElem;
    }

    return true;
}
