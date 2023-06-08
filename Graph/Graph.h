#pragma once

#include <vector>

template <typename T>
class Graph
{
public:
    // 创建图
    virtual void createGraph(const std::vector<T> &vertexList, const std::vector<std::pair<T, T>> &edgeList) = 0;
    // 销毁图
    virtual void destroyGraph() = 0;
    // 定位顶点在图中的位置
    virtual int locateVex(T v) const = 0;
    // 获取顶点的值
    virtual T getVex(int v) const = 0;
    // 修改顶点的值
    virtual void putVex(int v, T value) = 0;
    // 获取顶点的第一个邻接顶点
    virtual int firstAdjVex(int v) const = 0;
    // 获取顶点v相对于顶点w的下一个邻接顶点
    virtual int nextAdjVex(int v, int w) const = 0;
    // 插入新顶点
    virtual void insertVex(T v) = 0;
    // 删除顶点及其相关的边
    virtual void deleteVex(T v) = 0;
    // 插入新边
    virtual void insertArc(T v, T w) = 0;
    // 删除边
    virtual void deleteArc(T v, T w) = 0;
    // 深度优先遍历
    virtual void DFSTraverse() = 0;
    // 广度优先遍历
    virtual void BFSTraverse() = 0;

    virtual void printGraph() const = 0;

    virtual ~Graph() {}
};
