#pragma once

#include <vector>
#include <iostream>
#include <queue>

#include "Graph.h"

template <typename T>
struct ArcNode
{
    int tail;          // 弧尾顶点的索引
    int head;          // 弧头顶点的索引
    ArcNode<T> *hLink; // 指向具有相同弧头的下一条弧
    ArcNode<T> *tLink; // 指向具有相同弧尾的下一条弧
};

template <typename T>
struct VertexNode
{
    T data;               // 顶点数据
    ArcNode<T> *firstIn;  // 指向以该顶点为弧头的第一条弧
    ArcNode<T> *firstOut; // 指向以该顶点为弧尾的第一条弧
};

template <typename T>
class CrossLinkedListGraph : public Graph<T>
{
private:
    std::vector<VertexNode<T>> vertices; // 顶点列表

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
void CrossLinkedListGraph<T>::createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList)
{
    vertices.clear();

    // 创建顶点
    for (const auto &v : vertexList)
    {
        VertexNode<T> vertex;
        vertex.data = v;
        vertex.firstIn = nullptr;
        vertex.firstOut = nullptr;
        vertices.push_back(vertex);
    }

    // 创建边
    for (const auto &edge : edgeList)
    {
        int tail = locateVex(edge.first);
        int head = locateVex(edge.second);

        if (tail != -1 && head != -1)
        {
            ArcNode<T> *arc = new ArcNode<T>;
            arc->tail = tail;
            arc->head = head;
            arc->hLink = vertices[head].firstIn;
            arc->tLink = vertices[tail].firstOut;
            vertices[head].firstIn = arc;
            vertices[tail].firstOut = arc;
        }
    }
}

template <typename T>
void CrossLinkedListGraph<T>::destroyGraph()
{
    for (auto &vertex : vertices)
    {
        ArcNode<T> *arc = vertex.firstOut;
        while (arc != nullptr)
        {
            ArcNode<T> *temp = arc;
            arc = arc->tLink;
            delete temp;
        }
    }

    vertices.clear();
}

template <typename T>
int CrossLinkedListGraph<T>::locateVex(T v) const
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
T CrossLinkedListGraph<T>::getVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        return vertices[v].data;
    }
    throw std::out_of_range("Invalid vertex index.");
}

template <typename T>
void CrossLinkedListGraph<T>::putVex(int v, T value)
{
    if (v >= 0 && v < vertices.size())
    {
        vertices[v].data = value;
    }
    else
    {
        throw std::out_of_range("Invalid vertex index.");
    }
}

template <typename T>
int CrossLinkedListGraph<T>::firstAdjVex(int v) const
{
    if (v >= 0 && v < vertices.size())
    {
        if (vertices[v].firstOut != nullptr)
        {
            return vertices[v].firstOut->head;
        }
    }
    return -1;
}

template <typename T>
int CrossLinkedListGraph<T>::nextAdjVex(int v, int w) const
{
    if (v >= 0 && v < vertices.size() && w >= 0 && w < vertices.size())
    {
        ArcNode<T> *arc = vertices[v].firstOut;
        while (arc != nullptr)
        {
            if (arc->head == w)
            {
                if (arc->tLink != nullptr)
                {
                    return arc->tLink->head;
                }
                break;
            }
            arc = arc->tLink;
        }
    }
    return -1;
}

template <typename T>
void CrossLinkedListGraph<T>::insertVex(T v)
{
    VertexNode<T> vertex;
    vertex.data = v;
    vertex.firstIn = nullptr;
    vertex.firstOut = nullptr;
    vertices.push_back(vertex);
}

template <typename T>
void CrossLinkedListGraph<T>::deleteVex(T v)
{
    int index = locateVex(v);
    if (index != -1)
    {
        // 删除以该顶点为弧头的弧
        ArcNode<T> *arc = vertices[index].firstIn;
        while (arc != nullptr)
        {
            int tail = arc->tail;
            ArcNode<T> *temp = arc;
            arc = arc->hLink;

            // 删除以该弧头为弧尾的弧
            ArcNode<T> *arcToDelete = vertices[tail].firstOut;
            ArcNode<T> *prevArc = nullptr;
            while (arcToDelete != nullptr)
            {
                if (arcToDelete->head == index)
                {
                    if (prevArc != nullptr)
                    {
                        prevArc->tLink = arcToDelete->tLink;
                    }
                    else
                    {
                        vertices[tail].firstOut = arcToDelete->tLink;
                    }
                    delete arcToDelete;
                    break;
                }
                prevArc = arcToDelete;
                arcToDelete = arcToDelete->tLink;
            }

            delete temp;
        }

        // 删除以该顶点为弧尾的弧
        arc = vertices[index].firstOut;
        while (arc != nullptr)
        {
            int head = arc->head;
            ArcNode<T> *temp = arc;
            arc = arc->tLink;

            // 删除以该弧尾为弧头的弧
            ArcNode<T> *arcToDelete = vertices[head].firstIn;
            ArcNode<T> *prevArc = nullptr;
            while (arcToDelete != nullptr)
            {
                if (arcToDelete->tail == index)
                {
                    if (prevArc != nullptr)
                    {
                        prevArc->hLink = arcToDelete->hLink;
                    }
                    else
                    {
                        vertices[head].firstIn = arcToDelete->hLink;
                    }
                    delete arcToDelete;
                    break;
                }
                prevArc = arcToDelete;
                arcToDelete = arcToDelete->hLink;
            }

            delete temp;
        }

        vertices.erase(vertices.begin() + index);
    }
}

