#pragma once

#include <BinaryTree.h>
#include <LinkQueue.h>

template <typename ElemType>
class BinaryTreeNode
{
public:
    ElemType data;
    BinaryTreeNode<ElemType> *left;
    BinaryTreeNode<ElemType> *right;
    BinaryTreeNode<ElemType> *parent;

    BinaryTreeNode(const ElemType &value = 0, BinaryTreeNode<ElemType> *p = nullptr, , BinaryTreeNode<ElemType> *l = nullptr, BinaryTreeNode<ElemType> *r = nullptr)
        : data(value), parent(p), left(l), right(r) {}
};

// 具体类 LinkedBinaryTree 的定义
template <typename NodeType, typename ElemType>
class LinkedBinaryTree : public BinaryTree<NodeType, ElemType>
{
public:
    LinkedBinaryTree();
    virtual ~LinkedBinaryTree();

public:
    virtual void ClearBiTree();
    virtual bool BiTreeEmpty() const;
    virtual int BiTreeDepth() const;
    virtual NodeType &Root() const;
    virtual ElemType Value(const NodeType &e) const;
    virtual void Assign(const NodeType &e, const ElemType &value);
    virtual NodeType &Parent(const NodeType &e) const;
    virtual NodeType &LeftChild(const NodeType &e) const;
    virtual NodeType &RightChild(const NodeType &e) const;
    virtual NodeType &LeftSibling(const NodeType &e) const;
    virtual NodeType &RightSibling(const NodeType &e) const;
    virtual void InsertChild(const NodeType &p, int LR, const BinaryTree<NodeType, ElemType> &c);
    virtual void DeleteChild(const NodeType &p, int LR);
    virtual void PreOrderTraverse(void (*visit)(ElemType &));
    virtual void InOrderTraverse(void (*visit)(ElemType &));
    virtual void PostOrderTraverse(void (*visit)(ElemType &));
    virtual void LevelOrderTraverse(void (*visit)(ElemType &));

private:
    NodeType *root;

private:
    friend void ClearOneNode<ElemType>(ElemType &e);

    void InOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &));
    void PreOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &));
    void PostOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &));
};

// 具体类 LinkedBinaryTree 的实现
template <typename NodeType, typename ElemType>
LinkedBinaryTree<NodeType, ElemType>::LinkedBinaryTree()
    : root(nullptr)
{
}

template <typename NodeType, typename ElemType>
LinkedBinaryTree<NodeType, ElemType>::~LinkedBinaryTree()
{
    this->ClearBiTree();
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::ClearBiTree()
{
    this->PostOrderTraverse(ClearOneNode);
}

template <typename NodeType, typename ElemType>
bool LinkedBinaryTree<NodeType, ElemType>::BiTreeEmpty() const
{
    return this->root == nullptr;
}

template <typename NodeType, typename ElemType>
int LinkedBinaryTree<NodeType, ElemType>::BiTreeDepth() const
{
    // TODO: BiTreeDepth 函数的实现
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::Root() const
{
    return *this->root;
}

template <typename NodeType, typename ElemType>
ElemType LinkedBinaryTree<NodeType, ElemType>::Value(const NodeType &e) const
{
    return e->data;
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::Assign(const NodeType &e, const ElemType &value)
{
    e->data = value;
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::Parent(const NodeType &e) const
{
    return *e->parent;
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::LeftChild(const NodeType &e) const
{
    return *e->left;
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::RightChild(const NodeType &e) const
{
    return *e->right;
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::LeftSibling(const NodeType &e) const
{
    if (e->parent->left == 0)
        return 0;
    return *(e->parent->left);
}

template <typename NodeType, typename ElemType>
NodeType &LinkedBinaryTree<NodeType, ElemType>::RightSibling(const NodeType &e) const
{
    if (e->parent->right == 0)
        return 0;
    return *(e->parent->right);
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::InsertChild(const NodeType &p, int LR, const BinaryTree<NodeType, ElemType> &c)
{
    // TODO: InsertChild 函数的实现

    switch (LR) // 0 左,1 右
    {
    case 0:
        /* code */
        break;

    default:
        break;
    }
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::DeleteChild(const NodeType &p, int LR)
{
    // TODO: DeleteChild 函数的实现
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::PreOrderTraverse(void (*visit)(ElemType &))
{
    /*
    在 PreOrderTraverse 函数中进行初始化和其他必要的操作,
    如果不用递归调用的方式,而是用栈 or 队列,
    需要在这里初始化容器,再调用
    */

    // 调用辅助函数进行递归遍历
    this->PreOrderTraverse(this->root, visit);
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::InOrderTraverse(void (*visit)(ElemType &))
{
    /*
    在 InOrderTraverse 函数中进行初始化或其他必要的操作,
    如果不用递归调用的方式,而是用栈 or 队列,
    需要在这里初始化容器,再调用
    */

    // 调用辅助函数进行递归遍历
    this->InOrderTraverseRecursive(this->root, visit);
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::PostOrderTraverse(void (*visit)(ElemType &))
{
    /*
    在 PostOrderTraverse 函数中进行初始化或其他必要的操作,
    如果不用递归调用的方式,而是用栈 or 队列,
    需要在这里初始化容器,再调用
    */

    // 调用辅助函数进行递归遍历
    this->PostOrderTraverse(this->root, visit);
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::LevelOrderTraverse(void (*visit)(ElemType &))
{
    // TODO: LevelOrderTraverse 函数的实现
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::PreOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &))
{
    if (node != nullptr)
    {
        visit(node->data);                                        // 访问当前节点
        this->PreOrderTraverseRecursive(node->leftChild, visit);  // 递归遍历左子树
        this->PreOrderTraverseRecursive(node->rightChild, visit); // 递归遍历右子树
    }
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::InOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &))
{
    if (node != nullptr)
    {
        this->InOrderTraverseRecursive(node->leftChild, visit);  // 递归遍历左子树
        visit(node->data);                                       // 访问当前节点
        this->InOrderTraverseRecursive(node->rightChild, visit); // 递归遍历右子树
    }
}

template <typename NodeType, typename ElemType>
void LinkedBinaryTree<NodeType, ElemType>::PostOrderTraverseRecursive(BinaryTreeNode<ElemType> *node, void (*visit)(ElemType &))
{
    if (node != nullptr)
    {
        this->PostOrderTraverseRecursive(node->leftChild, visit);  // 递归遍历左子树
        this->PostOrderTraverseRecursive(node->rightChild, visit); // 递归遍历右子树
        visit(node->data);                                         // 访问当前节点
    }
}
template <typename ElemType>
static void ClearOneNode(ElemType &e)
{
    delete &e;
};