## ADT Set

### 数据

无数据成员

### 方法

- `Set()`
  - 构造函数，创建一个空的集合。

- `makeEmpty()`
  - 置空集合，使集合中不包含任何元素。

- `addMember(const T x)`
  - 加入新成员 `x` 到集合中。如果成功添加，则返回 `true`，否则返回 `false`。

- `delMember(const T x)`
  - 删除集合中的成员 `x`。如果成功删除，则返回 `true`，否则返回 `false`。

- `intersectWith(const Set<T>& R)`
  - 返回当前集合与集合 `R` 的交集。

- `unionWith(const Set<T>& R)`
  - 返回当前集合与集合 `R` 的并集。

- `differenceFrom(const Set<T>& R)`
  - 返回当前集合与集合 `R` 的差集。

- `Contains(const T x)`
  - 判断元素 `x` 是否是集合的成员。如果是成员，则返回 `true`，否则返回 `false`。

- `subSet(const Set<T>& R)`
  - 判断当前集合是否是集合 `R` 的子集。如果是子集，则返回 `true`，否则返回 `false`。

- `operator==(const Set<T>& R)`
  - 判断当前集合与集合 `R` 是否相等。如果相等，则返回 `true`，否则返回 `false`。
