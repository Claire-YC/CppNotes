#ifndef CODENOTES_GENERAL_H
#define CODENOTES_GENERAL_H

// 简单的struct/class写在header文件里了
// 复杂一点的再后序查资料
template <typename T>
struct TreeNode
{
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
            : val(0), left(nullptr), right(nullptr) {}

    TreeNode(T value)
            : val(value), left(nullptr), right(nullptr) {}

    TreeNode(T value, TreeNode* left, TreeNode* right)
            : val(value), left(left), right(right) {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
}; // struct

#endif //CODENOTES_GENERAL_H
