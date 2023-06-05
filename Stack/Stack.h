#pragma once

template <typename T>
class Stack
{
public:
    // 构造函数
    Stack() {}

    // 析构函数
    virtual ~Stack() {}

public:
    // 清空栈
    virtual void ClearStack() = 0;

    // 判断栈是否为空
    virtual bool StackEmpty() const = 0;

    // 获取栈的长度
    virtual int StackLength() const = 0;

    // 获取栈顶元素
    virtual bool GetTop(T &e) const = 0;

    // 入栈操作
    virtual void Push(const T &e) = 0;

    // 出栈操作
    virtual bool Pop(T &e) = 0;

    // 遍历栈中的元素
    virtual void StackTraverse(void (*visit)(T &)) const = 0;
};
