#pragma once

#include <Stack.h>

// 顺序栈定义
#define OVERFLOW -2
#define MAXSIZE 100 // 顺序栈存储空间的初始分配量

template <typename T>
class SqStack : public Stack<T>
{
private:
    T *base;
    T *top;
    int stacksize;

public:
    SqStack();

    ~SqStack();

    void ClearStack() override;

    bool StackEmpty() const override;

    int StackLength() const override;

    bool GetTop(T &e) const override;

    void Push(const T &e) override;

    bool Pop(T &e) override;

    void StackTraverse(void (*visit)(T &)) const override;
};

template <typename T>
SqStack<T>::SqStack()
{
    this->base = new T[MAXSIZE];
    if (!this->base)
        exit(OVERFLOW);
    this->top = this->base;
    this->stacksize = MAXSIZE;
}

template <typename T>
SqStack<T>::~SqStack()
{
    delete[] this->base;
}

template <typename T>
void SqStack<T>::ClearStack()
{
    this->top = this->base;
}

template <typename T>
bool SqStack<T>::StackEmpty() const
{
    return (this->top == this->base);
}

template <typename T>
int SqStack<T>::StackLength() const
{
    return (this->top - this->base);
}

template <typename T>
bool SqStack<T>::GetTop(T &e) const
{
    if (this->StackEmpty())
        return false;
    e = *(this->top - 1);
    return true;
}

template <typename T>
void SqStack<T>::Push(const T &e)
{
    if (this->top - this->base == this->stacksize)
        return; // 栈满，无法入栈
    *(this->top++) = e;
}

template <typename T>
bool SqStack<T>::Pop(T &e)
{
    if (this->StackEmpty())
        return false;
    e = *(--this->top);
    return true;
}

template <typename T>
void SqStack<T>::StackTraverse(void (*visit)(T &)) const
{
    for (T *p = this->base; p < this->top; p++)
    {
        visit(*p);
    }
}
