# ADT Graph

## 数据对象
- `v`：具有相同特性的数据元素的集合，称为顶点集。

## 数据关系
- `R`：弧集合
- `VR`：弧关系集合，表示从顶点 `V` 到顶点 `W` 的弧，谓词 `P(v, W)` 定义了弧 `<v, W>` 的意义或信息。

## 基本操作
- `CreateGraph(&G, V, VR)`: 初始化图 `G`，其中 `V` 是顶点集，`VR` 是弧关系集。
- `DestroyGraph(&G)`: 销毁图 `G`。
- `LocateVex(G, u)`: 获取顶点 `u` 在图 `G` 中的位置。
- `GetVex(G, v)`: 返回顶点 `v` 的值。
- `PutVex(&G, v, value)`: 将顶点 `v` 的值设置为 `value`。
- `FirstAdjVex(G, v)`: 返回顶点 `v` 的第一个邻接顶点。
- `NextAdjVex(G, v, w)`: 返回顶点 `v` 相对于邻接顶点 `w` 的下一个邻接顶点。
- `InsertVex(&G, V)`: 在图 `G` 中增添新顶点 `V`。
- `DeleteVex(&G, v)`: 删除图 `G` 中顶点 `v` 及其相关的弧。
- `InsertArc(&G, v, w)`: 在图 `G` 中增添弧 `<v, w>`，若 `G` 是无向图，则还增添对称弧 `<w, v>`。
- `DeleteArc(&G, v, w)`: 在图 `G` 中删除弧 `<v, w>`，若 `G` 是无向图，则还删除对称弧 `<w, v>`。
- `DESTraverse(G)`: 对图 `G` 进行深度优先遍历。
- `BESTraverse(G)`: 对图 `G` 进行广度优先遍历。

---

ADT 图（Graph）

数据：
- 顶点集合 V：存储图中所有顶点的集合
- 边集合 E：存储图中所有边的集合

操作：
- `CreateGraph(&G, V, E)`: 创建一个空图G，其中V为顶点集合，E为边集合
- `DestroyGraph(&G)`: 销毁图G，释放相关资源
- `LocateVex(G, v)`: 返回顶点v在图G中的位置
- `GetVex(G, v)`: 返回顶点v的值
- `PutVex(&G, v, value)`: 修改顶点v的值为value
- `FirstAdjVex(G, v)`: 返回顶点v的第一个邻接顶点
- `NextAdjVex(G, v, w)`: 返回顶点v相对于顶点w的下一个邻接顶点
- `InsertVex(&G, v)`: 在图G中插入新顶点v
- `DeleteVex(&G, v)`: 删除图G中的顶点v以及与其相关的边
- `InsertArc(&G, v, w)`: 在图G中插入由顶点v和w构成的新边
- `DeleteArc(&G, v, w)`: 删除图G中顶点v和w之间的边
- `DFSTraverse(G)`: 深度优先遍历图G
- `BFSTraverse(G)`: 广度优先遍历图G
