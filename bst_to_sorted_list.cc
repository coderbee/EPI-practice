#include <memory>
#include <vector>
#include "bst_prototype_shared_ptr.h"

using std::shared_ptr;

struct HeadAndTail;
HeadAndTail BSTToDoublyLinkedListHelper(const shared_ptr<BstNode<int>>&);

struct HeadAndTail { 
  shared_ptr<BstNode<int>> head, tail;
}

shared_ptr<BstNode<int>> BSTToDoublyLinkedList(
  const shared_ptr<BstNode<int>>& tree) {
return BSTToDoublyLinkedListHelper(tree).head;
}

//Transforms a BST into a sorted doubly linked list in-place,
//and return the head and tail of the list.
HeadAndTail BSTToDoublyLinkedListHelper(const shared_ptr<BstNode<int>>& tree) {
  //Empty subtree.
  if(!tree) {
    return {nullptr, nullptr};
  }
  
  //Recursively builds the list from left and right subtrees.
  HeadAndTail left = BSTToDoublyLinkedListHelper(tree ->left);
  HeadAndTail right = BSTToDoublyLinkedListHelper(tree->right);
  
  //APpends tree to the list from left subtree
  if(left.tail) {
    left.tail->right = tree;
  }
  tree->left = left.tail;
  
  //APpends the list from right subtree to tree.
  tree->right = right.head;
  if(right.head) {
    right.head->left = tree;
  }
  
  return {left.head ? left.head : tree, right.tail ? right.tail : tree);
}

  
std::vector<int> BSTToDoublyLinkedListWrapper(
  TimedExecutor& executor, const std::shared_ptr<BstNode<int>>& tree) {
 auto list = executor.Run([&] { return BSTToDoublyLinkedList(tree); } );
  
  if(list && list->left) {
    throw testFailure(
      "Function must return the head of the list. Left link must be null");
  }
  std::vector<int> v;
  while (list) {
    v.push_back(list->data);
