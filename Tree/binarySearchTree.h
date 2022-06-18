#ifndef CODENOTES_BINARYSEARCHTREE_H
#define CODENOTES_BINARYSEARCHTREE_H

#include "general.h"

/****************** Search ******************/
template <typename T>
TreeNode<T>* SearchBST_recursive(TreeNode<T>* root, T val);

template <typename T>
TreeNode<T>* SearchBST_iterative(TreeNode<T>* root, T val);

/****************** Insert ******************/
template <typename T>
TreeNode<T>* Insert_iterative(TreeNode<T>* root, T val);

template <typename T>
TreeNode<T>* Insert_recursive(TreeNode<T>* root, T val);

/****************** Delete ******************/
template <typename T>
TreeNode<T>* Delete_recursive(TreeNode<T>* root, T key);

#endif //CODENOTES_BINARYSEARCHTREE_H
