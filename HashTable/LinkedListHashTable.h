#pragma once

#include "HashTable.h"

#define DefaultSize 100 // 桶个数

// 元素分类(活动/空/删)
enum KindOfStatus
{
    Active,
    Empty,
    Deleted
};

// 链表节点
template <class E, class K>
class ListNode
{
public:
    K key;
    E data;
    ListNode<E, K> *next;

    ListNode() : next(nullptr) {}
    ListNode(const K &k, const E &d) : key(k), data(d), next(nullptr) {}
};

// 链表散列表
template <class E, class K>
class LinkedListHashTable : public HashTable<E, K>
{
private:
    int TableSize;       // 散列表大小
    ListNode<E, K> **ht; // 存储数组
    KindOfStatus *info;  // 状态数组

public:
    LinkedListHashTable(int sz = DefaultSize);
    ~LinkedListHashTable() override;
    bool Search(const K kl, E &el) const override;
    bool Insert(const E &el) override;
    bool Remove(const K kl, E &el) override;
    void makeEmpty() override;
};

template <class E, class K>
LinkedListHashTable<E, K>::LinkedListHashTable(int sz) : TableSize(sz)
{
    ht = new ListNode<E, K> *[TableSize];
    info = new KindOfStatus[TableSize];
    for (int i = 0; i < TableSize; i++)
    {
        ht[i] = nullptr;
        info[i] = Empty;
    }
}

template <class E, class K>
LinkedListHashTable<E, K>::~LinkedListHashTable()
{
    makeEmpty();
    delete[] ht;
    delete[] info;
}

template <class E, class K>
bool LinkedListHashTable<E, K>::Search(const K kl, E &el) const
{
    int hashValue = kl % TableSize;
    ListNode<E, K> *curr = ht[hashValue];
    while (curr != nullptr)
    {
        if (curr->key == kl)
        {
            el = curr->data;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <class E, class K>
bool LinkedListHashTable<E, K>::Insert(const E &el)
{
    K kl = el % TableSize;
    int hashValue = kl % TableSize;
    ListNode<E, K> *curr = ht[hashValue];
    ListNode<E, K> *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == kl)
        {
            return false; // Key already exists
        }
        prev = curr;
        curr = curr->next;
    }
    curr = new ListNode<E, K>(kl, el);
    if (prev == nullptr)
    {
        ht[hashValue] = curr;
    }
    else
    {
        prev->next = curr;
    }
    info[hashValue] = Active;
    return true;
}

template <class E, class K>
bool LinkedListHashTable<E, K>::Remove(const K kl, E &el)
{
    int hashValue = kl % TableSize;
    ListNode<E, K> *curr = ht[hashValue];
    ListNode<E, K> *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == kl)
        {
            el = curr->data;
            if (prev == nullptr)
            {
                ht[hashValue] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

template <class E, class K>
void LinkedListHashTable<E, K>::makeEmpty()
{
    for (int i = 0; i < TableSize; i++)
    {
        ListNode<E, K> *curr = ht[i];
        while (curr != nullptr)
        {
            ListNode<E, K> *temp = curr;
            curr = curr->next;
            delete temp;
        }
        ht[i] = nullptr;
        info[i] = Empty;
    }
}
