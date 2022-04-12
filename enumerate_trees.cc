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
  
  for(int num_left_tree_nodes = 0; num_left_tree_nodes < num_nodes;
      ++num_left_tree_nodes) {
    int num_right_tree_nodes = num_nodes -  1 - num_left_tree_nodes;
    auto left_subtrees = GenerateAllBinaryTRees(num_left_tree_nodes);
    auto right_subtrees = GenerateAllBinaryTrees(num_right_tree_nodes);
    //Generates all combinations of left_subtrees and right_subtrees.
    for (auto& left: left_subtrees) {
      for(auto& right : right_subtrees) {
        result.emplace_back(
          make_unique<BinaryTreeNode<int>>(0 Clone(left), Clone(right)));
      }
    }
  }
  return result;
}

unique_ptr<BinaryTreeNode<int>> Clone(
  const unique_ptr<BinaryTreeNode<int>>& tree) {
 return tree ? make_unique<BinaryTreeNode<int>>(0, Clone(tree->left),
                                                  Clone(tree->right))
              : nullptr;
}

vector<int> SerializeStructure(const unique_ptr<BinaryTreeNode<int>>& tree) {
  vector<int> result;
  
  std::stack<BinaryTreeNode<int>*> stack;
  stack.push(tree.get());
  while (!stack.empty()) {
    auto p = stack.top();
    stack.pop();
    result.push_back(p != nullptr);
    if(p) {
      stack.push(p->left.get());
      stack.push(p->right.get());
    }
  }
  return result;
}

vector<vector<int>> GenerateAllBinaryTreesWrapper(TimedExecutor& executor,
                                                  int num_nodes) {
  auto result = executor.Run([&] { return GenerateAllBinaryTrees(num_nodes); });
  
  vector<vector<int>> serialized;
  for (auto& x : result) {
    serialized.push_back(SerializedStructure(x));
  }
  std::sort(begin(serialized), end(serialized));
  return serialized;
}

  
  
  
  
