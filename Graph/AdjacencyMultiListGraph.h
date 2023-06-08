#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "Graph.h"

template <typename T>
struct ArcNode
{
    int ivex;
    int jvex;
    ArcNode<T> *ilink;
    ArcNode<T> *jlink;
};

template <typename T>
struct VexNode
{
    T data;
    ArcNode<T> *firstarc;
};

template <typename T>
class AdjacencyMultiListGraph : public Graph<T>
{
public:
    // 创建图
    void createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList) override;
    // 销毁图
    void destroyGraph() override;
    // 定位顶点在图中的位置
    int locateVex(T v) const override;
    // 获取顶点的值
    T getVex(int v) const override;
    // 修改顶点的值
    void putVex(int v, T value) override;
    // 获取顶点的第一个邻接顶点
    int firstAdjVex(int v) const override;
    // 获取顶点v相对于顶点w的下一个邻接顶点
    int nextAdjVex(int v, int w) const override;
    // 插入新顶点
    void insertVex(T v) override;
    // 删除顶点及其相关的边
    void deleteVex(T v) override;
    // 插入新边
    void insertArc(T v, T w) override;
    // 删除边
    void deleteArc(T v, T w) override;
    // 深度优先遍历
    void DFSTraverse() override;
    // 广度优先遍历
    void BFSTraverse() override;

    void printGraph() const override;

    ~AdjacencyMultiListGraph();

private:
    std::vector<VexNode<T>> vertices;

    void DFS(int v, std::vector<bool> &visited);
    void BFS(int v, std::vector<bool> &visited);
};

template <typename T>
void AdjacencyMultiListGraph<T>::createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList)
{
    // 创建顶点
    vertices.resize(vertexList.size());
    for (int i = 0; i < vertexList.size(); i++)
    {
        vertices[i].data = vertexList[i];
        vertices[i].firstarc = nullptr;
    }

    // 创建边
    for (const auto &edge : edgeList)
    {
        T v = edge.first;
        T w = edge.second;
        int vIndex = locateVex(v);
        int wIndex = locateVex(w);
        if (vIndex != -1 && wIndex != -1)
        {
            // 创建v->w的边
            ArcNode<T> *arc1 = new ArcNode<T>;
            arc1->ivex = vIndex;
            arc1->jvex = wIndex;
            arc1->ilink = vertices[vIndex].firstarc;
            arc1->jlink = vertices[wIndex].firstarc;
            vertices[vIndex].firstarc = arc1;

            // 创建w->v的边
            ArcNode<T> *arc2 = new ArcNode<T>;
            arc2->ivex = wIndex;
            arc2->jvex = vIndex;
            arc2->ilink = vertices[wIndex].firstarc;
            arc2->jlink = vertices[vIndex].firstarc;
            vertices[wIndex].firstarc = arc2;
        }
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::destroyGraph()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        ArcNode<T> *arc = vertices[i].firstarc;
        while (arc != nullptr)
        {
            ArcNode<T> *temp = arc;
            arc = arc->ilink;
            delete temp;
        }
    }
    vertices.clear();
}

template <typename T>
int AdjacencyMultiListGraph<T>::locateVex(T v) const
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].data == v)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
T AdjacencyMultiListGraph<T>::getVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        return vertices[v].data;
    }
    return T();
}

template <typename T>
void AdjacencyMultiListGraph<T>::putVex(int v, T value)
{
    if (v >= 0 && v < vertices.size())
    {
        vertices[v].data = value;
    }
}

template <typename T>
int AdjacencyMultiListGraph<T>::firstAdjVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        if (vertices[v].firstarc != nullptr)
        {
            return vertices[v].firstarc->jvex;
        }
    }
    return -1;
}

template <typename T>
int AdjacencyMultiListGraph<T>::nextAdjVex(int v, int w) const
{
    if (v >= 0 && v < vertices.size())
    {
        ArcNode<T> *arc = vertices[v].firstarc;
        while (arc != nullptr)
        {
            if (arc->jvex == w)
            {
                arc = arc->ilink;
                if (arc != nullptr)
                {
                    return arc->jvex;
                }
                break;
            }
            arc = arc->ilink;
        }
    }
    return -1;
}

template <typename T>
void AdjacencyMultiListGraph<T>::insertVex(T v)
{
    VexNode<T> vexNode;
    vexNode.data = v;
    vexNode.firstarc = nullptr;
    vertices.push_back(vexNode);
}

