## ADT MinHeap

### 数据

- `heap`：数组，存放堆元素
- `currentSize`：整数，当前堆中元素的数量
- `maxHeapSize`：整数，堆数组的最大容量

### 方法

- `MinHeap(int sz = DefaultSize)`
    - 构造函数，创建一个空的最小堆。可以指定堆的初始容量，默认为 `DefaultSize`。

- `MinHeap(E arr[], int n)`
    - 构造函数，通过一个数组建堆。数组 `arr` 包含 `n` 个元素。

- `~MinHeap()`
    - 析构函数，销毁堆对象。

- `bool Insert(const E& x)`
    - 将元素 `x` 插入到最小堆中。返回插入操作是否成功。

- `bool RemoveMin(E& x)`
    - 删除堆顶上的最小元素，并将其存储在变量 `x` 中。返回删除操作是否成功。

- `bool IsEmpty() const`
    - 判堆空否。如果堆为空，返回 `true`，否则返回 `false`。

- `bool IsFull() const`
    - 判堆满否。如果堆已满，返回 `true`，否则返回 `false`。

- `void MakeEmpty()`
    - 置空堆，使堆中的元素数量为零。
