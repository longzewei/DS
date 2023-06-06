#include <iostream>

template <typename T>
struct BiNode
{ // 二叉树结点定义
    T data;
    struct BiNode<T> *lchild, *rchild;
};

template <typename T>
using BiTree = BiNode<T> *;

// 使用先序遍历顺序创建二叉树（算法5.3）
template <typename T>
void CreateBiTree(BiTree<T> &tree)
{
    // 按先序顺序输入结点值（字符），创建由二叉链表表示的二叉树tree
    T value;
    std::cout << "请输入结点的值（输入'#'表示空结点）：";
    std::cin >> value;
    if (value == '#')
        tree = nullptr; // 递归结束，创建空树
    else
    {
        tree = new BiNode<T>;
        tree->data = value;         // 生成根结点
        CreateBiTree(tree->lchild); // 递归创建左子树
        CreateBiTree(tree->rchild); // 递归创建右子树
    }
}

template <typename DataType>
void Copy(BiTree<DataType> src, BiTree<DataType> &dest)
{
    if (src == NULL)
    {
        dest = NULL;
        return;
    }
    else
    {
        dest = new BiNode<DataType>;
        dest->data = src->data;
        Copy(src->lchild, dest->lchild);
        Copy(src->rchild, dest->rchild);
    }
}

// 中序遍历二叉树tree的递归算法
template <typename T>
void InOrderTraverse(BiTree<T> tree)
{
    if (tree)
    {
        InOrderTraverse(tree->lchild); // 中序遍历左子树
        std::cout << tree->data;       // 输出结点值
        InOrderTraverse(tree->rchild); // 中序遍历右子树
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
    BiTree<char> tree;
    std::cout << "按先序顺序输入结点值来创建二叉树：\n";
    CreateBiTree(tree);
    std::cout << "中序遍历的结果为：\n";
    InOrderTraverse(tree);
    std::cout << std::endl;
    
    return 0;
}
