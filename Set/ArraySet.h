#pragma once

#include <vector>

#include "Set.h"

template <class T>
class ArraySet : public Set<T>
{
private:
    std::vector<T> elements;

public:
    ArraySet();
    ~ArraySet() override;
    void makeEmpty() override;
    bool isEmpty() const override;
    bool addMember(const T &x) override;
    bool delMember(const T &x) override;
    Set<T> *intersectWith(const Set<T> &R) const override;
    Set<T> *unionWith(const Set<T> &R) const override;
    Set<T> *differenceFrom(const Set<T> &R) const override;
    bool Contains(const T &x) const override;
    bool subSet(const Set<T> &R) const override;
    bool operator==(const Set<T> &R) const override;
};

template <class T>
ArraySet<T>::ArraySet()
{
}

template <class T>
ArraySet<T>::~ArraySet()
{
}

template <class T>
void ArraySet<T>::makeEmpty()
{
    elements.clear();
}

template <class T>
bool ArraySet<T>::isEmpty() const
{
    return elements.empty();
}

template <class T>
bool ArraySet<T>::addMember(const T &x)
{
    if (Contains(x))
    {
        return false; // 添加失败，元素已存在
    }
    elements.push_back(x);
    return true; // 添加成功
}

template <class T>
bool ArraySet<T>::delMember(const T &x)
{
    for (typename std::vector<T>::iterator it = elements.begin(); it != elements.end(); ++it)
    {
        if (*it == x)
        {
            elements.erase(it);
            return true; // 删除成功
        }
    }
    return false; // 删除失败，元素不存在
}

template <class T>
Set<T> *ArraySet<T>::intersectWith(const Set<T> &R) const
{
    const ArraySet<T> &otherSet = dynamic_cast<const ArraySet<T> &>(R);

    ArraySet<T> *result = new ArraySet<T>;
    for (const T &element : elements)
    {
        if (otherSet.Contains(element))
        {
            result->addMember(element);
        }
    }
    return result;
}

template <class T>
Set<T> *ArraySet<T>::unionWith(const Set<T> &R) const
{
    const ArraySet<T> &otherSet = dynamic_cast<const ArraySet<T> &>(R);

    ArraySet<T> *result = new ArraySet<T>(*this);
    for (const T &element : otherSet.elements)
    {
        result->addMember(element);
    }
    return result;
}

template <class T>
Set<T> *ArraySet<T>::differenceFrom(const Set<T> &R) const
{
    const ArraySet<T> &otherSet = dynamic_cast<const ArraySet<T> &>(R);

    ArraySet<T> *result = new ArraySet<T>(*this);
    for (const T &element : otherSet.elements)
    {
        result->delMember(element);
    }
    return result;
}

template <class T>
bool ArraySet<T>::Contains(const T &x) const
{
    for (const T &element : elements)
    {
        if (element == x)
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool ArraySet<T>::subSet(const Set<T> &R) const
{
    const ArraySet<T> &otherSet = dynamic_cast<const ArraySet<T> &>(R);

    for (const T &element : otherSet.elements)
    {
        if (!Contains(element))
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool ArraySet<T>::operator==(const Set<T> &R) const
{
    const ArraySet<T> &otherSet = dynamic_cast<const ArraySet<T> &>(R);

    if (elements.size() != otherSet.elements.size())
    {
        return false;
    }

    for (const T &element : elements)
    {
        if (!otherSet.Contains(element))
        {
            return false;
        }
    }
    return true;
}
