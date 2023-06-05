ADT Tree
===============

数据对象 D：D 是具有相同特性的数据元素的集合。

数据关系 R：
- 若 D 为空集，则称为空树；
- 若 D 仅含一个数据元素，则 R 为空集；
- 否则 R = {H}，H 是如下二元关系：
  - 在 D 中存在唯一的称为根的数据元素 root，它在关系 H 下无前驱；
  - 若 D - {root} ≠ φ，则存在 D - {root} 的一个划分 D1, D2, ..., Dm（m > 0)，
    对任意 j ≠ k（1 ≤ j, k ≤ m）有 Dj ∩ Dk = ∅，
    且对任意的 i（1 ≤ i ≤ m)，唯一存在数据元素 Xi ∈ Di，有 <root, xi> ∈ H；
  - 对应于 D - {root} 的划分，H - {<root, x1>, ..., <root, xm>} 有唯一的一个划分 H1, H2, ...,
    Hm（m > 0），对任意 j ≠ k（1 ≤ j, k ≤ m）有 Hj ∩ Hk = ∅，
    且对任意 i（1 ≤ i ≤ m)，H2 是 D2 上的二元关系，（Di, {Hi}) 是一棵符合本定义的树，称为根 root 的子树。

基本操作 P：
- InitTree(&T)
  - 操作结果：构造空树 T。
- DestroyTree(&T)
  - 初始条件：树 T 存在。
  - 操作结果：销毁树 T。
- CreateTree(&T, definition)
  - 初始条件：definition 给出树 T 的定义。
  - 操作结果：按 definition 构造树 T。
- ClearTree(&T)
  - 初始条件：树 T 存在。
  - 操作结果：将树 T 清为空树。
- TreeEmpty(T)
  - 初始条件：树 T 存在。
  - 操作结果：若 T 为空树，则返回 true，否则返回 false。
- TreeDepth(T)
  - 初始条件：树 T 存在。
  - 操作结果：返回 T 的深度。
- Root(T)
  - 初始条件：树 T 存在。
  - 操作结果：返回 T 的根。
- Value(T, cur_e)
  - 初始条件：树 T 存在，cur_e 是 T 中某个结点。
  - 操作结果：返回 cur_e 的值。
- Assign(T, cur_e, value)
  - 初始条件：树 T 存在，cur_e 是 T 中某个结点。
  - 操作结果：结点 cur_e 赋值为 value。
- Parent(T, cur_e)
  - 初始条件：树 T 存在，cur_e 是 T 中某个结点。
  - 操作结果：若 cur_e 是 T 的非根结点，则返回它的双亲，否则函数值为“空”。
- LeftChild(T, cur_e)
  - 初始条件：树 T 存在，cur_e 是 T 中某个结点。
  - 操作结果：若 cur_e 是 T 的非叶子结点，则返回它的最左孩子，否则返回“空”。
- RightSibling(T, cur_e)
  - 初始条件：树 T 存在，cur_e 是 T 中某个结点。
  - 操作结果：若 cur_e 有右兄弟，则返回它的右兄弟，否则函数值为“空”。
- InsertChild(&T, p, i, c)
  - 初始条件：树 T 存在，p 指向 T 中某个结点，1 ≤ i ≤ p 所指结点的度 + 1，非空树 c 与 T 不相交。
  - 操作结果：插入 c 为 T 中 p 指结点的第 i 棵子树。
- DeleteChild(&T, p, i)
  - 初始条件：树 T 存在，p 指向 T 中某个结点，1 ≤ i ≤ p 指结点的度。
  - 操作结果：删除 T 中 p 所指结点的第 i 棵子树。
- TraverseTree(T)
  - 初始条件：树 T 存在。
  - 操作结果：按某种次序对 T 的每个结点访问一次。

