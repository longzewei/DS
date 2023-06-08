#include <iostream>
#include <vector>
#include <queue>

#include "Graph.h"

template <typename T>
class AdjacencyMatrixGraph : public Graph<T>
{
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    // 创建图
    void createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList);
    // 销毁图
    void destroyGraph();
    // 定位顶点在图中的位置
    int locateVex(T v) const;
    // 获取顶点的值
    T getVex(int v) const;
    // 修改顶点的值
    void putVex(int v, T value);
    // 获取顶点的第一个邻接顶点
    int firstAdjVex(int v) const;
    // 获取顶点v相对于顶点w的下一个邻接顶点
    int nextAdjVex(int v, int w) const;
    // 插入新顶点
    void insertVex(T v);
    // 删除顶点及其相关的边
    void deleteVex(T v);
    // 插入新边
    void insertArc(T v, T w);
    // 删除边
    void deleteArc(T v, T w);
    // 深度优先遍历
    void DFSTraverse();
    // 广度优先遍历
    void BFSTraverse();
    // 打印图的邻接矩阵表示
    void printGraph() const;

private:
    // 深度优先遍历辅助函数
    void DFS(int v, std::vector<bool> &visited);
};

template <typename T>
int AdjacencyMatrixGraph<T>::locateVex(T v) const
{
    for (int i = 0; i < vertices.size(); ++i)
    {
        if (vertices[i] == v)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
int AdjacencyMatrixGraph<T>::firstAdjVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        for (int i = 0; i < vertices.size(); ++i)
        {
            if (adjacencyMatrix[v][i] == 1)
            {
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
int AdjacencyMatrixGraph<T>::nextAdjVex(int v, int w) const
{
    if (v >= 0 && v < vertices.size() && w >= 0 && w < vertices.size())
    {
        for (int i = w + 1; i < vertices.size(); ++i)
        {
            if (adjacencyMatrix[v][i] == 1)
            {
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
void AdjacencyMatrixGraph<T>::createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList)
{
    vertices = vertexList;
    adjacencyMatrix.resize(vertices.size(), std::vector<int>(vertices.size(), 0));

    for (const auto &edge : edgeList)
    {
        int v = locateVex(edge.first);
        int w = locateVex(edge.second);

        if (v != -1 && w != -1)
        {
            adjacencyMatrix[v][w] = 1;
            adjacencyMatrix[w][v] = 1;
        }
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::destroyGraph()
{
    vertices.clear();
    adjacencyMatrix.clear();
}

template <typename T>
T AdjacencyMatrixGraph<T>::getVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        return vertices[v];
    }
    return T();
}

template <typename T>
void AdjacencyMatrixGraph<T>::putVex(int v, T value)
{
    if (v >= 0 && v < vertices.size())
    {
        vertices[v] = value;
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::insertVex(T v)
{
    if (locateVex(v) == -1)
    {
        vertices.push_back(v);

        for (auto &row : adjacencyMatrix)
        {
            row.push_back(0);
        }
        adjacencyMatrix.push_back(std::vector<int>(vertices.size(), 0));
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::deleteVex(T v)
{
    int index = locateVex(v);

    if (index != -1)
    {
        vertices.erase(vertices.begin() + index);

        for (auto &row : adjacencyMatrix)
        {
            row.erase(row.begin() + index);
        }
        adjacencyMatrix.erase(adjacencyMatrix.begin() + index);
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::insertArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);

    if (vIndex != -1 && wIndex != -1)
    {
        adjacencyMatrix[vIndex][wIndex] = 1;
        adjacencyMatrix[wIndex][vIndex] = 1;
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::deleteArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);

    if (vIndex != -1 && wIndex != -1)
    {
        adjacencyMatrix[vIndex][wIndex] = 0;
        adjacencyMatrix[wIndex][vIndex] = 0;
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::DFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);

    for (int v = 0; v < vertices.size(); ++v)
    {
        if (!visited[v])
        {
            DFS(v, visited);
        }
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::DFS(int v, std::vector<bool> &visited)
{
    std::cout << vertices[v] << " ";
    visited[v] = true;

    for (int w = firstAdjVex(v); w != -1; w = nextAdjVex(v, w))
    {
        if (!visited[w])
        {
            DFS(w, visited);
        }
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::BFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> queue;

    for (int v = 0; v < vertices.size(); ++v)
    {
        if (!visited[v])
        {
            visited[v] = true;
            std::cout << vertices[v] << " ";
            queue.push(v);

            while (!queue.empty())
            {
                int front = queue.front();
                queue.pop();

                for (int w = firstAdjVex(front); w != -1; w = nextAdjVex(front, w))
                {
                    if (!visited[w])
                    {
                        visited[w] = true;
                        std::cout << vertices[w] << " ";
                        queue.push(w);
                    }
                }
            }
        }
    }
}

template <typename T>
void AdjacencyMatrixGraph<T>::printGraph() const
{
    std::cout << "图的邻接矩阵表示：" << std::endl;

    for (int i = 0; i < adjacencyMatrix.size(); ++i)
    {
        for (int j = 0; j < adjacencyMatrix[i].size(); ++j)
        {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

