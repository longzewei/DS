#pragma once

class String
{
public:
    String() {}
    String(const char *chars){};
    String(const String &s){};

    ~String() {}

public:
    virtual bool StrEmpty() const = 0;
    virtual int StrCompare(const String &s) const = 0;
    virtual int StrLength() const = 0;
    virtual bool ClearString() = 0;
    virtual bool Concat(const String &s2) = 0;
    virtual bool SubString(String &sub, int pos, int len) const = 0;
    virtual int Index(const String &s, int pos) const = 0;
    virtual bool Replace(const String &s, const String &v) = 0;
    virtual bool StrInsert(int pos, const String &s) = 0;
    virtual bool StrDelete(int pos, int len) = 0;

public:
    // 仅仅作为测试用
    virtual void Print() const {};
};
