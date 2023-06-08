#pragma once

template <class E, class K>
class HashTable
{
public:
    HashTable(){};
    virtual ~HashTable(){};
    virtual bool Search(const K kl, E &el) const = 0;
    virtual bool Insert(const E &el) = 0;
    virtual bool Remove(const K kl, E &el) = 0;
    virtual void makeEmpty() = 0;
};