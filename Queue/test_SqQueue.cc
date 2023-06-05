#include <iostream>
#include <fstream>

#include <SqQueue.h>

/*
gcc -I./ \
-o test_SqQueue \
test_SqQueue.cc \
-lstdc++ -std=c++14
*/
int main()
{
    int choose, flag = 0;
    std::unique_ptr<Queue<char>> Q = std::make_unique<SqQueue<char>>();

    char e, j;
    std::cout << "1.初始化\n";
    std::cout << "2.入队\n";
    std::cout << "3.读队头元素\n";
    std::cout << "4.出队\n";
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
            std::cout << "成功对队列进行初始化\n\n";
            break;
        case 2:
        {
            std::fstream file;
            file.open("QNode.txt");
            if (!file)
            {
                std::cout << "错误！未找到文件！\n\n"
                          << std::endl;
                exit(0);
            }
            if (flag)
            {
                flag = 1;
                std::cout << "入队的元素依次为：\n";
                while (!file.eof())
                {
                    file >> j;
                    if (file.fail())
                        break;
                    else
                    {
                        if (!Q->EnQueue(j))
                            std::cout << "队列已满，入队失败\n";
                        else
                            std::cout << j << "  ";
                    }
                }
                std::cout << std::endl
                          << std::endl;
            }
            else
                std::cout << "队列未建立，请重新选择\n\n";
            file.close();
        }
        break;
        case 3:
            if (flag != -1 && flag != 0)
            {
                Q->GetHead(e);
                std::cout << "队头元素为：\n"
                          << e << std::endl
                          << std::endl;
            }
            else
                std::cout << "队列中无元素，请重新选择\n"
                          << std::endl;
            break;
        case 4:
            std::cout << "依次弹出的队头元素为:\n";
            while (Q->DeQueue(e))
            {
                flag = -1;
                std::cout << e << "  ";
            }
            std::cout << std::endl
                      << std::endl;
            break;
        }
    }
    return 0;
}
