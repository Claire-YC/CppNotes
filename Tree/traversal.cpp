#include <vector>
#include <queue>
#include <stack>
#include "general.h"

/**************** PreOrder ****************/
template <typename T>
void R_Preorder(TreeNode<T>* root, std::vector<T>& vec)
{
    if (!root)
        return ;

    vec.push_back(root->val);
    Preorder(root->left, vec);
    Preorder(root->right, vec);
}

std::vector<int> I_Preorder(TreeNode<int>* root)
{
    std::stack<TreeNode<int>*> st;
    std::vector<int> result;

    if (root == nullptr)
        return result;

    st.push(root);
    while (!st.empty())
    {
        // 1. parent node
        auto node = st.top();
        st.pop(); // .pop()是没有return value的
        result.push_back(node->val);

        // 2. why right child first?
        // stack: last in first out [parent,left,right]
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return  result;
}

/**************** InOrder ****************/
template <typename T>
void R_Inorder(TreeNode<T>* root, std::vector<T>& vec)
{
    if (root == nullptr)
        return ;

    Inorder(root->left, vec);
    vec.push_back(root->val);
    Inorder(root->right, vec);
}

std::vector<int> I_Inorder(TreeNode<int>* root)
{
    std::vector<int> result;
    std::stack<TreeNode<int>*> stack;

    auto node = root;
    while (node != nullptr || !stack.empty())
    {
        // 若还没有访问到当前节点的最左侧，将途径node全部压栈
        if (node != nullptr)
        {
            stack.push(node);
            node = node->left;
        } // if
        else
        {
            // 走到当前节点的最左侧，开始处理
            node = stack.top();
            stack.pop();
            result.push_back(node->val);
            node = node->right;
        } // else
    } // while
    return result;
} // InorderTraversal

/**************** PostOrder ****************/
template <typename T>
void R_Postorder(TreeNode<T>* root, std::vector<T>& vec)
{
    if (root == nullptr)
        return ;
    Postorder(root->left, vec);
    Postorder(root->right, vec);
    vec.push_back(root->val);
}

// 后序遍历 = 中右左 -> 【翻转】左右中 （通过前序遍历来写）
std::vector<int> I_Postorder(TreeNode<int>* root)
{
    std::vector<int> result;
    std::stack<TreeNode<int>*> stack;

    if (root == nullptr)
        return result;

    stack.push(root);
    while (!stack.empty())
    {
        auto node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if (node->left)
            stack.push(node->left);
        if (node->right)
            stack.push(node->right);
    } //while
    std::reverse(result.begin(), result.end());
    return result;
} //PostOrderTraveral

/**************** Level Order ****************/
template <typename T>
void LevelOrder(TreeNode<T>* root, std::vector<T>& vec)
{
    if (root == nullptr)
        return ;
    std::queue<TreeNode<T>*> que;
    que.push(root);

    while (!que.empty())
    {
        TreeNode<T>* node = que.front();
        que.pop();
        vec.push_back(node->val);

        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
    }
}