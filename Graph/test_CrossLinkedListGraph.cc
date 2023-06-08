#include <iostream>
#include "CrossLinkedListGraph.h"

int main()
{
    // 创建一个图对象
    Graph<char> *graph = new CrossLinkedListGraph<char>();

    // 顶点列表和边列表
    std::vector<char> vertexList = {'A', 'B', 'C', 'D', 'E'};
    std::vector<std::pair<char, char>> edgeList = {
        {'A', 'B'},
        {'A', 'C'},
        {'B', 'D'},
        {'C', 'D'},
        {'C', 'E'},
        {'D', 'E'}};

    // 创建图
    graph->createGraph(vertexList, edgeList);

    // 输出顶点在位置2的值
    std::cout << "顶点在位置2的值：" << graph->getVex(2) << std::endl;

    // 修改顶点在位置2的值
    graph->putVex(2, 'X');

    // 输出修改后顶点在位置2的值
    std::cout << "顶点在位置2的值：" << graph->getVex(2) << std::endl;

    // 深度优先遍历
    std::cout << "深度优先遍历：" << std::endl;
    graph->DFSTraverse();
    std::cout << std::endl;

    // 广度优先遍历
    std::cout << "广度优先遍历：" << std::endl;
    graph->BFSTraverse();
    std::cout << std::endl;

    // 打印图的邻接矩阵表示
    graph->printGraph();

    // 销毁图
    graph->destroyGraph();

    std::cout << "图已销毁。" << std::endl;

    return 0;
}