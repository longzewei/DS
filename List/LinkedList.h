#pragma once
#include <List.h>

template <typename T>
class LinkedList : public List<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    int length;
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void ClearList() override;
    bool ListIsEmpty() const override;
    int ListLength() const override;
    bool GetElem(int i, T &e) const override;
    int LocateElem(const T &e) const override;
    bool PriorElem(const T &cur_e, T &pre_e) const override;
    bool NextElem(const T &cur_e, T &next_e) const override;
    bool ListInsert(int i, const T &e) override;
    bool ListDelete(int i) override;
    void TraverseList(void (*visit)(T &)) override;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = new Node;
    this->head->next = nullptr;
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    this->ClearList();
    delete this->head;
}

template <typename T>
void LinkedList<T>::ClearList()
{
    Node *p = this->head->next;
    while (p != nullptr)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    this->head->next = nullptr;
    this->length = 0;
}

template <typename T>
bool LinkedList<T>::ListIsEmpty() const
{
    return (this->head->next == nullptr);
}

template <typename T>
int LinkedList<T>::ListLength() const
{
    return this->length;
}

template <typename T>
bool LinkedList<T>::GetElem(int i, T &e) const
{
    if (i < 1 || i > this->ListLength())
        return false;

    Node *p = this->head->next;
    int count = 1;
    while (count < i)
    {
        p = p->next;
        count++;
    }

    e = p->data;
    return true;
}

template <typename T>
int LinkedList<T>::LocateElem(const T &e) const
{
    Node *p = this->head->next;
    int index = 1;
    while (p != nullptr)
    {
        if (p->data == e)
            return index;
        p = p->next;
        index++;
    }
    return 0;
}

template <typename T>
bool LinkedList<T>::PriorElem(const T &cur_e, T &pre_e) const
{
    Node *p = this->head->next;
    Node *pre = this->head;
    while (p != nullptr && p->data != cur_e)
    {
        pre = p;
        p = p->next;
    }
    if (p == nullptr || p == this->head->next)
        return false;

    pre_e = pre->data;
    return true;
}

template <typename T>
bool LinkedList<T>::NextElem(const T &cur_e, T &next_e) const
{
    Node *p = this->head->next;
    while (p != nullptr && p->data != cur_e)
    {
        p = p->next;
    }
    if (p == nullptr || p->next == nullptr)
        return false;

    next_e = p->next->data;
    return true;
}

template <typename T>
bool LinkedList<T>::ListInsert(int i, const T &e)
{
    if (i < 1 || i > this->ListLength() + 1)
        return false;

    Node *p = this->head;
    int count = 0;
    while (count < i - 1)
    {
        p = p->next;
        count++;
    }

    Node *new_node = new Node;
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;
    this->length++;
    return true;
}

template <typename T>
bool LinkedList<T>::ListDelete(int i)
{
    if (i < 1 || i > this->ListLength())
        return false;

    Node *p = this->head;
    int count = 0;
    while (count < i - 1)
    {
        p = p->next;
        count++;
    }

    Node *deleted_node = p->next;
    p->next = deleted_node->next;
    delete deleted_node;
    this->length++;
    return true;
}

template <typename T>
void LinkedList<T>::TraverseList(void (*visit)(T &))
{
    Node *p = this->head->next;
    while (p != nullptr)
    {
        visit(p->data);
        p = p->next;
    }
}
