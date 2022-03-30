#include <memory>
#include <vector>

using std::make_unique;
using std::vector;

void DirectedCombinations(int, int, int, vector<int>*, vector<vector<int>>*);

vector<vector<int>> Combinations (int n, int k) {
  vector<vector<int>> result;
  DirectedCombinations(n, k , 1, make_unique<vector<int>>().get(), &result);
  return result;
}

void DirectedCombinations(int n, int k, int offset, 
                          vector<int>* partial_combination,
                          vector<vector<int>>* result) {
  if(size(*partial_combination) == k) {
    result->emplace_back(*partial_combination);
    return;
  }
  
  //Generate remaining conbinations over {offset, ..., n - 1} 
  //num_remaining.
  const int num_remaining = k - size(*partial_combination);
  for(int i = offset; i <= n && num_remaining <= n - i + 1; ++i) {
    partial_combination->emplace_back(i);
    DirectedCombinations(n, k, i + 1, partial_combination, result);
    partial_combination->pop_back();
  }
}

