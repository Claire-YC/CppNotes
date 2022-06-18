#include "general.h"

/****************** Search ******************/
template <typename T>
TreeNode<T>* SearchBST_recursive(TreeNode<T>* root, T val)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == val)
        return root;
    else if (root->val < val)
        return SearchBST_recursive(root->right, val);
    else
        return SearchBST_recursive(root->left, val);
}
template TreeNode<int>* SearchBST_recursive(TreeNode<int>* root, int val);

template <typename T>
TreeNode<T>* SearchBST_iterative(TreeNode<T>* root, T val)
{
    auto node = root;
    while (node != nullptr)
    {
        if (node->val == val)
            return node;
        else if (node->val < val)
            node = node->right;
        else
            node = node->left;
    }
    return nullptr;
}
template TreeNode<int>* SearchBST_iterative(TreeNode<int>* root, int val);

/****************** Insertion ******************/
template <typename T>
TreeNode<T>* Insert_iterative(TreeNode<T>* root, T val)
{
    TreeNode<T>* newNode = new TreeNode<T>(val);
    if (root == nullptr)
        return newNode;

    TreeNode<T>* node = root;
    // 需要把插入节点分parent node记录下来，要不然找不到插入的位置
    TreeNode<T>* pre = nullptr;
    while (node)
    {
        pre = node;
        if (node->val < val)
            node = node->right;
        else
            node = node->left;
    }
    if (pre->val < val)
        pre->right = newNode;
    else
        pre->left = newNode;
    return root;
}
template TreeNode<int>* Insert_iterative(TreeNode<int>* root, int val);

template <typename T>
TreeNode<T>* Insert_recursive(TreeNode<T>* root, T val)
{

    if (root == nullptr){
        TreeNode<T>* newNode = new TreeNode<T>(val);
        return newNode;
    }

    if (root->val < val)
        root->right = Insert_recursive(root->right, val);
    else
        root->left = Insert_recursive(root->left, val);
    return root;
}
template TreeNode<int>* Insert_recursive(TreeNode<int>* root, int val);

/****************** Delete ******************/
template <typename T>
TreeNode<T>* Delete_recursive(TreeNode<T>* root, T key)
{
    // 表示没有找到
    if (root == nullptr)
        return nullptr;

    // 找到了，但是要删除要分很多种情况
    if (root->val == key)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if ((root->left) && (!root->right))
        {
            auto tmp = root->left;
            root->left = nullptr;
            delete root;
            return tmp;
        }
        else if ((!root->left) && (root->right))
        {
            auto tmp = root->right;
            root->right = nullptr;
            delete root;
            return tmp;
        }
        else
        {
            auto newNode = root->right;
            while (newNode->left)
                newNode = newNode->left;

            // 第一种写法
            newNode->left = root->left;
            auto tmp = root->right;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            return tmp;

            /*第二种写法
            root->left->val = newNode->val;
            delete newNode;
            return root;
             */
        }
    } // if
    else if (root->val > key)
        root->left = Delete_recursive(root->left, key);
    else
        root->right = Delete_recursive(root->right, key);
    return root;
}
template TreeNode<int>* Delete_recursive(TreeNode<int>* root, int key);