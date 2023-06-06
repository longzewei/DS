#include <iostream>
#include "BinaryTree.h" // 包含BinaryTree抽象类的头文件

template <typename T>
struct BiNode
{
    T data;
    BiNode<T> *lchild;
    BiNode<T> *rchild;
    BiNode<T> *parent;
};

template <typename T>
class BiTree : public BinaryTree<T, BiNode<T>> // 继承自BinaryTree抽象类
{
public:
    BiTree();
    void CreateTree();                          // 创建二叉树
    void ClearBiTree();                         // 清空二叉树
    BinaryTree<T, BiNode<T>> *CopyTree() const; // 复制二叉树
    int BiTreeDepth() const;                    // 计算二叉树的深度
    int NodeCount() const;                      // 计算二叉树的节点数
    void InOrderTraverse() const;               // 中序遍历二叉树
    bool BiTreeEmpty() const;                   // 判断二叉树是否为空
    BiNode<T> *Root() const;                    // 获取二叉树的根节点
    bool Root(T value);
    T Value(const BiNode<T> *node) const;                                // 获取节点的值
    void Assign(BiNode<T> *node, const T &value);                        // 设置节点的值
    BiNode<T> *Parent(const BiNode<T> *node) const;                      // 获取节点的父节点
    BiNode<T> *LeftChild(const BiNode<T> *node) const;                   // 获取节点的左孩子
    BiNode<T> *RightChild(const BiNode<T> *node) const;                  // 获取节点的右孩子
    BiNode<T> *LeftSibling(const BiNode<T> *node) const;                 // 获取节点的左兄弟
    BiNode<T> *RightSibling(const BiNode<T> *node) const;                // 获取节点的右兄弟
    void InsertChild(BiNode<T> *p, int LR, BinaryTree<T, BiNode<T>> *c); // 在指定节点的左子树或右子树插入一个二叉树,LR 插入的位置，0表示左子树，1表示右子树
    void DeleteChild(BiNode<T> *p, int LR);                              // 删除指定节点的左子树或右子树,LR 删除的位置，0表示左子树，1表示右子树

private:
    BiNode<T> *root;

    void CreateBiTree(BiNode<T> *&node);                     // 递归创建二叉树
    void Copy(const BiNode<T> *src, BiNode<T> *&dest) const; // 递归复制二叉树
    int CalculateDepth(const BiNode<T> *node) const;         // 递归计算二叉树的深度
    int CalculateNodeCount(const BiNode<T> *node) const;     // 递归计算二叉树的节点数
    void InOrder(const BiNode<T> *node) const;               // 递归中序遍历二叉树
    void DestroyBiTree(BiNode<T> *&node);                    // 递归销毁二叉树
};

template <typename T>
BiTree<T>::BiTree() : root(nullptr)
{
}

template <typename T>
void BiTree<T>::CreateTree()
{
    CreateBiTree(root);
}

template <typename T>
void BiTree<T>::ClearBiTree()
{
    DestroyBiTree(root);
    root = nullptr;
}

template <typename T>
BinaryTree<T, BiNode<T>> *BiTree<T>::CopyTree() const
{
    BiTree<T> *copy = new BiTree<T>();
    Copy(root, copy->root);
    return copy;
}

template <typename T>
int BiTree<T>::BiTreeDepth() const
{
    return CalculateDepth(root);
}

template <typename T>
int BiTree<T>::NodeCount() const
{
    return CalculateNodeCount(root);
}

template <typename T>
void BiTree<T>::InOrderTraverse() const
{
    InOrder(root);
}

template <typename T>
bool BiTree<T>::BiTreeEmpty() const
{
    return (root == nullptr);
}

template <typename T>
BiNode<T> *BiTree<T>::Root() const
{
    return root;
}

template <typename T>
bool BiTree<T>::Root(T value)
{
    if (root == nullptr)
    {
        root = new BiNode<T>;
        root->data = value;
        root->lchild = nullptr;
        root->rchild = nullptr;
        root->parent = nullptr;
        return true;
    }
    else
    {
        root->data = value;
        return false;
    }
}

template <typename T>
T BiTree<T>::Value(const BiNode<T> *node) const
{
    return node->data;
}

template <typename T>
void BiTree<T>::Assign(BiNode<T> *node, const T &value)
{
    node->data = value;
}

