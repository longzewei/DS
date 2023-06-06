#include <iostream>

template <typename T>
struct BiNode
{
    T data;
    BiNode<T> *lchild;
    BiNode<T> *rchild;
    BiNode<T> *parent;
};

template <typename T>
class BiTree
{
public:
    BiTree();
    void CreateTree();            // 创建二叉树
    void ClearBiTree();           // 清空二叉树
    BiTree<T> *CopyTree() const;  // 复制二叉树
    int BiTreeDepth() const;      // 计算二叉树的深度
    int NodeCount() const;        // 计算二叉树的节点数
    void InOrderTraverse() const; // 中序遍历二叉树
    bool BiTreeEmpty() const;     // 判断二叉树是否为空
    BiNode<T> *Root() const;      // 获取二叉树的根节点
    bool Root(T value);
    T Value(const BiNode<T> *node) const;                 // 获取节点的值
    void Assign(BiNode<T> *node, const T &value);         // 设置节点的值
    BiNode<T> *Parent(const BiNode<T> *node) const;       // 获取节点的父节点
    BiNode<T> *LeftChild(const BiNode<T> *node) const;    // 获取节点的左孩子
    BiNode<T> *RightChild(const BiNode<T> *node) const;   // 获取节点的右孩子
    BiNode<T> *LeftSibling(const BiNode<T> *node) const;  // 获取节点的左兄弟
    BiNode<T> *RightSibling(const BiNode<T> *node) const; // 获取节点的右兄弟
    void InsertChild(BiNode<T> *p, int LR, BiTree<T> *c); // 在指定节点的左子树或右子树插入一个二叉树,LR 插入的位置，0表示左子树，1表示右子树
    void DeleteChild(BiNode<T> *p, int LR);               // 删除指定节点的左子树或右子树,LR 删除的位置，0表示左子树，1表示右子树
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
BiTree<T>::BiTree() : root(nullptr) {}

template <typename T>
void BiTree<T>::CreateTree()
{
    CreateBiTree(root);
}

template <typename T>
BiTree<T> *BiTree<T>::CopyTree() const
{
    BiTree<T> *newTree = new BiTree<T>;
    Copy(root, newTree->root);
    return newTree;
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
    return root == nullptr;
}

template <typename T>
BiNode<T> *BiTree<T>::Root() const
{
    return root;
}

template <typename T>
bool BiTree<T>::Root(T value)
{
    if (this->root == nullptr)
    {
        this->root = new BiNode<T>;
        this->root->data = value;
        this->root->lchild = 0;
        this->root->rchild = 0;
        this->root->parent = 0;
        return true;
    }
    return false;
};

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
    if (node == nullptr || node == root)
    {
        return nullptr;
    }
    else
    {
        return node->parent;
    }
}

template <typename T>
BiNode<T> *BiTree<T>::LeftChild(const BiNode<T> *node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        return node->lchild;
    }
}

template <typename T>
BiNode<T> *BiTree<T>::RightChild(const BiNode<T> *node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        return node->rchild;
    }
}

template <typename T>
BiNode<T> *BiTree<T>::LeftSibling(const BiNode<T> *node) const
{
    if (node == nullptr || node == root)
    {
        return nullptr;
    }

    BiNode<T> *parent = node->parent;
    if (parent != nullptr && parent->lchild != node)
    {
        return parent->lchild;
    }

    return nullptr;
}

template <typename T>
BiNode<T> *BiTree<T>::RightSibling(const BiNode<T> *node) const
{
    if (node == nullptr || node == root)
    {
        return nullptr;
    }

    BiNode<T> *parent = node->parent;
    if (parent != nullptr && parent->rchild != node)
    {
        return parent->rchild;
    }

    return nullptr;
}

template <typename T>
void BiTree<T>::InsertChild(BiNode<T> *p, int LR, BiTree<T> *c)
{
    if (p == nullptr || c == nullptr || LR < 0 || LR > 1 || c->root == nullptr)
    {
        return;
    }

    if (LR == 0)
    {
        c->root->rchild = p->lchild;
        if (p->lchild != nullptr)
        {
            p->lchild->parent = c->root;
        }
        p->lchild = c->root;
        c->root->parent = p;
    }
    else
    {
        c->root->rchild = p->rchild;
        if (p->rchild != nullptr)
        {
            p->rchild->parent = c->root;
        }
        p->rchild = c->root;
        c->root->parent = p;
    }
}

