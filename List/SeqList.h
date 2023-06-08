#include <iostream>
#include <chrono>

#include "List.h"

#define DEFAULTCAPACITY 3

// 具体实现的顺序表类
template <typename T>
class SeqList : public List<T>
{
private:
    T *elem;      // 存储线性表元素的数组
    int length;   // 线性表的长度
    int capacity; // 数组的容量

public:
    // 构造函数
    SeqList(int n = DEFAULTCAPACITY);

    // 析构函数
    ~SeqList();

    // 置空线性表
    void ClearList();

    // 判断线性表是否为空
    bool ListIsEmpty() const;

    // 获取线性表的元素个数
    int ListLength() const;

    // 获取线性表的第 i 个元素的值
    bool GetElem(int i, T &e) const;

    // 确定元素 e 在线性表中的位置
    int LocateElem(const T &e) const;

    // 获取指定元素的前驱
    bool PriorElem(const T &cur_e, T &pre_e) const;

    // 获取指定元素的后继
    bool NextElem(const T &cur_e, T &next_e) const;

    // 在指定位置插入元素
    bool ListInsert(int i, const T &e);

    // 删除指定位置的元素
    bool ListDelete(int i);

    // 遍历线性表
    void TraverseList(void (*visit)(T &));

    bool sort() override;

protected:
    bool expand();
    bool shrink();

protected:
    // 插入排序
    bool InsertionSort();

    // 折半插入排序
    bool BinaryInsertionSort();

    // 希尔排序
    bool ShellSort();

    // 冒泡排序
    bool BubbleSort();

    // 快速排序
    bool QuickSort(int low, int high);

    // 简单选择排序
    bool SelectionSort();

    // 归并排序
    bool MergeSort(int left, int right);
};

// 构造函数
template <typename T>
SeqList<T>::SeqList(int n)
{
    this->elem = new T[n];
    this->length = 0;
    this->capacity = n;
}

// 析构函数
template <typename T>
SeqList<T>::~SeqList()
{
    delete[] this->elem;
}

// 置空线性表
template <typename T>
void SeqList<T>::ClearList()
{
    this->length = 0;
}

// 判断线性表是否为空
template <typename T>
bool SeqList<T>::ListIsEmpty() const
{
    return (this->length == 0);
}

// 获取线性表的元素个数
template <typename T>
int SeqList<T>::ListLength() const
{
    return this->length;
}

// 获取线性表的第 i 个元素的值
template <typename T>
bool SeqList<T>::GetElem(int i, T &e) const
{
    if (i < 1 || i > this->length)
        return false;

    e = this->elem[i - 1];
    return true;
}

// 确定元素 e 在线性表中的位置
template <typename T>
int SeqList<T>::LocateElem(const T &e) const
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 获取指定元素的前驱
template <typename T>
bool SeqList<T>::PriorElem(const T &cur_e, T &pre_e) const
{
    int cur_index = LocateElem(cur_e);
    if (cur_index != 0 && cur_index != 1)
    {
        pre_e = this->elem[cur_index - 2];
        return true;
    }
    return false;
}

// 获取指定元素的后继
template <typename T>
bool SeqList<T>::NextElem(const T &cur_e, T &next_e) const
{
    int cur_index = LocateElem(cur_e);
    if (cur_index != 0 && cur_index != this->length)
    {
        next_e = this->elem[cur_index];
        return true;
    }
    return false;
}

// 在指定位置插入元素
template <typename T>
bool SeqList<T>::ListInsert(int i, const T &e)
{
    if (i < 1 || i > this->length + 1)
        return false;

    if (!this->expand())
        return false;

    for (int j = this->length - 1; j >= i - 1; j--)
    {
        this->elem[j + 1] = this->elem[j];
    }
    this->elem[i - 1] = e;
    this->length++;

    return true;
}

// 删除指定位置的元素
template <typename T>
bool SeqList<T>::ListDelete(int i)
{
    if (i < 1 || i > this->length)
        return false;

    for (int j = i; j < this->length; j++)
    {
        this->elem[j - 1] = this->elem[j];
    }
    this->length--;

    if (this->length <= this->capacity / 2)
        shrink();

    return true;
}

// 遍历线性表
template <typename T>
void SeqList<T>::TraverseList(void (*visit)(T &))
{
    for (int i = 0; i < this->length; i++)
    {
        visit(this->elem[i]);
    }
}

// 扩展数组容量
template <typename T>
bool SeqList<T>::expand()
{
    if (this->length < this->capacity)
        return true;

    T *newElem = new T[this->capacity << 1];
    if (!newElem)
        return false;

    for (int i = 0; i < this->length; i++)
    {
        newElem[i] = this->elem[i];
    }

    delete[] this->elem;
    this->elem = newElem;
    this->capacity <<= 1;

    return true;
}

