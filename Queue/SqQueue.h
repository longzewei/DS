#pragma once

#include <Queue.h>

#define DefaultSize 100

template <typename T>
class SqQueue : public Queue<T>
{
private:
    T *base;
    int front;
    int rear;
    int maxsize;

public:
    SqQueue(int size = DefaultSize);
    ~SqQueue();

    void ClearQueue() override;
    bool QueueEmpty() const override;
    int QueueLength() const override;
    bool GetHead(T &e) const override;
    bool EnQueue(const T &e) override;
    bool DeQueue(T &e) override;
    void QueueTraverse(void (*visit)(T &)) const override;
};

template <typename T>
SqQueue<T>::SqQueue(int size)
{
    this->base = new T[size];
    this->front = this->rear = 0;
    this->maxsize = size;
}

template <typename T>
SqQueue<T>::~SqQueue()
{
    delete[] this->base;
}

template <typename T>
void SqQueue<T>::ClearQueue()
{
    this->front = this->rear = 0;
}

template <typename T>
bool SqQueue<T>::QueueEmpty() const
{
    return (this->front == this->rear);
}

template <typename T>
int SqQueue<T>::QueueLength() const
{
    return (this->rear - this->front + this->maxsize) % this->maxsize;
}

template <typename T>
bool SqQueue<T>::GetHead(T &e) const
{
    if (this->QueueEmpty())
        return false;
    e = this->base[this->front];
    return true;
}

template <typename T>
bool SqQueue<T>::EnQueue(const T &e)
{
    if ((this->rear + 1) % this->maxsize == this->front)
        return false;
    this->base[this->rear] = e;
    this->rear = (this->rear + 1) % this->maxsize;
    return true;
}

template <typename T>
bool SqQueue<T>::DeQueue(T &e)
{
    if (this->QueueEmpty())
        return false;
    e = this->base[this->front];
    this->front = (this->front + 1) % this->maxsize;
    return true;
}

template <typename T>
void SqQueue<T>::QueueTraverse(void (*visit)(T &)) const
{
    int i = this->front;
    while (i != this->rear)
    {
        visit(this->base[i]);
        i = (i + 1) % this->maxsize;
    }
}
