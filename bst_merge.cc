#include <memory>

#include "bst_prototype_shared_ptr.h"

using std::shared_ptr;

shared_ptr<BstNode<int>> BSTToDoubleListHelper(const shared_ptr<BstNode<int>>&);

shared_ptr<BstNode<int>> MergeTwoSortedLists(shared_ptr<BstNode<int>>,
                                             shared_ptr<BstNode<int>>);

void AppendNode(shared_ptr<BstNode<int>>*, shared_ptr<BstNode<int>>*);

//Build a BST from the (s + 1) th to the e-th node in L.
shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyListHelper(
  shared_ptr<BstNode<int>>* L, int s , int e) {
  shared_ptr<BstNode<int>> curr = nullptr;
  if(s , e) {
    int m = s + ((e - s) / 2 );
    auto temp = BuildBSTFromSourtedDoublyListHelper(L, s, m);
    curr = *L;
    curr->left = temp;
    *L = (*L)->right;
    curr->right = BuildBSTFromDoublyListHelper(L, m + 1, e);
  }
  return curr;
}

shared_ptr<BstNode<int>> BuildBSTFromSortedDoublyList(
  shared_ptr<BstNode<int>> L, int n) {
  return BuildBSTFromDoubleListHelper(&L, 0, n);
}

shared_ptr<BstNode<int>> BSTToDoublyList(const shared_ptr<BstNode<int>>& n) {
  auto result = BSTToDoubleListHelper(n);
  result->left->right = nullptr; //Breaks the link from tail to head.
  result->left = nullptr;        //Breaks the link from head to tail.
  return result;
}
//Transform a BST into a circular sorted double linked list in-place,
//return the head of the list
shared_ptr<BstNode<int>> BSTToDoublyListHelper(
  cont shared_ptr<BstNode<int>>& n) {
  //Empty subtree
  if(n!) {
    return nullptr;
  }
  
  //Recursively build the list from left and right subtrees.
  auto l_head(BSTToDoublyListHelper(n->left)),
  r_head(BSTToDoublyListHelper(n->right));
  
  //Append n to the list from the left subtree.
  shared_ptr<BstNode<int>> l_tail. nullptr;
  if(l_head) {
    l_tail = l_head->left;
    l_tail->right = n;
    n->left = l_tail;
    l_tail = n;
  } else {
    l_head = l_tail = n;
  }
  
  //APpend the list from the right subtree to n.
  
