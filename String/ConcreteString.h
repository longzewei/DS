#pragma once

#include <cstring>
#include <iostream>
#include <cstdlib> //rand
#include <ctime>   // time
#include "String.h"

class ConcreteString : public String
{
private:
    char *data;
    int length;

public:
    ConcreteString();

    ConcreteString(const char *chars);

    ConcreteString(const String &s);

    ~ConcreteString();

public:
    bool StrEmpty() const override;

    int StrCompare(const String &s) const override;

    int StrLength() const override;

    bool ClearString() override;

    bool Concat(const String &s2) override;

    bool SubString(String &sub, int pos, int len) const override;

    int Index(const String &s, int pos) const override;

    bool Replace(const String &s, const String &v) override;

    bool StrInsert(int pos, const String &s) override;

    bool StrDelete(int pos, int len) override;

    void Print() const override
    {
        std::cout << this->data;
    }

private:
    friend int Index_raw(const String &S, const String &T, int pos);
    friend int Index_BF(const String &S, const String &T, int pos);
    friend int Index_KMP(const String &S, const String &T, int pos);
    friend void get_next(const String &T, int next[]);
};

ConcreteString::ConcreteString() : length(0)
{
    this->data = new char[this->length + 1];
    this->data[0] = '\0';
}

ConcreteString::ConcreteString(const char *chars) : length(0)
{
    if (chars != nullptr)
    {
        this->length = std::strlen(chars);
        this->data = new char[this->length + 1];
        std::strcpy(this->data, chars);
    }
}

ConcreteString::ConcreteString(const String &s) : length(0)
{
    const ConcreteString *concreteString = dynamic_cast<const ConcreteString *>(&s);
    if (concreteString)
    {
        this->length = concreteString->length;
        this->data = new char[this->length + 1];
        std::strcpy(this->data, concreteString->data);
    }
}

ConcreteString::~ConcreteString()
{
    this->ClearString();
}

bool ConcreteString::StrEmpty() const
{
    return this->length == 0;
}

int ConcreteString::StrCompare(const String &s) const
{
    const ConcreteString *concreteString = dynamic_cast<const ConcreteString *>(&s);
    if (concreteString)
        return std::strcmp(this->data, concreteString->data);

    return -1; // 不支持与不同类型字符串的比较
}

int ConcreteString::StrLength() const
{
    return this->length;
}

bool ConcreteString::ClearString()
{
    if (this->data)
    {
        delete[] this->data;
        this->data = nullptr;
        this->length = 0;
        return true;
    }
    return false;
}

bool ConcreteString::Concat(const String &s2)
{
    const ConcreteString *concreteString2 = dynamic_cast<const ConcreteString *>(&s2);
    if (concreteString2)
    {
        int newLength = this->length + concreteString2->length;
        char *newData = new char[newLength + 1];
        std::strcpy(newData, this->data);
        std::strcat(newData, concreteString2->data);

        delete[] this->data;
        this->data = newData;
        this->length = newLength;
        return true;
    }
    return false;
}

bool ConcreteString::SubString(String &sub, int pos, int len) const
{
    ConcreteString *concreteSub = dynamic_cast<ConcreteString *>(&sub);
    if (concreteSub)
    {
        if (pos < 1 || pos > this->length || len < 0 || len > this->length - pos + 1)
            return false;

        concreteSub->length = len;
        concreteSub->data = new char[len + 1];
        std::strncpy(concreteSub->data, this->data + pos - 1, len);
        concreteSub->data[len] = '\0';
        return true;
    }
    return false;
}

int ConcreteString::Index(const String &s, int pos) const
{
    int temp = std::rand() % 3;
    std::cout << "temp:" << temp << std::endl;
    switch (temp % 3)
    {
    case 1:
    {
        std::cout << "Index_BF" << std::endl;
        return Index_BF(*this, s, pos);
    }
    case 2:
    {
        std::cout << "Index_KMP" << std::endl;
        return Index_KMP(*this, s, pos);
    }
    default:
    {
        std::cout << "Index_raw" << std::endl;
        return Index_raw(*this, s, pos);
    }
    }
}

bool ConcreteString::Replace(const String &s, const String &v)
{
    const ConcreteString *concreteString = dynamic_cast<const ConcreteString *>(&s);
    const ConcreteString *concreteV = dynamic_cast<const ConcreteString *>(&v);
    if (concreteString && concreteV)
    {
        int pos = this->Index(*concreteString, 1);
        while (pos != 0)
        {
            this->StrDelete(pos, concreteString->length);
            this->StrInsert(pos, *concreteV);
            pos = this->Index(*concreteString, pos + concreteV->length);
        }
        return true;
    }
    return false;
}

