#pragma once

template <class Key, class Value>
class BinarySearchTree
{
public:
    virtual ~BinarySearchTree() {}

    virtual bool Search(const Key &key, Value &value) const = 0;
    virtual bool Insert(const Key &key, Value e) = 0;
    virtual bool Remove(const Key &key) = 0;
    virtual Key Min() const = 0;
    virtual Key Max() const = 0;
    virtual void MakeEmpty() = 0;
};
