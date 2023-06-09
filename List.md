## ADT List

数据对象：
- 线性表的元素集合为 { ai | ai ∈ ElemSet, i = 1, 2, ..., n, n ≥ 0 }

数据关系：
- R1 = { <ai-1, ai> | ai-1, ai ∈ D, i = 2, ..., n }

基本操作：
- `InitList(&L)`
  - 操作结果：构造一个空的线性表L。

- `DestroyList(&L)`
  - 初始条件：线性表L已存在。
  - 操作结果：销毁线性表L。

- `ClearList(&L)`
  - 初始条件：线性表L已存在。
  - 操作结果：将L重置为空表。

- `ListEmpty(L)`
  - 初始条件：线性表L已存在。
  - 操作结果：若L为空表，则返回true，否则返回false。

- `ListLength(L)`
  - 初始条件：线性表L已存在。
  - 操作结果：返回L中数据元素个数。

- `GetElem(L, i, &e)`
  - 初始条件：线性表L已存在，且1 ≤ i ≤ ListLength(L)。
  - 操作结果：用e返回L中第i个数据元素的值。

- `LocateElem(L, e)`
  - 初始条件：线性表L已存在。
  - 操作结果：返回L中第一个值与e相同的元素在L中的位置。若这样的数据元素不存在，则返回值为0。

- `PriorElem(L, cur_e, &pre_e)`
  - 初始条件：线性表L已存在。
  - 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回其前驱；否则操作失败，pre_e无定义。

- `NextElem(L, cur_e, &next_e)`
  - 初始条件：线性表L已存在。
  - 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回其后继；否则操作失败，next_e无定义。

- `ListInsert(&L, i, e)`
  - 初始条件：线性表L已存在，且1 ≤ i ≤ ListLength(L) + 1。
  - 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。

- `ListDelete(&L, i)`
  - 初始条件：线性表L已存在且非空，且1 ≤ i ≤ ListLength(L)。
  - 操作结果：删除L的第i个数据元素，L的长度减1。

- `TraverseList(L)`
  - 初始条件：线性表L已存在。
  - 操作结果：对线性表L进行遍历，在遍历过程中对L的每个结点访问一次。
