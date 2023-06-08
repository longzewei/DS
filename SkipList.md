# SkipList ADT

## 类型定义
- `E`: 元素类型
- `K`: 键类型

## 成员函数
- `virtual ~SkipList()`: 虚析构函数，用于销毁 SkipList 对象。
- `virtual bool Search(const K kl, E &el) const = 0`: 虚函数，搜索指定键的元素。
  - 参数：
    - `kl`: 要搜索的键值。
    - `el`: 用于存储搜索结果的元素引用。
  - 返回值：
    - 若找到指定键的元素，则返回 `true`，并将对应的元素存储在 `el` 中；否则返回 `false`。
- `virtual bool Insert(const K kl, E &el) = 0`: 虚函数，插入元素到 SkipList 中。
  - 参数：
    - `kl`: 要插入的键值。
    - `el`: 要插入的元素。
  - 返回值：
    - 若插入成功，则返回 `true`；否则返回 `false`。
- `virtual bool Remove(const K kl, E &el) = 0`: 虚函数，从 SkipList 中删除指定键的元素。
  - 参数：
    - `kl`: 要删除的键值。
    - `el`: 用于存储被删除元素的引用。
  - 返回值：
    - 若删除成功，则返回 `true`，并将被删除的元素存储在 `el` 中；否则返回 `false`。
