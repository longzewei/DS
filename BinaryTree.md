ADT BinaryTree
================

数据对象 D：D 是具有相同特性的数据元素的集合。

数据关系 R：
- 若 D = ∅ ，则 R = ∅ ，称 BinaryTree 为空二叉树；
- 若 D ≠ ∅ ，则 R = {H} ，H 是如下二元关系：
  - 在 D 中存在唯一的称为根的数据元素 root ，它在关系 H 下无前驱；
  - 若 D - {root} ≠ ∅ ，则存在 D - {root} = {D1, Dr} ，且 D1 ∩ Dr = ∅ ；
  - 若 D1 ≠ ∅ ，则 D1 中存在唯一的元素 x1 ，<root, x1> ∈ H ，且存在 D1 上的关系 H1 ∈ H ；
  - 若 Dr ≠ ∅ ，则 Dr 中存在唯一的元素 xr ，<root, xr> ∈ H ，且存在 Dr 上的关系 Hr ∈ H ；
  - H = {<root, x1>, <root, xr>, H1, Hr} ；
  - (D1, {H2}) 是一棵符合本定义的二叉树，称为根的左子树；
  - (D2, {H}) 是一棵符合本定义的二叉树，称为根的右子树。

基本操作 P：
- InitBiTree(&T)
  - 操作结果：构造空二叉树 T 。
- DestroyBiTree(&T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：销毁二叉树 T 。
- CreateBiTree(&T, definition)
  - 初始条件：definition 给出二叉树 T 的定义。
  - 操作结果：按 definition 构造二叉树 T 。
- ClearBiTree(&T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：将二叉树 T 清为空树。
- BiTreeEmpty(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：若 T 为空二叉树，则返回 true ，否则返回 false 。
- BiTreeDepth(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：返回 T 的深度。
- Root(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：返回 T 的根。
- Value(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：返回 e 的值。
- Assign(T, &e, value)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：结点 e 赋值为 value 。
- Parent(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：若 e 是 T 的非根结点，则返回它的双亲，否则返回“空”。
- LeftChild(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：返回 e 的左孩子。若 e 无左孩子，则返回“空”。
- RightChild(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：返回 e 的右孩子。若 e 无右孩子，则返回“空”。
- LeftSibling(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：返回 e 的左兄弟。若 e 是 T 的左孩子或无左兄弟，则返回“空”。
- RightSibling(T, e)
  - 初始条件：二叉树 T 存在，e 是 T 中某个结点。
  - 操作结果：返回 e 的右兄弟。若 e 是 T 的右孩子或无右兄弟，则返回“空”。
- InsertChild(&T, p, LR, c)
  - 初始条件：二叉树 T 存在，p 指向 T 中某个结点，LR 为 0 或 1，非空二叉树 c 与 T 不相交且右子树为空。
  - 操作结果：根据 LR 为 0 或 1，插入 c 为 T 中 p 所指结点的左或右子树。p 所指结点的原有左或右子树则成为 c 的右子树。
- DeleteChild(&T, p, LR)
  - 初始条件：二叉树 T 存在，p 指向 T 中某个结点，LR 为 0 或 1。
  - 操作结果：根据 LR 为 0 或 1，删除 T 中 p 所指结点的左或右子树。
- PreOrderTraverse(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：先序遍历 T ，对每个结点访问一次。
- InOrderTraverse(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：中序遍历 T ，对每个结点访问一次。
- PostOrderTraverse(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：后序遍历 T ，对每个结点访问一次。
- LevelOrderTraverse(T)
  - 初始条件：二叉树 T 存在。
  - 操作结果：层序遍历 T ，对每个结点访问一次。

