#pragma once

#include <vector>

template <class E>
class MinHeap
{
public:
    // 构造函数：建立空堆
    MinHeap();
    // 构造函数：通过一个数组建堆
    MinHeap(const std::vector<E> &arr);
    ~MinHeap();
    bool Insert(const E &x);
    bool RemoveMin(E &x);
    bool IsEmpty() const;
    void MakeEmpty();

private:
    std::vector<E> heap; // 存放最小堆中元素的数组

    void siftDown(int start, int m); // 从start到m下滑调整成为最小堆
    void siftUp(int start);          // 从start到0上滑调整成为最小堆
};

template <class E>
MinHeap<E>::MinHeap() {}

template <class E>
MinHeap<E>::MinHeap(const std::vector<E> &arr)
{
    heap = arr;
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        siftDown(i, n);
    }
}

template <class E>
MinHeap<E>::~MinHeap() {}

template <class E>
bool MinHeap<E>::Insert(const E &x)
{
    heap.push_back(x);
    siftUp(heap.size() - 1);
    return true;
}

template <class E>
bool MinHeap<E>::RemoveMin(E &x)
{
    if (IsEmpty())
    {
        return false;
    }
    x = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0, heap.size());
    return true;
}

template <class E>
bool MinHeap<E>::IsEmpty() const
{
    return heap.empty();
}

template <class E>
void MinHeap<E>::MakeEmpty()
{
    heap.clear();
}

template <class E>
void MinHeap<E>::siftDown(int start, int m)
{
    int i = start;
    int j = 2 * i + 1;
    E tmp = heap[i];

    // 在堆的范围内进行下滑调整
    while (j < m)
    {
        // 如果存在右孩子且右孩子比左孩子小，将 j 指向右孩子
        if (j + 1 < m && heap[j + 1] < heap[j])
        {
            j++;
        }

        // 如果当前节点比最小的孩子节点小或等于，停止下滑调整
        if (tmp <= heap[j])
        {
            break;
        }

        // 将最小的孩子节点上移至当前节点的位置
        heap[i] = heap[j];

        // 更新当前节点和孩子节点的索引
        i = j;
        j = 2 * i + 1;
    }

    // 将原始的节点值放置到最终位置
    heap[i] = tmp;
}

template <class E>
void MinHeap<E>::siftUp(int start)
{
    int j = start;
    int i = (j - 1) / 2;
    E tmp = heap[j];

    while (j > 0)
    {
        if (heap[i] <= tmp)
        {
            break;
        }
        heap[j] = heap[i];
        j = i;
        i = (j - 1) / 2;
    }

    heap[j] = tmp;
}
