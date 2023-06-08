#pragma once

template <class Name, class Attribute>
class Dictionary
{
public:
    virtual ~Dictionary() {}

    virtual bool Member(Name name) = 0;
    // 判断字典中是否存在名字为name的项，存在则返回true，否则返回false

    virtual Attribute *Search(Name name) = 0;
    // 查找并返回名字为name的项的属性指针，若不存在则返回nullptr

    virtual void Insert(Name name, Attribute attr) = 0;
    // 插入一项<name, attr>到字典中，若已存在则修改对应项的属性

    virtual void Remove(Name name) = 0;
    // 移除字典中名字为name的项
};
