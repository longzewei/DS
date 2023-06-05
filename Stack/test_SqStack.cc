#include <iostream>
#include <fstream>
#include <memory>

#include <SqStack.h>

/*
gcc -I./ \
-o test_SqStack \
test_SqStack.cc \
-lstdc++ -std=c++14
*/
int main()
{
    std::unique_ptr<Stack<char>> s = std::make_unique<SqStack<char>>();

    int choose, flag = 0;
    char j, e, t;
    char temp;
    std::cout << "1.初始化\n";
    std::cout << "2.入栈\n";
    std::cout << "3.读栈顶元素\n";
    std::cout << "4.出栈\n";
    std::cout << "0.退出\n\n";

    choose = -1;
    while (choose != 0)
    {
        std::cout << "请选择:";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            flag = 1;
            std::cout << "成功对栈进行初始化\n\n";
            break;
        case 2:
        {
            std::fstream file;
            file.open("SqStack.txt");
            if (!file)
            {
                std::cout << "错误！未找到文件！\n\n"
                          << std::endl;
                exit(0);
            }
            if (flag)
            {
                flag = 1;
                std::cout << "进栈元素依次为：\n";
                while (!file.eof())
                {
                    file >> j;
                    if (file.fail())
                        break;
                    else
                    {
                        s->Push(j);
                        std::cout << j << "  ";
                    }
                }
                std::cout << std::endl
                          << std::endl;
            }
            else
                std::cout << "栈未建立，请重新选择\n\n";
            file.close();
        }
        break;
        case 3:
            if (flag != -1 && flag != 0)
            {
                s->GetTop(temp);
                std::cout << "栈顶元素为：\n"
                          << temp << std::endl
                          << std::endl;
            }

            else
                std::cout << "栈中无元素，请重新选择\n"
                          << std::endl;
            break;
        case 4:
            std::cout << "依次弹出的栈顶元素为:\n";
            while (!s->StackEmpty())
            {
                flag = -1;
                s->Pop(t);
                std::cout << t << "  ";
            }
            std::cout << std::endl
                      << std::endl;
            break;
        }
    }
    return 0;
}
