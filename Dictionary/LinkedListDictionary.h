#pragma once

#include "Dictionary.h"

template <class Name, class Attribute>
struct LinkedListDictionaryNode
{
    Name name;
    Attribute attr;
    LinkedListDictionaryNode<Name, Attribute> *next;

    LinkedListDictionaryNode(const Name &n, const Attribute &a) : name(n), attr(a), next(nullptr) {}
};

template <class Name, class Attribute>
class LinkedListDictionary : public Dictionary<Name, Attribute>
{
private:
    LinkedListDictionaryNode<Name, Attribute> *head;

public:
    LinkedListDictionary();
    ~LinkedListDictionary();
    bool Member(Name name) override;
    Attribute *Search(Name name) override;
    void Insert(Name name, Attribute attr) override;
    void Remove(Name name) override;
};

template <class Name, class Attribute>
LinkedListDictionary<Name, Attribute>::LinkedListDictionary() : head(nullptr) {}

template <class Name, class Attribute>
LinkedListDictionary<Name, Attribute>::~LinkedListDictionary()
{
    LinkedListDictionaryNode<Name, Attribute> *curr = head;
    while (curr)
    {
        LinkedListDictionaryNode<Name, Attribute> *next = curr->next;
        delete curr;
        curr = next;
    }
}

template <class Name, class Attribute>
bool LinkedListDictionary<Name, Attribute>::Member(Name name)
{
    LinkedListDictionaryNode<Name, Attribute> *curr = head;
    while (curr)
    {
        if (curr->name == name)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <class Name, class Attribute>
Attribute *LinkedListDictionary<Name, Attribute>::Search(Name name)
{
    LinkedListDictionaryNode<Name, Attribute> *curr = head;
    while (curr)
    {
        if (curr->name == name)
        {
            return &(curr->attr);
        }
        curr = curr->next;
    }
    return nullptr;
}

template <class Name, class Attribute>
void LinkedListDictionary<Name, Attribute>::Insert(Name name, Attribute attr)
{
    LinkedListDictionaryNode<Name, Attribute> *newNode = new LinkedListDictionaryNode<Name, Attribute>(name, attr);
    newNode->next = head;
    head = newNode;
}

template <class Name, class Attribute>
void LinkedListDictionary<Name, Attribute>::Remove(Name name)
{
    LinkedListDictionaryNode<Name, Attribute> *curr = head;
    LinkedListDictionaryNode<Name, Attribute> *prev = nullptr;
    while (curr)
    {
        if (curr->name == name)
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                head = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}
