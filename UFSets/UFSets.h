#pragma once

template <typename T>
class UFSets
{
public:
    UFSets();
    ~UFSets();
    UFSets &operator=(const UFSets &R);
    void Union(T Root1, T Root2);
    T Find(T x);
    void WeightedUnion(T Root1, T Root2);

private:
    T *parent;
    int *weight;
    int size; // 集合的大小

    // 辅助函数
    void Resize(int newSize);
};

template <typename T>
UFSets<T>::UFSets()
{
    parent = nullptr;
    weight = nullptr;
    size = 0;
}

template <typename T>
UFSets<T>::~UFSets()
{
    delete[] parent;
    delete[] weight;
}

template <typename T>
UFSets<T> &UFSets<T>::operator=(const UFSets<T> &R)
{
    if (this != &R)
    {
        delete[] parent;
        delete[] weight;

        Resize(R.size);

        for (int i = 0; i < R.size; i++)
        {
            parent[i] = R.parent[i];
            weight[i] = R.weight[i];
        }
    }
    return *this;
}

template <typename T>
void UFSets<T>::Resize(int newSize)
{
    T *newParent = new T[newSize];
    int *newWeight = new int[newSize];

    for (int i = 0; i < newSize; i++)
    {
        if (i < size)
        {
            newParent[i] = parent[i];
            newWeight[i] = weight[i];
        }
        else
        {
            newParent[i] = i;
            newWeight[i] = 1;
        }
    }

    delete[] parent;
    delete[] weight;

    parent = newParent;
    weight = newWeight;
    size = newSize;
}

template <typename T>
void UFSets<T>::Union(T Root1, T Root2)
{
    T maxRoot = std::max(Root1, Root2);

    if (maxRoot >= size)
    {
        Resize(maxRoot + 1);
    }

    parent[Root2] = Root1;
}

template <typename T>
T UFSets<T>::Find(T x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

template <typename T>
void UFSets<T>::WeightedUnion(T Root1, T Root2)
{
    if (weight[Root1] < weight[Root2])
    {
        parent[Root1] = Root2;
        weight[Root2] += weight[Root1];
    }
    else
    {
        parent[Root2] = Root1;
        weight[Root1] += weight[Root2];
    }
}