// 缩小数组容量
template <typename T>
bool SeqList<T>::shrink()
{
    if (this->capacity <= DEFAULTCAPACITY)
        return false;

    T *newElem = new T[this->capacity >> 2];
    if (!newElem)
        return false;

    for (int i = 0; i < this->length; i++)
    {
        newElem[i] = this->elem[i];
    }

    delete[] this->elem;
    this->elem = newElem;
    this->capacity >>= 2;

    return true;
}

template <typename T>
bool SeqList<T>::sort()
{
    // 获取当前时间点
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // 获取时间戳
    long long timestamp_nanoseconds = std::chrono::time_point_cast<std::chrono::nanoseconds>(now).time_since_epoch().count();

    int choice = timestamp_nanoseconds % 7; // 生成0到6之间的随机数

    switch (choice)
    {
    case 0:
        return BubbleSort();
    case 1:
        return QuickSort(0, this->length - 1);
    case 2:
        return SelectionSort();
    case 3:
        return MergeSort(0, this->length - 1);
    case 4:
        return InsertionSort();
    case 5:
        return BinaryInsertionSort();
    case 6:
        return ShellSort();
    default:
        return false;
    }
}

// 冒泡排序
template <typename T>
bool SeqList<T>::BubbleSort()
{
    for (int i = 0; i < this->length - 1; i++)
    {
        for (int j = 0; j < this->length - i - 1; j++)
        {
            if (this->elem[j] > this->elem[j + 1])
            {
                T temp = this->elem[j];
                this->elem[j] = this->elem[j + 1];
                this->elem[j + 1] = temp;
            }
        }
    }
    return true;
}

// 快速排序
template <typename T>
bool SeqList<T>::QuickSort(int low, int high)
{
    if (low < high)
    {
        int i = low, j = high;
        T pivot = this->elem[low];
        while (i < j)
        {
            while (i < j && this->elem[j] >= pivot)
                j--;
            if (i < j)
                this->elem[i++] = this->elem[j];
            while (i < j && this->elem[i] <= pivot)
                i++;
            if (i < j)
                this->elem[j--] = this->elem[i];
        }
        this->elem[i] = pivot;
        QuickSort(low, i - 1);
        QuickSort(i + 1, high);
    }
    return true;
}

// 简单选择排序
template <typename T>
bool SeqList<T>::SelectionSort()
{
    for (int i = 0; i < this->length - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < this->length; j++)
        {
            if (this->elem[j] < this->elem[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            T temp = this->elem[i];
            this->elem[i] = this->elem[minIndex];
            this->elem[minIndex] = temp;
        }
    }
    return true;
}

// 归并排序
template <typename T>
bool SeqList<T>::MergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);

        int i = left, j = mid + 1, k = 0;
        T *temp = new T[right - left + 1];

        while (i <= mid && j <= right)
        {
            if (this->elem[i] <= this->elem[j])
                temp[k++] = this->elem[i++];
            else
                temp[k++] = this->elem[j++];
        }

        while (i <= mid)
            temp[k++] = this->elem[i++];
        while (j <= right)
            temp[k++] = this->elem[j++];

        for (int m = 0, n = left; m < k; m++, n++)
            this->elem[n] = temp[m];

        delete[] temp;
    }
    return true;
}

// 插入排序
template <typename T>
bool SeqList<T>::InsertionSort()
{
    for (int i = 1; i < this->length; i++)
    {
        T temp = this->elem[i];
        int j = i - 1;
        while (j >= 0 && this->elem[j] > temp)
        {
            this->elem[j + 1] = this->elem[j];
            j--;
        }
        this->elem[j + 1] = temp;
    }
    return true;
}

// 折半插入排序
template <typename T>
bool SeqList<T>::BinaryInsertionSort()
{
    for (int i = 1; i < this->length; i++)
    {
        T temp = this->elem[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (this->elem[mid] > temp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
        {
            this->elem[j + 1] = this->elem[j];
        }
        this->elem[left] = temp;
    }
    return true;
}

// 希尔排序
template <typename T>
bool SeqList<T>::ShellSort()
{
    int gap = this->length / 2;
    while (gap > 0)
    {
        for (int i = gap; i < this->length; i++)
        {
            T temp = this->elem[i];
            int j = i - gap;
            while (j >= 0 && this->elem[j] > temp)
            {
                this->elem[j + gap] = this->elem[j];
                j -= gap;
            }
            this->elem[j + gap] = temp;
        }
        gap /= 2;
    }
    return true;
}
