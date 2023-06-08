# ADT UFSets

## 类型定义
- UFSets
  - 描述：并查集类，用于处理不相交集合的合并与查找操作。
  - 成员变量：
    - parent：父指针数组，用于记录每个元素的根节点。
    - size：集合元素的数目。
  - 成员函数：
    - UFSets(sz: int = DefaultSize)：构造函数，创建指定大小的并查集对象。
    - ~UFSets()：析构函数，释放内存。
    - operator= (R: UFSets&)：重载赋值运算符，将一个并查集对象赋值给另一个对象。
    - Union(Root1: int, Root2: int)：合并两个子集合，将Root2的根节点合并到Root1的根节点。
    - Find(x: int) -> int：查找元素x所在集合的根节点。
    - WeightedUnion(Root1: int, Root2: int)：加权的合并算法，根据集合大小合并两个子集合。

### 构造函数 UFSets

**描述**：创建指定大小的并查集对象。

#### 参数

- sz: int (可选) - 集合的大小，默认为 DefaultSize。

### 析构函数 ~UFSets

**描述**：释放内存。

### 重载函数 operator=

**描述**：将一个并查集对象赋值给另一个对象。

#### 参数

- R: UFSets& - 要赋值的并查集对象。

### 函数 Union

**描述**：合并两个子集合，将Root2的根节点合并到Root1的根节点。

#### 参数

- Root1: int - 第一个子集合的根节点。
- Root2: int - 第二个子集合的根节点。

### 函数 Find

**描述**：查找元素x所在集合的根节点。

#### 参数

- x: int - 要查找的元素。

#### 返回值

- int - 元素x所在集合的根节点。

### 函数 WeightedUnion

**描述**：加权的合并算法，根据集合大小合并两个子集合。

#### 参数

- Root1: int - 第一个子集合的根节点。
- Root2: int - 第二个子集合的根节点.

