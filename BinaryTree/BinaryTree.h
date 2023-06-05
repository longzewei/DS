#pragma once

template <typename NodeType, typename ElemType>
class BinaryTree
{
public:
    BinaryTree() {}
    virtual ~BinaryTree() {}

public:
    virtual void ClearBiTree() = 0;
    virtual bool BiTreeEmpty() const = 0;
    virtual int BiTreeDepth() const = 0;
    virtual NodeType &Root() const = 0;
    virtual ElemType Value(const NodeType &e) const = 0;
    virtual void Assign(const NodeType &e, const ElemType &value) = 0;
    virtual NodeType &Parent(const NodeType &e) const = 0;
    virtual NodeType &LeftChild(const NodeType &e) const = 0;
    virtual NodeType &RightChild(const NodeType &e) const = 0;
    virtual NodeType &LeftSibling(const NodeType &e) const = 0;
    virtual NodeType &RightSibling(const NodeType &e) const = 0;
    virtual void InsertChild(const NodeType &p, int LR, const BinaryTree<NodeType, ElemType> &c) = 0;
    virtual void DeleteChild(const NodeType &p, int LR) = 0;
    virtual void PreOrderTraverse(void (*visit)(ElemType &)) = 0;
    virtual void InOrderTraverse(void (*visit)(ElemType &)) = 0;
    virtual void PostOrderTraverse(void (*visit)(ElemType &)) = 0;
    virtual void LevelOrderTraverse(void (*visit)(ElemType &)) = 0;
};