template <typename T>
void AdjacencyMultiListGraph<T>::deleteVex(T v)
{
    int vIndex = locateVex(v);
    if (vIndex != -1)
    {
        // 删除与顶点v相关的边
        ArcNode<T> *arc = vertices[vIndex].firstarc;
        while (arc != nullptr)
        {
            int wIndex = arc->jvex;
            // 删除v->w的边
            ArcNode<T> *prevArc = nullptr;
            ArcNode<T> *currArc = vertices[vIndex].firstarc;
            while (currArc != nullptr)
            {
                if (currArc->jvex == wIndex)
                {
                    if (prevArc != nullptr)
                    {
                        prevArc->ilink = currArc->ilink;
                    }
                    else
                    {
                        vertices[vIndex].firstarc = currArc->ilink;
                    }
                    delete currArc;
                    break;
                }
                prevArc = currArc;
                currArc = currArc->ilink;
            }

            // 删除w->v的边
            prevArc = nullptr;
            currArc = vertices[wIndex].firstarc;
            while (currArc != nullptr)
            {
                if (currArc->jvex == vIndex)
                {
                    if (prevArc != nullptr)
                    {
                        prevArc->ilink = currArc->ilink;
                    }
                    else
                    {
                        vertices[wIndex].firstarc = currArc->ilink;
                    }
                    delete currArc;
                    break;
                }
                prevArc = currArc;
                currArc = currArc->ilink;
            }

            arc = arc->ilink;
        }

        // 删除顶点v
        vertices.erase(vertices.begin() + vIndex);
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::insertArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);
    if (vIndex != -1 && wIndex != -1)
    {
        // 创建v->w的边
        ArcNode<T> *arc1 = new ArcNode<T>;
        arc1->ivex = vIndex;
        arc1->jvex = wIndex;
        arc1->ilink = vertices[vIndex].firstarc;
        arc1->jlink = vertices[wIndex].firstarc;
        vertices[vIndex].firstarc = arc1;

        // 创建w->v的边
        ArcNode<T> *arc2 = new ArcNode<T>;
        arc2->ivex = wIndex;
        arc2->jvex = vIndex;
        arc2->ilink = vertices[wIndex].firstarc;
        arc2->jlink = vertices[vIndex].firstarc;
        vertices[wIndex].firstarc = arc2;
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::deleteArc(T v, T w)
{
    int vIndex = locateVex(v);
    int wIndex = locateVex(w);
    if (vIndex != -1 && wIndex != -1)
    {
        // 删除v->w的边
        ArcNode<T> *prevArc = nullptr;
        ArcNode<T> *currArc = vertices[vIndex].firstarc;
        while (currArc != nullptr)
        {
            if (currArc->jvex == wIndex)
            {
                if (prevArc != nullptr)
                {
                    prevArc->ilink = currArc->ilink;
                }
                else
                {
                    vertices[vIndex].firstarc = currArc->ilink;
                }
                delete currArc;
                break;
            }
            prevArc = currArc;
            currArc = currArc->ilink;
        }

        // 删除w->v的边
        prevArc = nullptr;
        currArc = vertices[wIndex].firstarc;
        while (currArc != nullptr)
        {
            if (currArc->jvex == vIndex)
            {
                if (prevArc != nullptr)
                {
                    prevArc->ilink = currArc->ilink;
                }
                else
                {
                    vertices[wIndex].firstarc = currArc->ilink;
                }
                delete currArc;
                break;
            }
            prevArc = currArc;
            currArc = currArc->ilink;
        }
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::DFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);
    for (int i = 0; i < vertices.size(); i++)
    {
        if (!visited[i])
        {
            DFS(i, visited);
        }
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::DFS(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << vertices[v].data << " ";

    ArcNode<T> *arc = vertices[v].firstarc;
    while (arc != nullptr)
    {
        int w = arc->jvex;
        if (!visited[w])
        {
            DFS(w, visited);
        }
        arc = arc->ilink;
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::BFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);
    for (int i = 0; i < vertices.size(); i++)
    {
        if (!visited[i])
        {
            BFS(i, visited);
        }
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::BFS(int v, std::vector<bool> &visited)
{
    std::queue<int> q;
    visited[v] = true;
    std::cout << vertices[v].data << " ";
    q.push(v);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        ArcNode<T> *arc = vertices[u].firstarc;
        while (arc != nullptr)
        {
            int w = arc->jvex;
            if (!visited[w])
            {
                visited[w] = true;
                std::cout << vertices[w].data << " ";
                q.push(w);
            }
            arc = arc->ilink;
        }
    }
}

template <typename T>
void AdjacencyMultiListGraph<T>::printGraph() const
{
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << "Vertex: " << vertices[i].data << std::endl;
        std::cout << "Adjacency List: ";
        ArcNode<T> *arc = vertices[i].firstarc;
        while (arc != nullptr)
        {
            std::cout << vertices[arc->jvex].data << " ";
            arc = arc->ilink;
        }
        std::cout << std::endl;
    }
}

template <typename T>
AdjacencyMultiListGraph<T>::~AdjacencyMultiListGraph()
{
    std::cout << "图的邻接多重表表示：" << std::endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        ArcNode<T> *arc = vertices[i].firstarc;
        while (arc != nullptr)
        {
            ArcNode<T> *temp = arc;
            arc = arc->ilink;
            delete temp;
        }
    }
}