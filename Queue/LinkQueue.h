#pragma once

#include <Queue.h>

template <typename T>
class LinkQueue : public Queue<T>
{
private:
    struct QNode
    {
        T data;
        QNode *next;
    };

    QNode *front;
    QNode *rear;

    int length;

public:
    LinkQueue();

    ~LinkQueue();

    void ClearQueue() override;

    bool QueueEmpty() const override;

    int QueueLength() const override;

    bool GetHead(T &e) const override;

    bool EnQueue(const T &e) override;

    bool DeQueue(T &e) override;

    void QueueTraverse(void (*visit)(T &)) const override;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
    this->front = this->rear = new QNode;
    this->front->next = nullptr;
    this->length = 0;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
    this->ClearQueue();
    delete this->front;
}

template <typename T>
void LinkQueue<T>::ClearQueue()
{
    QNode *p = this->front->next;
    while (p)
    {
        QNode *q = p;
        p = p->next;
        delete q;
    }
    this->rear = this->front;
    this->front->next = nullptr;

    this->length = 0;
}

template <typename T>
bool LinkQueue<T>::QueueEmpty() const
{
    return (this->front == this->rear);
}

template <typename T>
int LinkQueue<T>::QueueLength() const
{
    return this->length;
}

template <typename T>
bool LinkQueue<T>::GetHead(T &e) const
{
    if (this->QueueEmpty())
        return false;
    e = this->front->next->data;
    return true;
}

template <typename T>
bool LinkQueue<T>::EnQueue(const T &e)
{
    QNode *p = new QNode;
    if (!p)
        return false;
    p->data = e;
    p->next = nullptr;
    this->rear->next = p;
    this->rear = p;

    this->length++;
    return true;
}

template <typename T>
bool LinkQueue<T>::DeQueue(T &e)
{
    if (this->QueueEmpty())
        return false;
    QNode *p = this->front->next;
    e = p->data;
    this->front->next = p->next;
    if (this->rear == p)
        this->rear = this->front;
    delete p;

    this->length--;
    return true;
}

template <typename T>
void LinkQueue<T>::QueueTraverse(void (*visit)(T &)) const
{
    QNode *p = this->front->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}
