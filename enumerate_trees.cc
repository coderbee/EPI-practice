#include <algorithm>
#include <memory>
#include <stack>
#include <vector>

using std::make_unique;
using std::vector;

unique_ptr<BinaryTreeNode<int>> CLone(const unique_ptr<BinaryTreeNode<int>>&);

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBonaryTrees(int num_nodes) {
  vector<unique_ptr<BinaryTreeNode<int>>> result;
  if(num_nodes == 0 ) { //Empty tree, add as a nullptr.
    result.emplace_back(nullptr);
  }
  
  
