#include <iostream>
#include <vector>
#include <queue>
#include <list>

#include "Graph.h"

template <typename T>
class AdjacencyListGraph : public Graph<T>
{
private:
    std::vector<T> vertices;
    std::vector<std::list<int>> adjacencyList;

public:
    void createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList) override;
    void destroyGraph() override;
    int locateVex(T v) const override;
    T getVex(int v) const override;
    void putVex(int v, T value) override;
    int firstAdjVex(int v) const override;
    int nextAdjVex(int v, int w) const override;
    void insertVex(T v) override;
    void deleteVex(T v) override;
    void insertArc(T v, T w) override;
    void deleteArc(T v, T w) override;
    void DFSTraverse() override;
    void BFSTraverse() override;
    void printGraph() const override;

private:
    void DFS(int v, std::vector<bool> &visited);
};

template <typename T>
void AdjacencyListGraph<T>::createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList)
{
    vertices = vertexList;
    adjacencyList.clear();
    adjacencyList.resize(vertices.size());

    // &符号用于声明一个对edgeList中元素的引用，而不是对元素进行拷贝。
    // 使用引用的好处是可以避免不必要的拷贝操作，提高代码的效率
    for (const auto &edge : edgeList)
    {
        int v = locateVex(edge.first);
        int w = locateVex(edge.second);

        if (v != -1 && w != -1)
        {
            adjacencyList[v].push_back(w);
            adjacencyList[w].push_back(v);
        }
    }
}

template <typename T>
void AdjacencyListGraph<T>::destroyGraph()
{
    vertices.clear();
    adjacencyList.clear();
}

template <typename T>
int AdjacencyListGraph<T>::locateVex(T v) const
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == v)
            return i;
    }
    return -1;
}

template <typename T>
T AdjacencyListGraph<T>::getVex(int v) const
{
    if (v >= 0 && v < vertices.size())
        return vertices[v];
    throw std::out_of_range("Invalid vertex index");
}

template <typename T>
void AdjacencyListGraph<T>::putVex(int v, T value)
{
    if (v >= 0 && v < vertices.size())
        vertices[v] = value;
    else
        throw std::out_of_range("Invalid vertex index");
}

template <typename T>
int AdjacencyListGraph<T>::firstAdjVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        if (!adjacencyList[v].empty())
            return adjacencyList[v].front();
        return -1; // No adjacent vertices
    }
    throw std::out_of_range("Invalid vertex index");
}

template <typename T>
int AdjacencyListGraph<T>::nextAdjVex(int v, int w) const
{
    if (v >= 0 && v < vertices.size() && w >= 0 && w < vertices.size())
    {
        auto it = std::find(adjacencyList[v].begin(), adjacencyList[v].end(), w);
        if (it != adjacencyList[v].end() && ++it != adjacencyList[v].end())
            return *it;
        return -1; // No more adjacent vertices
    }
    throw std::out_of_range("Invalid vertex index");
}

template <typename T>
void AdjacencyListGraph<T>::insertVex(T v)
{
    vertices.push_back(v);
    adjacencyList.push_back(std::list<int>());
}

template <typename T>
void AdjacencyListGraph<T>::deleteVex(T v)
{
    int index = locateVex(v);
    if (index != -1)
    {
        vertices.erase(vertices.begin() + index);
        adjacencyList.erase(adjacencyList.begin() + index);
        for (auto &adj : adjacencyList)
        {
            adj.remove(index);
            for (auto &x : adj)
            {
                if (x > index)
                    x--;
            }
        }
    }
}

template <typename T>
void AdjacencyListGraph<T>::insertArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);

    if (vIndex != -1 && wIndex != -1)
    {
        adjacencyList[vIndex].push_back(wIndex);
        adjacencyList[wIndex].push_back(vIndex);
    }
}

template <typename T>
void AdjacencyListGraph<T>::deleteArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);

    if (vIndex != -1 && wIndex != -1)
    {
        adjacencyList[vIndex].remove(wIndex);
        adjacencyList[wIndex].remove(vIndex);
    }
}

template <typename T>
void AdjacencyListGraph<T>::DFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);

    for (int i = 0; i < vertices.size(); i++)
    {
        if (!visited[i])
            DFS(i, visited);
    }
}

template <typename T>
void AdjacencyListGraph<T>::DFS(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << vertices[v] << " ";

    for (int adj : adjacencyList[v])
    {
        if (!visited[adj])
            DFS(adj, visited);
    }
}

template <typename T>
void AdjacencyListGraph<T>::BFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> queue;

    for (int i = 0; i < vertices.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            std::cout << vertices[i] << " ";
            queue.push(i);

            while (!queue.empty())
            {
                int v = queue.front();
                queue.pop();

                for (int adj : adjacencyList[v])
                {
                    if (!visited[adj])
                    {
                        visited[adj] = true;
                        std::cout << vertices[adj] << " ";
                        queue.push(adj);
                    }
                }
            }
        }
    }
}

template <typename T>
void AdjacencyListGraph<T>::printGraph() const
{
    std::cout << "图的邻接表表示：" << std::endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << ": ";
        for (int adj : adjacencyList[i])
        {
            std::cout << vertices[adj] << " ";
        }
        std::cout << std::endl;
    }
}