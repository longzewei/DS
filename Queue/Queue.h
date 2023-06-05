#pragma once

template <typename T>
class Queue
{
public:
    // 构造函数
    Queue() {}

    // 析构函数
    virtual ~Queue() {}

public:
    // 清空队列
    virtual void ClearQueue() = 0;

    // 判断队列是否为空
    virtual bool QueueEmpty() const = 0;

    // 获取队列长度
    virtual int QueueLength() const = 0;

    // 获取队头元素
    virtual bool GetHead(T &e) const = 0;

    // 入队操作
    virtual bool EnQueue(const T &e) = 0;

    // 出队操作
    virtual bool DeQueue(T &e) = 0;

    // 遍历队列中的元素
    virtual void QueueTraverse(void (*visit)(T &)) const = 0;
};
