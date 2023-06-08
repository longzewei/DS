#pragma once

template <class E, class K>
class SkipList
{
public:
    virtual ~SkipList() {}
    virtual bool Search(const K kl, E &el) const = 0;
    virtual bool Insert(const K kl, E &el) = 0;
    virtual bool Remove(const K kl, E &el) = 0;
};

