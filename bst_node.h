#pragma once
//COnde placed here is only included once per translation unit

#include <memory>

using std::unique_ptr;

template <typename T>
  struct BstNode {
    T data;
    unique_ptr<BstNode<T>> left, right;
    
    explicit BstNode(const T& data) : data(data) {}
    
    BstNode(T data, unique_ptr<BstNode<T>> left, unique_ptr<BstNode<T>> right)
      : data(data), left(std::move(left)), right(std::move(right)) {}
    
  };
DECLARE_BINARY_TREE(KeyT, std::unique_ptr<BstNode<KeyT>>, false)