bool ConcreteString::StrInsert(int pos, const String &s)
{
    const ConcreteString *concreteString = dynamic_cast<const ConcreteString *>(&s);
    if (concreteString && pos >= 1 && pos <= this->length)
    {
        int newLength = this->length + concreteString->length;
        char *newData = new char[newLength + 1];
        std::strncpy(newData, this->data, pos - 1);
        std::strncpy(newData + pos - 1, concreteString->data, concreteString->length);
        std::strncpy(newData + pos - 1 + concreteString->length, this->data + pos - 1, this->length - pos + 1);
        newData[newLength] = '\0';
        delete[] this->data;
        this->data = newData;
        this->length = newLength;
        return true;
    }
    return false;
}

bool ConcreteString::StrDelete(int pos, int len)
{
    if (pos >= 1 && pos <= this->length && len >= 0 && len <= this->length - pos + 1)
    {
        std::strncpy(this->data + pos - 1, this->data + pos - 1 + len, this->length - pos - len + 1);
        this->length -= len;
        this->data[this->length] = '\0';
        return true;
    }
    return false;
}

/*
c++内置算法
*/
int Index_raw(const String &S, const String &T, int pos)
{
    const ConcreteString *S_ptr = dynamic_cast<const ConcreteString *>(&S);
    const ConcreteString *T_ptr = dynamic_cast<const ConcreteString *>(&T);
    if (S_ptr && T_ptr && pos >= 1 && pos <= S_ptr->length)
    {
        const char *result = std::strstr(S_ptr->data + pos - 1, T_ptr->data);
        if (result)
            return result - S_ptr->data + 1;
    }
    return 0;
}

/*
BF 算法
*/
int Index_BF(const String &S, const String &T, int pos)
{
    const ConcreteString *S_ptr = dynamic_cast<const ConcreteString *>(&S);
    const ConcreteString *T_ptr = dynamic_cast<const ConcreteString *>(&T);

    // 返回模式T在主串S中第pos个字符之后第一次出现的位置。若不存在，则返回值为0
    // 其中，T非空，1≤pos≤StrLength(S)
    int i = pos; // 主串S的起始位置
    int j = 1;   // 模式串T的起始位置
    while (i <= S_ptr->length && j <= T_ptr->length)
    {
        if (S_ptr->data[i - 1] == T_ptr->data[j - 1])
        {
            // 当前字符匹配成功，继续比较下一个字符
            ++i;
            ++j;
        }
        else
        {
            // 当前字符匹配失败，回溯到主串S中的下一个位置重新开始匹配
            /*
            FIXME i-j多回退了一格,+1 是指不回退到原来的位置,应该进行下一层判定
            */
            i = (i - j + 1) + 1;
            j = 1;
        }
    }
    if (j > T_ptr->length)
        return i - T_ptr->length; // 返回匹配成功的起始位置
    else
        return 0; // 没有找到匹配的位置
}

/*
KMP 算法
*/
void get_next(const String &T, int next[]);
int Index_KMP(const String &S, const String &T, int pos)
{ // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
    // 其中，T非空，1≤pos≤StrLength(S)

    const ConcreteString *S_ptr = dynamic_cast<const ConcreteString *>(&S);
    const ConcreteString *T_ptr = dynamic_cast<const ConcreteString *>(&T);

    int *next = new int[T_ptr->length + 1]; // 生成T的next数组
    get_next(T, next);

    int i = pos, j = 1;
    while (i <= S_ptr->length && j <= T_ptr->length)
        if (j == 0 || S_ptr->data[i] == T_ptr->data[j]) // 继续比较后继字
        {
            ++i;
            ++j;
        }
        else
            j = next[j];   // 模式串向右移动
    if (j > T_ptr->length) // 匹配成功
        return i - T_ptr->length;
    else
        return 0;
}

/*
关键思想
*/
void get_next(const String &T, int next[])
{ // 求模式串T的next函数值并存入数组next

    const ConcreteString *T_ptr = dynamic_cast<const ConcreteString *>(&T);
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T_ptr->length)
        if (j == 0 || T_ptr->data[i] == T_ptr->data[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
}