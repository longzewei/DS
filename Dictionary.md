## Dictionary<Name, Attribute>

字典的抽象数据类型。包含一组<名字-属性>对，其中名字是唯一的。

#### 构造函数

- `Dictionary(int size = DefaultSize)`

  建立一个容量为size的空字典。

#### 成员函数

- `bool Member(Name name)`

  若name在字典中，则返回true，否则返回false。

- `Attribute* Search(Name name)`

  若name在字典中，则返回指向相应Attr的指针，否则返回0。

- `void Insert(Name name, Attribute attr)`

  若name在字典中，则修改相应<name，Attr>对的attr项，否则插入<name, Attr>到字典中。

- `void Remove(Name name)`

  若name在字典中，则在字典中删除相应的<name，Attr>对。
