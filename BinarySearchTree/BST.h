#include <stdexcept>

#include "BinarySearchTree.h"

template <class Key, class Value>
class TreeNode
{
public:
    Key key;
    Value value;
    TreeNode<Key, Value> *left;
    TreeNode<Key, Value> *right;

    TreeNode(const Key &k, const Value &v)
        : key(k), value(v), left(nullptr), right(nullptr)
    {
    }
};

template <class Key, class Value>
class BST : public BinarySearchTree<Key, Value>
{
private:
    TreeNode<Key, Value> *root;

public:
    BST();
    ~BST();

    bool Search(const Key &key, Value &value) const override;
    bool Insert(const Key &key, Value value) override;
    bool Remove(const Key &key) override;
    Key Min() const override;
    Key Max() const override;
    void MakeEmpty() override;

private:
    bool Search(const Key &key, Value &value, TreeNode<Key, Value> *node) const;
    bool Insert(const Key &key, Value value, TreeNode<Key, Value> *&node);
    bool Remove(const Key &key, TreeNode<Key, Value> *&node);
    TreeNode<Key, Value> *Min(TreeNode<Key, Value> *node) const;
    TreeNode<Key, Value> *Max(TreeNode<Key, Value> *node) const;
    void MakeEmpty(TreeNode<Key, Value> *&node);
};

template <class Key, class Value>
BST<Key, Value>::BST() : root(nullptr)
{
}

template <class Key, class Value>
BST<Key, Value>::~BST()
{
    MakeEmpty();
}

template <class Key, class Value>
bool BST<Key, Value>::Search(const Key &key, Value &value) const
{
    return Search(key, value, root);
}

template <class Key, class Value>
bool BST<Key, Value>::Insert(const Key &key, Value value)
{
    return Insert(key, value, root);
}

template <class Key, class Value>
bool BST<Key, Value>::Remove(const Key &key)
{
    return Remove(key, root);
}

template <class Key, class Value>
Key BST<Key, Value>::Min() const
{
    if (root == nullptr)
        throw std::runtime_error("Tree is empty");
    return Min(root)->key;
}

template <class Key, class Value>
Key BST<Key, Value>::Max() const
{
    if (root == nullptr)
        throw std::runtime_error("Tree is empty");
    return Max(root)->key;
}

template <class Key, class Value>
void BST<Key, Value>::MakeEmpty()
{
    MakeEmpty(root);
    root = nullptr;
}

template <class Key, class Value>
bool BST<Key, Value>::Search(const Key &key, Value &value, TreeNode<Key, Value> *node) const
{
    if (node == nullptr)
        return false;

    if (key == node->key)
    {
        value = node->value;
        return true;
    }
    else if (key < node->key)
        return Search(key, value, node->left);
    else
        return Search(key, value, node->right);
}

template <class Key, class Value>
bool BST<Key, Value>::Insert(const Key &key, Value value, TreeNode<Key, Value> *&node)
{
    if (node == nullptr)
    {
        node = new TreeNode<Key, Value>(key, value);
        return true;
    }

    if (key == node->key)
        return false; // Key already exists
    else if (key < node->key)
        return Insert(key, value, node->left);
    else
        return Insert(key, value, node->right);
}

template <class Key, class Value>
bool BST<Key, Value>::Remove(const Key &key, TreeNode<Key, Value> *&node)
{
    if (node == nullptr)
        return false; // Key not found

    if (key < node->key)
        return Remove(key, node->left);
    else if (key > node->key)
        return Remove(key, node->right);
    else
    {
        if (node->left == nullptr)
        {
            TreeNode<Key, Value> *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            TreeNode<Key, Value> *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            TreeNode<Key, Value> *successor = Min(node->right);
            node->key = successor->key;
            node->value = successor->value;
            Remove(successor->key, node->right);
        }
        return true;
    }
}

template <class Key, class Value>
TreeNode<Key, Value> *BST<Key, Value>::Min(TreeNode<Key, Value> *node) const
{
    if (node->left == nullptr)
        return node;
    return Min(node->left);
}

template <class Key, class Value>
TreeNode<Key, Value> *BST<Key, Value>::Max(TreeNode<Key, Value> *node) const
{
    if (node->right == nullptr)
        return node;
    return Max(node->right);
}

template <class Key, class Value>
void BST<Key, Value>::MakeEmpty(TreeNode<Key, Value> *&node)
{
    if (node == nullptr)
        return;

    MakeEmpty(node->left);
    MakeEmpty(node->right);
    delete node;
    node = nullptr;
}
