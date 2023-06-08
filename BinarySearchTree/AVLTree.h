#pragma once

#include "BinarySearchTree.h"

template <class Key, class Value>
struct AVLTreeNode
{
    Key key;
    Value value;
    int height;
    AVLTreeNode *left;
    AVLTreeNode *right;

    AVLTreeNode(const Key &k, const Value &v)
        : key(k), value(v), height(1), left(nullptr), right(nullptr)
    {
    }
};

template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
private:
    AVLTreeNode<Key, Value> *root;

public:
    AVLTree();
    ~AVLTree();

    bool Search(const Key &key, Value &value) const override;
    bool Insert(const Key &key, Value value) override;
    bool Remove(const Key &key) override;
    Key Min() const override;
    Key Max() const override;
    void MakeEmpty() override;

private:
    int GetHeight(AVLTreeNode<Key, Value> *node) const;
    int GetBalanceFactor(AVLTreeNode<Key, Value> *node) const;
    AVLTreeNode<Key, Value> *RotateLeft(AVLTreeNode<Key, Value> *node);
    AVLTreeNode<Key, Value> *RotateRight(AVLTreeNode<Key, Value> *node);
    AVLTreeNode<Key, Value> *Insert(AVLTreeNode<Key, Value> *node, const Key &key, const Value &value);
    AVLTreeNode<Key, Value> *Remove(AVLTreeNode<Key, Value> *node, const Key &key);
    AVLTreeNode<Key, Value> *Min(AVLTreeNode<Key, Value> *node) const;
    AVLTreeNode<Key, Value> *Max(AVLTreeNode<Key, Value> *node) const;
    void MakeEmpty(AVLTreeNode<Key, Value> *node);
    AVLTreeNode<Key, Value> *Balance(AVLTreeNode<Key, Value> *node);
    AVLTreeNode<Key, Value> *FindSuccessor(AVLTreeNode<Key, Value> *node);
};

template <class Key, class Value>
AVLTree<Key, Value>::AVLTree()
    : root(nullptr)
{
}

template <class Key, class Value>
AVLTree<Key, Value>::~AVLTree()
{
    MakeEmpty();
}

template <class Key, class Value>
bool AVLTree<Key, Value>::Search(const Key &key, Value &value) const
{
    AVLTreeNode<Key, Value> *current = root;
    while (current != nullptr)
    {
        if (key == current->key)
        {
            value = current->value;
            return true; // Key found
        }
        else if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return false; // Key not found
}

template <class Key, class Value>
bool AVLTree<Key, Value>::Insert(const Key &key, Value value)
{
    if (Search(key, value))
        return false; // Duplicate keys not allowed

    root = Insert(root, key, value);
    return true;
}

template <class Key, class Value>
bool AVLTree<Key, Value>::Remove(const Key &key)
{
    Value tempValue;
    if (!Search(key, tempValue))
        return false; // Key not found

    root = Remove(root, key);
    return true;
}

template <class Key, class Value>
Key AVLTree<Key, Value>::Min() const
{
    if (root == nullptr)
        throw std::runtime_error("Tree is empty");
    AVLTreeNode<Key, Value> *minNode = Min(root);
    return minNode->key;
}

template <class Key, class Value>
Key AVLTree<Key, Value>::Max() const
{
    if (root == nullptr)
        throw std::runtime_error("Tree is empty");
    AVLTreeNode<Key, Value> *maxNode = Max(root);
    return maxNode->key;
}

template <class Key, class Value>
void AVLTree<Key, Value>::MakeEmpty()
{
    MakeEmpty(root);
    root = nullptr;
}

template <class Key, class Value>
int AVLTree<Key, Value>::GetHeight(AVLTreeNode<Key, Value> *node) const
{
    if (node == nullptr)
        return 0;
    return node->height;
}

template <class Key, class Value>
int AVLTree<Key, Value>::GetBalanceFactor(AVLTreeNode<Key, Value> *node) const
{
    if (node == nullptr)
        return 0;
    return GetHeight(node->left) - GetHeight(node->right);
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::RotateLeft(AVLTreeNode<Key, Value> *node)
{
    AVLTreeNode<Key, Value> *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
    newRoot->height = 1 + std::max(GetHeight(newRoot->left), GetHeight(newRoot->right));
    return newRoot;
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::RotateRight(AVLTreeNode<Key, Value> *node)
{
    AVLTreeNode<Key, Value> *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
    newRoot->height = 1 + std::max(GetHeight(newRoot->left), GetHeight(newRoot->right));
    return newRoot;
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::Insert(AVLTreeNode<Key, Value> *node, const Key &key, const Value &value)
{
    if (node == nullptr)
        return new AVLTreeNode<Key, Value>(key, value);

    if (key < node->key)
        node->left = Insert(node->left, key, value);
    else
        node->right = Insert(node->right, key, value);

    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

    return Balance(node);
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::Remove(AVLTreeNode<Key, Value> *node, const Key &key)
{
    if (node == nullptr)
        return nullptr;

    if (key < node->key)
        node->left = Remove(node->left, key);
    else if (key > node->key)
        node->right = Remove(node->right, key);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            AVLTreeNode<Key, Value> *temp = node->left ? node->left : node->right;
            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
                *node = *temp;
            delete temp;
        }
        else
        {
            AVLTreeNode<Key, Value> *successor = FindSuccessor(node->right);
            node->key = successor->key;
            node->value = successor->value;
            node->right = Remove(node->right, successor->key);
        }
    }

    if (node == nullptr)
        return nullptr;

    node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

    return Balance(node);
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::Min(AVLTreeNode<Key, Value> *node) const
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::Max(AVLTreeNode<Key, Value> *node) const
{
    while (node->right != nullptr)
        node = node->right;
    return node;
}

template <class Key, class Value>
void AVLTree<Key, Value>::MakeEmpty(AVLTreeNode<Key, Value> *node)
{
    if (node != nullptr)
    {
        MakeEmpty(node->left);
        MakeEmpty(node->right);
        delete node;
    }
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::Balance(AVLTreeNode<Key, Value> *node)
{
    int balanceFactor = GetBalanceFactor(node);

    if (balanceFactor > 1) // Left subtree is taller
    {
        if (GetBalanceFactor(node->left) < 0) // Left-Right case
            node->left = RotateLeft(node->left);
        return RotateRight(node); // Left-Left case
    }
    else if (balanceFactor < -1) // Right subtree is taller
    {
        if (GetBalanceFactor(node->right) > 0) // Right-Left case
            node->right = RotateRight(node->right);
        return RotateLeft(node); // Right-Right case
    }

    return node;
}

template <class Key, class Value>
AVLTreeNode<Key, Value> *AVLTree<Key, Value>::FindSuccessor(AVLTreeNode<Key, Value> *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}
