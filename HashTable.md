## HashTable 抽象数据类型 (ADT)

### 属性

- 无

### 方法

- `HashTable()`: 构造函数，创建一个新的散列表。
- `~HashTable()`: 虚析构函数，释放散列表使用的内存。
- `Search(kl: K, el: E&) -> bool`: 纯虚函数，在散列表中搜索键为 `kl` 的元素，并将找到的元素存储在 `el` 中。如果找到返回 `true`，否则返回 `false`。
- `Insert(el: E) -> bool`: 纯虚函数，将元素 `el` 插入到散列表中。如果成功插入返回 `true`，否则返回 `false`。
- `Remove(kl: K, el: E&) -> bool`: 纯虚函数，从散列表中删除键为 `kl` 的元素，并将删除的元素存储在 `el` 中。如果成功删除返回 `true`，否则返回 `false`。
- `makeEmpty()`: 纯虚函数，将散列表置空，删除所有元素。
