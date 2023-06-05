#include <iostream>
#include <memory>
#include <cstdlib> //rand
#include <ctime>   // time
#include "ConcreteString.h"

/*
gcc -I./ \
-o test_ConcreteString \
test_ConcreteString.cc \
-lstdc++ -std=c++14
*/
int main()
{
    std::srand(std::time(nullptr));
    std::unique_ptr<String> s1 = std::make_unique<ConcreteString>();
    std::cout << "s1: ";
    s1->Print(); // 输出空字符串
    std::cout << std::endl;

    std::unique_ptr<String> s2 = std::make_unique<ConcreteString>("Hello");
    std::cout << "s2: ";
    s2->Print(); // 输出 "Hello"
    std::cout << std::endl;

    std::unique_ptr<String> s3 = std::make_unique<ConcreteString>(*s2);
    std::cout << "s3: ";
    s3->Print(); // 输出 "Hello"
    std::cout << std::endl;

    std::cout << "s1 is empty: " << (s1->StrEmpty() ? "true" : "false") << std::endl; // 输出 "true"
    std::cout << "s2 is empty: " << (s2->StrEmpty() ? "true" : "false") << std::endl; // 输出 "false"

    std::cout << "Length of s2: " << s2->StrLength() << std::endl; // 输出 "5"

    s1->Concat(*s2);
    std::cout << "s1 after concatenation: ";
    s1->Print(); // 输出 "Hello"
    std::cout << std::endl;

    String *sub = new ConcreteString();
    s2->SubString(*sub, 1, 2);
    std::cout << "Substring of s2: ";
    sub->Print(); // 输出 "He"
    std::cout << std::endl;
    delete sub;

    int index = s2->Index(*s3, 1);
    std::cout << "Index of s3 in s2: " << index << std::endl; // 输出 "1"

    s2->Replace(*s3, *s1);
    std::cout << "s2 after replacement: ";
    s2->Print(); // 输出 "Hello"
    std::cout << std::endl;

    s1->StrInsert(3, *s2);
    std::cout << "s1 after insertion: ";
    s1->Print(); // 输出 "HelHellolo"
    std::cout << std::endl;

    s1->StrDelete(3, 5);
    std::cout << "s1 after deletion: ";
    s1->Print(); // 输出 "Hello"
    std::cout << std::endl;

    s1->ClearString();
    std::cout << "s1 after clearing: ";
    s1->Print(); // 输出空字符串
    std::cout << std::endl;

    return 0;
}
