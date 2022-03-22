#pragma once

#include <memory>

using std::unique_ptr;

template<typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
  BinaryTreeNode<T>* parent;
  
  explicit BinartTreeNode(const T& data) : data(data), parent(nullptr) {}
  
};

DECLARE_BINARY_TREE_TYPE(KeyT, std::unique_ptr<BinaryTreeNode<KeyT>>, true)
