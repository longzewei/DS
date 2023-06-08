#pragma once

template <class T>
class Set
{
public:
    virtual ~Set(){};
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool addMember(const T &x) = 0;
    virtual bool delMember(const T &x) = 0;
    virtual Set<T> *intersectWith(const Set<T> &R) const = 0;
    virtual Set<T> *unionWith(const Set<T> &R) const = 0;
    virtual Set<T> *differenceFrom(const Set<T> &R) const = 0;
    virtual bool Contains(const T &x) const = 0;
    virtual bool subSet(const Set<T> &R) const = 0;
    virtual bool operator==(const Set<T> &R) const = 0;
};