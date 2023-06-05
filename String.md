### ADT String

数据对象：D={ailaiECharacterSet,i=1,2,…,n,n≥0}

数据关系:Rl={<ai-1,ai>lai-1,aiED,i=2,…,n}

#### 基本操作：

- StrAssign (&T, chars)
    初始条件：chars 是字符串常量。
    操作结果：生成一个其值等于 chars 的串 T。

- StrCopy(&T,S)
    初始条件：串s存在。
    操作结果：由串s复制得串T。

- StrEmpty(S)
    初始条件：串s存在。
    操作结果：若s为空串，则返回true，否则返回false。

- StrCompare(S,T)
    初始条件：串s和T存在。
    操作结果：若S>T，则返回值>0；若S=T，则返回值=O；若S<T，则返回值<O。

- StrLength (S)
    初始条件：串s存在。
    操作结果：返回s的元素个数，称为串的长度。

- ClearString(&S)
    初始条件：串s存在。
    操作结果：将s清为空串。

- Concat (&T, S1,S2)
    初始条件：串s1和s2存在。
    操作结果：用T返回由s1和s2联接而成的新串。

- SubString (&Sub, S,pos,len)
    初始条件：串s存在，1≤pos≤StrLength(S)且0≤len≤StrLength(S)-pos+1。
    操作结果：用Sub 返回串s的第pos个字符起长度为len的子串。

- Index(S,T,pos)
    初始条件：串S和T存在，T是非空串，1≤pos≤StrLength(S)。
    操作结果：若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置；否则函数值为0。

- Replace (&S, T, V)
    初始条件：串s，T和v存在，T是非空串。
    操作结果：用v替换主串s中出现的所有与T相等的不重叠的子串。

- StrInsert (&S,pos,T)
    初始条件：串s和T存在，1≤pos≤StrLength(S)+1。
    操作结果：在串S的第pos个字符之前插入串T。

- StrDelete(&S,pos,len)
    初始条件：串s存在，1≤pos≤StrLength(S)-len+1。
    操作结果：从串s中删除第pos个字符起长度为len的子串。

- DestroyString(&S)
    初始条件：串s存在。
    操作结果：串s被销毁。
