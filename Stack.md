## ADT Stack

数据对象：D = { a1, a2, ..., an, n ≥ 0 }

数据关系：R = { < ai-1, ai > | ai-1, ai ∈ ElemSet, i = 2, 3, ..., n }

约定 an 端为栈顶，a1 端为栈底。

基本操作：

- InitStack(&S)

  操作结果：构造一个空栈 S。

- DestroyStack(&S)

  初始条件：栈 S 已存在。

  操作结果：栈 S 被销毁。

- ClearStack(&S)

  初始条件：栈 S 已存在。

  操作结果：将 S 清为空栈。

- StackEmpty(S)

  初始条件：栈 S 已存在。

  操作结果：若栈 S 为空栈，则返回 true，否则返回 false。

- StackLength(S)

  初始条件：栈 S 已存在。

  操作结果：返回 S 的元素个数，即栈的长度。

- GetTop(S)

  初始条件：栈 S 已存在且非空。

  操作结果：返回 S 的栈顶元素，不修改栈顶指针。

- Push(&S, e)

  初始条件：栈 S 已存在。

  操作结果：插入元素 e 为新的栈顶元素。

- Pop(&S, &e)

  初始条件：栈 S 已存在且非空。

  操作结果：删除 S 的栈顶元素，并用 e 返回其值。

- StackTraverse(S)

  初始条件：栈 S 已存在且非空。

  操作结果：从栈底到栈顶依次对 S 的每个数据元素进行访问。