template <typename T>
BiNode<T> *BiTree<T>::Parent(const BiNode<T> *node) const
{
    return node->parent;
}

template <typename T>
BiNode<T> *BiTree<T>::LeftChild(const BiNode<T> *node) const
{
    return node->lchild;
}

template <typename T>
BiNode<T> *BiTree<T>::RightChild(const BiNode<T> *node) const
{
    return node->rchild;
}

template <typename T>
BiNode<T> *BiTree<T>::LeftSibling(const BiNode<T> *node) const
{
    if (node->parent == nullptr)
        return nullptr;
    else if (node == node->parent->lchild)
        return nullptr;
    else
        return node->parent->lchild;
}

template <typename T>
BiNode<T> *BiTree<T>::RightSibling(const BiNode<T> *node) const
{
    if (node->parent == nullptr)
        return nullptr;
    else if (node == node->parent->rchild)
        return nullptr;
    else
        return node->parent->rchild;
}

template <typename T>
void BiTree<T>::InsertChild(BiNode<T> *p, int LR, BinaryTree<T, BiNode<T>> *c)
{
    BiTree<T> *child = dynamic_cast<BiTree<T> *>(c);
    if (child == nullptr)
        return;

    if (LR == 0)
    {
        if (p->lchild != nullptr)
            return;

        p->lchild = child->root;
        child->root->parent = p;
    }
    else if (LR == 1)
    {
        if (p->rchild != nullptr)
            return;

        p->rchild = child->root;
        child->root->parent = p;
    }
}

template <typename T>
void BiTree<T>::DeleteChild(BiNode<T> *p, int LR)
{
    if (LR == 0)
    {
        if (p->lchild == nullptr)
            return;

        DestroyBiTree(p->lchild);
        p->lchild = nullptr;
    }
    else if (LR == 1)
    {
        if (p->rchild == nullptr)
            return;

        DestroyBiTree(p->rchild);
        p->rchild = nullptr;
    }
}

template <typename T>
void BiTree<T>::CreateBiTree(BiNode<T> *&node)
{
    T value;
    std::cout << "Enter value (or # for null): ";
    std::cin >> value;

    if (value == '#')
    {
        node = nullptr;
    }
    else
    {
        node = new BiNode<T>;
        node->data = value;
        node->parent = nullptr;
        CreateBiTree(node->lchild);
        CreateBiTree(node->rchild);
        if (node->lchild != nullptr)
            node->lchild->parent = node;
        if (node->rchild != nullptr)
            node->rchild->parent = node;
    }
}

template <typename T>
void BiTree<T>::Copy(const BiNode<T> *src, BiNode<T> *&dest) const
{
    if (src == nullptr)
    {
        dest = nullptr;
    }
    else
    {
        dest = new BiNode<T>;
        dest->data = src->data;
        dest->parent = nullptr;
        Copy(src->lchild, dest->lchild);
        Copy(src->rchild, dest->rchild);
        if (dest->lchild != nullptr)
            dest->lchild->parent = dest;
        if (dest->rchild != nullptr)
            dest->rchild->parent = dest;
    }
}

template <typename T>
int BiTree<T>::CalculateDepth(const BiNode<T> *node) const
{
    if (node == nullptr)
        return 0;

    int leftDepth = CalculateDepth(node->lchild);
    int rightDepth = CalculateDepth(node->rchild);

    return 1 + std::max(leftDepth, rightDepth);
}

template <typename T>
int BiTree<T>::CalculateNodeCount(const BiNode<T> *node) const
{
    if (node == nullptr)
        return 0;

    int leftCount = CalculateNodeCount(node->lchild);
    int rightCount = CalculateNodeCount(node->rchild);

    return 1 + leftCount + rightCount;
}

template <typename T>
void BiTree<T>::InOrder(const BiNode<T> *node) const
{
    if (node == nullptr)
        return;

    InOrder(node->lchild);
    std::cout << node->data << " ";
    InOrder(node->rchild);
}

template <typename T>
void BiTree<T>::DestroyBiTree(BiNode<T> *&node)
{
    if (node == nullptr)
        return;

    DestroyBiTree(node->lchild);
    DestroyBiTree(node->rchild);

    delete node;
    node = nullptr;
}
