#pragma once

#include <Stack.h>

template <typename T>
class LinkedStack : public Stack<T>
{
private:
    struct StackNode
    {
        T data;
        StackNode *next;
    };

    StackNode *top;

public:
    LinkedStack();
    ~LinkedStack();

    void ClearStack() override;
    bool StackEmpty() const override;
    int StackLength() const override;
    bool GetTop(T &e) const override;
    void Push(const T &e) override;
    bool Pop(T &e) override;
    void StackTraverse(void (*visit)(T &)) const override;
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    this->top = nullptr;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    this->ClearStack();
}

template <typename T>
void LinkedStack<T>::ClearStack()
{
    StackNode *p;
    while (this->top != nullptr)
    {
        p = this->top;
        this->top = this->top->next;
        delete p;
    }
}

template <typename T>
bool LinkedStack<T>::StackEmpty() const
{
    return (this->top == nullptr);
}

template <typename T>
int LinkedStack<T>::StackLength() const
{
    int length = 0;
    StackNode *p = this->top;
    while (p != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}

template <typename T>
bool LinkedStack<T>::GetTop(T &e) const
{
    if (this->StackEmpty())
        return false;
    e = this->top->data;
    return true;
}

template <typename T>
void LinkedStack<T>::Push(const T &e)
{
    StackNode *newNode = new StackNode;
    newNode->data = e;
    newNode->next = this->top;
    this->top = newNode;
}

template <typename T>
bool LinkedStack<T>::Pop(T &e)
{
    if (this->StackEmpty())
        return false;
    e = this->top->data;
    StackNode *p = this->top;
    this->top = this->top->next;
    delete p;
    return true;
}

template <typename T>
void LinkedStack<T>::StackTraverse(void (*visit)(T &)) const
{
    StackNode *p = this->top;
    while (p != nullptr)
    {
        visit(p->data);
        p = p->next;
    }
}