template <typename T>
void BiTree<T>::DeleteChild(BiNode<T> *p, int LR)
{
    if (p == nullptr || LR < 0 || LR > 1)
    {
        return;
    }

    if (LR == 0)
    {
        DestroyBiTree(p->lchild);
        p->lchild = nullptr;
    }
    else
    {
        DestroyBiTree(p->rchild);
        p->rchild = nullptr;
    }
}

template <typename T>
void BiTree<T>::ClearBiTree()
{
    DestroyBiTree(root);
}

template <typename T>
void BiTree<T>::CreateBiTree(BiNode<T> *&node)
{
    char ch;
    std::cin >> ch;
    if (ch == '#')
    {
        node = nullptr;
    }
    else
    {
        node = new BiNode<T>;
        node->data = ch;
        node->parent = nullptr;
        CreateBiTree(node->lchild);
        if (node->lchild != nullptr)
        {
            node->lchild->parent = node;
        }
        CreateBiTree(node->rchild);
        if (node->rchild != nullptr)
        {
            node->rchild->parent = node;
        }
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
        if (dest->lchild != nullptr)
        {
            dest->lchild->parent = dest;
        }
        Copy(src->rchild, dest->rchild);
        if (dest->rchild != nullptr)
        {
            dest->rchild->parent = dest;
        }
    }
}

template <typename T>
int BiTree<T>::CalculateDepth(const BiNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftDepth = CalculateDepth(node->lchild);
        int rightDepth = CalculateDepth(node->rchild);
        return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
    }
}

template <typename T>
int BiTree<T>::CalculateNodeCount(const BiNode<T> *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return CalculateNodeCount(node->lchild) + CalculateNodeCount(node->rchild) + 1;
    }
}

template <typename T>
void BiTree<T>::InOrder(const BiNode<T> *node) const
{
    if (node)
    {
        InOrder(node->lchild);
        std::cout << node->data << " ";
        InOrder(node->rchild);
    }
}

template <typename T>
void BiTree<T>::DestroyBiTree(BiNode<T> *&node)
{
    if (node)
    {
        DestroyBiTree(node->lchild);
        DestroyBiTree(node->rchild);
        delete node;
        node = nullptr;
    }
}

/*
gcc -I./ \
-o test \
test.cc \
-lstdc++ -std=c++14
*/
/*

测试输入:AB##CD##E##

    A
   / \
  B   C
     / \
    D   E

中序遍历的结果为：BADCE
*/
int main()
{
    // 创建二叉树
    std::cout << "按先序顺序输入结点值来创建二叉树：\n";
    BiTree<char> tree;
    tree.CreateTree();

    // 测试公共函数
    std::cout << "二叉树是否为空：" << (tree.BiTreeEmpty() ? "是" : "否") << std::endl;
    std::cout << "二叉树的深度：" << tree.BiTreeDepth() << std::endl;
    std::cout << "二叉树的节点数：" << tree.NodeCount() << std::endl;

    std::cout << "中序遍历二叉树：";
    tree.InOrderTraverse();
    std::cout << std::endl;

    BiNode<char> *root = tree.Root();
    if (root != nullptr)
    {
        std::cout << "二叉树的根节点的值：" << tree.Value(root) << std::endl;

        BiNode<char> *leftChild = tree.LeftChild(root);
        std::cout << "根节点的左孩子的值：" << tree.Value(leftChild) << std::endl;

        BiNode<char> *rightChild = tree.RightChild(root);
        std::cout << "根节点的右孩子的值：" << tree.Value(rightChild) << std::endl;

        BiNode<char> *parent = tree.Parent(leftChild);
        std::cout << "左孩子节点的父节点的值：" << tree.Value(parent) << std::endl;

        BiNode<char> *leftSibling = tree.LeftSibling(rightChild);
        if (leftSibling)
        {
            std::cout << "右孩子节点的左兄弟的值：" << tree.Value(leftSibling) << std::endl;
        }
        else
        {
            std::cout << "右孩子节点没有左兄弟" << std::endl;
        }
    }
    else
    {
        std::cout << "这是一颗空树" << std::endl;
    }

    // 清空二叉树
    tree.ClearBiTree();
    std::cout << "清空二叉树后，二叉树是否为空：" << (tree.BiTreeEmpty() ? "是" : "否") << std::endl;

    return 0;
}
