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
  HeadAndTail left = BST
