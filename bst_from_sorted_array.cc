#include <memory>
#include <vector>

#include"bst_node.h"

usung std::make_unique;
using std::unique_ptr;
using std::vector;

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedSubarray(const vector<int>&,
                                                             int, int);

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedArray(
  const vector<int>& A) {
  return BuildMinHeightBSTFromSortedSubarray(A, 0, size(A));
}

//Build a min-height BST over the entries in A[start, end - 1].


