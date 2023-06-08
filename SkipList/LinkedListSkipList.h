#pragma once

#include "SkipList.h"

template <class E, class K>
class SkipListNode
{
public:
    K key;
    E data;
};

template <class E, class K>
class LinkedListSkipList : public SkipList<E, K>
{
private:
    struct Node
    {
        K key;
        E data;
        Node **next;
    };

    Node *head;
    Node *tail;
    Node **last;
    int maxLevel;
    int levels;
    K tailKey;

public:
    LinkedListSkipList(K large);
    ~LinkedListSkipList();
    bool Search(const K kl, E &el) const override;
    bool Insert(const K kl, E &el) override;
    bool Remove(const K kl, E &el) override;

private:
    int level();
    Node *saveSearch(const K k1);
};

template <class E, class K>
LinkedListSkipList<E, K>::LinkedListSkipList(K large) : head(nullptr), tail(nullptr), last(nullptr), maxLevel(32), levels(1), tailKey(large)
{
    last = new Node *[maxLevel];
    for (int i = 0; i < maxLevel; i++)
    {
        last[i] = nullptr;
    }

    head = new Node();
    head->key = K();
    head->next = new Node *[maxLevel];
    tail = new Node();
    tail->key = tailKey;
    tail->next = new Node *[maxLevel];
    for (int i = 0; i < maxLevel; i++)
    {
        head->next[i] = tail;
        tail->next[i] = nullptr;
    }
}

template <class E, class K>
LinkedListSkipList<E, K>::~LinkedListSkipList()
{
    Node *curr = head->next[0];
    while (curr != tail)
    {
        Node *next = curr->next[0];
        delete[] curr->next;
        delete curr;
        curr = next;
    }
    delete[] head->next;
    delete head;
    delete[] tail->next;
    delete tail;
    delete[] last;
}

template <class E, class K>
bool LinkedListSkipList<E, K>::Search(const K kl, E &el) const
{
    Node *curr = head;
    for (int i = levels - 1; i >= 0; i--)
    {
        while (curr->next[i] != tail && curr->next[i]->key < kl)
        {
            curr = curr->next[i];
        }
    }
    curr = curr->next[0];
    if (curr != tail && curr->key == kl)
    {
        el = curr->data;
        return true;
    }
    return false;
}

template <class E, class K>
bool LinkedListSkipList<E, K>::Insert(const K kl, E &el)
{
    Node *update[maxLevel];
    Node *curr = head;
    for (int i = levels - 1; i >= 0; i--)
    {
        while (curr->next[i] != tail && curr->next[i]->key < kl)
        {
            curr = curr->next[i];
        }
        update[i] = curr;
    }
    curr = curr->next[0];
    if (curr != tail && curr->key == kl)
    {
        return false; // Key already exists
    }

    int newLevel = level();
    if (newLevel > levels)
    {
        for (int i = levels; i < newLevel; i++)
        {
            update[i] = head;
        }
        levels = newLevel;
    }

    curr = new Node();
    curr->key = kl;
    curr->data = el;
    curr->next = new Node *[newLevel];
    for (int i = 0; i < newLevel; i++)
    {
        curr->next[i] = update[i]->next[i];
        update[i]->next[i] = curr;
    }
    return true;
}

template <class E, class K>
bool LinkedListSkipList<E, K>::Remove(const K kl, E &el)
{
    Node *update[maxLevel];
    Node *curr = head;
    for (int i = levels - 1; i >= 0; i--)
    {
        while (curr->next[i] != tail && curr->next[i]->key < kl)
        {
            curr = curr->next[i];
        }
        update[i] = curr;
    }
    curr = curr->next[0];
    if (curr != tail && curr->key == kl)
    {
        el = curr->data;
        for (int i = 0; i < levels; i++)
        {
            if (update[i]->next[i] != curr)
                break;
            update[i]->next[i] = curr->next[i];
        }
        delete[] curr->next;
        delete curr;

        while (levels > 1 && head->next[levels - 1] == tail)
        {
            levels--;
        }
        return true;
    }
    return false;
}

template <class E, class K>
int LinkedListSkipList<E, K>::level()
{
    int lev = 1;
    while ((rand() & 1) && lev < maxLevel)
    {
        lev++;
    }
    return lev;
}

template <class E, class K>
typename LinkedListSkipList<E, K>::Node *LinkedListSkipList<E, K>::saveSearch(const K k1)
{
    Node *curr = head;
    for (int i = levels - 1; i >= 0; i--)
    {
        while (curr->next[i] != tail && curr->next[i]->key < k1)
        {
            curr = curr->next[i];
        }
        last[i] = curr;
    }
    curr = curr->next[0];
    return curr;
}
