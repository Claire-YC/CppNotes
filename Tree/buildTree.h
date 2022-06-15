#ifndef CODENOTES_BUILDTREE_H
#define CODENOTES_BUILDTREE_H

#include "general.h"

template <typename T>
TreeNode<T>* AddNode(TreeNode<T>* root, T value,
                     std::queue<TreeNode<T>*>& que);

template <typename T>
TreeNode<T>* BuildTree(std::vector<T>& vec);

#endif //CODENOTES_BUILDTREE_H
