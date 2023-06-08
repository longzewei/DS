#pragma once
template <typename T, typename Node>
class BinaryTree
{
public:
    virtual void CreateTree() = 0;
    virtual void ClearBiTree() = 0;
    virtual BinaryTree<T, Node> *CopyTree() const = 0;
    virtual int BiTreeDepth() const = 0;
    virtual int NodeCount() const = 0;
    virtual void InOrderTraverse() const = 0;
    virtual bool BiTreeEmpty() const = 0;
    virtual Node *Root() const = 0;
    virtual bool Root(T value, int weight) = 0;
    virtual T Value(const Node *node) const = 0;
    virtual void Assign(Node *node, const T &value, int weight) = 0;
    virtual Node *Parent(const Node *node) const = 0;
    virtual Node *LeftChild(const Node *node) const = 0;
    virtual Node *RightChild(const Node *node) const = 0;
    virtual Node *LeftSibling(const Node *node) const = 0;
    virtual Node *RightSibling(const Node *node) const = 0;
    virtual void InsertChild(Node *p, int LR, BinaryTree<T, Node> *c) = 0;
    virtual void DeleteChild(Node *p, int LR) = 0;
    virtual ~BinaryTree() {}
};