template <typename T>
void CrossLinkedListGraph<T>::insertArc(T v, T w)
{
    int tail = locateVex(v);
    int head = locateVex(w);

    if (tail != -1 && head != -1)
    {
        ArcNode<T> *arc = new ArcNode<T>;
        arc->tail = tail;
        arc->head = head;
        arc->hLink = vertices[head].firstIn;
        arc->tLink = vertices[tail].firstOut;
        vertices[head].firstIn = arc;
        vertices[tail].firstOut = arc;
    }
}

template <typename T>
void CrossLinkedListGraph<T>::deleteArc(T v, T w)
{
    int tail = locateVex(v);
    int head = locateVex(w);

    if (tail != -1 && head != -1)
    {
        // 删除以该顶点为弧头的弧
        ArcNode<T> *arc = vertices[head].firstIn;
        ArcNode<T> *prevArc = nullptr;
        while (arc != nullptr)
        {
            if (arc->tail == tail)
            {
                if (prevArc != nullptr)
                {
                    prevArc->hLink = arc->hLink;
                }
                else
                {
                    vertices[head].firstIn = arc->hLink;
                }
                delete arc;
                break;
            }
            prevArc = arc;
            arc = arc->hLink;
        }

        // 删除以该顶点为弧尾的弧
        arc = vertices[tail].firstOut;
        prevArc = nullptr;
        while (arc != nullptr)
        {
            if (arc->head == head)
            {
                if (prevArc != nullptr)
                {
                    prevArc->tLink = arc->tLink;
                }
                else
                {
                    vertices[tail].firstOut = arc->tLink;
                }
                delete arc;
                break;
            }
            prevArc = arc;
            arc = arc->tLink;
        }
    }
}

template <typename T>
void CrossLinkedListGraph<T>::DFSTraverse()
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
void CrossLinkedListGraph<T>::DFS(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << vertices[v].data << " ";

    ArcNode<T> *arc = vertices[v].firstOut;
    while (arc != nullptr)
    {
        int w = arc->head;
        if (!visited[w])
        {
            DFS(w, visited);
        }
        arc = arc->tLink;
    }
}

template <typename T>
void CrossLinkedListGraph<T>::BFSTraverse()
{
    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> queue;

    for (int i = 0; i < vertices.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            std::cout << vertices[i].data << " ";
            queue.push(i);

            while (!queue.empty())
            {
                int v = queue.front();
                queue.pop();

                ArcNode<T> *arc = vertices[v].firstOut;
                while (arc != nullptr)
                {
                    int w = arc->head;
                    if (!visited[w])
                    {
                        visited[w] = true;
                        std::cout << vertices[w].data << " ";
                        queue.push(w);
                    }
                    arc = arc->tLink;
                }
            }
        }
    }
}

template <typename T>
void CrossLinkedListGraph<T>::printGraph() const
{
    std::cout << "图的十字链表表示：" << std::endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << "Vertex " << i << ": " << vertices[i].data << std::endl;
        std::cout << "Outgoing Arcs: ";
        ArcNode<T> *arc = vertices[i].firstOut;
        while (arc != nullptr)
        {
            std::cout << "(" << vertices[arc->tail].data << ", " << vertices[arc->head].data << ") ";
            arc = arc->tLink;
        }
        std::cout << std::endl;
        std::cout << "Incoming Arcs: ";
        arc = vertices[i].firstIn;
        while (arc != nullptr)
        {
            std::cout << "(" << vertices[arc->tail].data << ", " << vertices[arc->head].data << ") ";
            arc = arc->hLink;
        }
        std::cout << std::endl
                  << std::endl;
    }
}