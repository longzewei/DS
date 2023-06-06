#include <iostream>
#include "LinkedBinaryTree.h"

/*
gcc -I./ \
-o test_LinkedBinaryTree \
test_LinkedBinaryTree.cc \
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
    BinaryTree<char, BiNode<char>> *binaryTree = new BiTree<char>();

    binaryTree->CreateTree();

    // 测试公共函数
    std::cout << "二叉树是否为空：" << (binaryTree->BiTreeEmpty() ? "是" : "否") << std::endl;
    std::cout << "二叉树的深度：" << binaryTree->BiTreeDepth() << std::endl;
    std::cout << "二叉树的节点数：" << binaryTree->NodeCount() << std::endl;

    std::cout << "中序遍历二叉树：";
    binaryTree->InOrderTraverse();
    std::cout << std::endl;

    BiNode<char> *root = binaryTree->Root();
    if (root != nullptr)
    {
        std::cout << "二叉树的根节点的值：" << binaryTree->Value(root) << std::endl;

        BiNode<char> *leftChild = binaryTree->LeftChild(root);
        std::cout << "根节点的左孩子的值：" << binaryTree->Value(leftChild) << std::endl;

        BiNode<char> *rightChild = binaryTree->RightChild(root);
        std::cout << "根节点的右孩子的值：" << binaryTree->Value(rightChild) << std::endl;

        BiNode<char> *parent = binaryTree->Parent(leftChild);
        std::cout << "左孩子节点的父节点的值：" << binaryTree->Value(parent) << std::endl;

        BiNode<char> *leftSibling = binaryTree->LeftSibling(rightChild);
        if (leftSibling)
        {
            std::cout << "右孩子节点的左兄弟的值：" << binaryTree->Value(leftSibling) << std::endl;
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
    binaryTree->ClearBiTree();
    std::cout << "清空二叉树后，二叉树是否为空：" << (binaryTree->BiTreeEmpty() ? "是" : "否") << std::endl;

    delete binaryTree;

    return 0;
}
