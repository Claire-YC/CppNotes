#include <iostream>
#include <queue>
#include <vector>

#include "buildTree.h"
#include "general.h"

template <typename T>
TreeNode<T>* AddNode(TreeNode<T>* root, T value, std::queue<TreeNode<T>*>& que)
{
    TreeNode<T>* newNode = new TreeNode<T>(value);
    if (root == nullptr)
        root = newNode;
    else if (!(que.front()->left))
        que.front()->left = newNode;
    else
    {
        que.front()->right = newNode;
        que.pop();
    }
    que.push(newNode);
    return root;
} // AddNode
// 把具体的模版给出来，要不然会有错！
template TreeNode<int>* AddNode<int>(TreeNode<int>*, int value, std::queue<TreeNode<int>*>&);

template <typename T>
TreeNode<T>* BuildTree(std::vector<T>& vec)
{
    TreeNode<T>* root = nullptr;
    std::queue<TreeNode<T>*> que;
//    que.push(root);

    for (size_t i=0; i<vec.size(); i++)
        root = AddNode(root, vec[i], que);
    return root;
}    // BuildTree

template TreeNode<int>* BuildTree(std::vector<int>& vec);