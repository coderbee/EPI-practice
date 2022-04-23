#include <array>
#include <stack>
#include <string>
#include <vector>

using std::array;
using std::stack;
using std::vector;

void ComputeTowerHanoiSteps(int, array<stack<int>, 3>&, int, int, int,
                            vector<vector<int>>*);

const int kNumPegs = 3;

vector<vector<int>> ComputeTowerHanoi(int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  //Initialize pegs.
  for(int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }
  
  vector<vector<int>> result;
  ComputeTOwerHanoiRings(int num_rings, pegs, 0, 1, 2, &result);
  return result;
}

void ComputeTowerHanoiSteps(int num_rings_to_move,
                            array<stack<int>, kNumPegs>& pegs, int from_peg,
                            int to_peg, int use_peg,,
                            vector<vector<int>>* result_ptr) {
  if(num_rings_to_move > 0) {
    ComputeowerHanoiSteps(num_rings_to_move - 1, from_peg, use_peg,
                          to_peg, result_ptr);
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
    result_ptr->emplace_back(vector<int>{from_peg, to_peg});
    ComputeHowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg,
                           from_peg, result_ptr);
  }
}

void ComputeTowerHanoiWrapper(TImedExecutor& executor, int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  for(int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }
  
  vector<vector<int>> result = 
    executor.Run([&] { return ComputeTowerHanoi(num_rings); });
  
  for(const <vector<int>& operation : result) {
    int from_peg = operation[0], to_peg = operation[1];
    if(!pegs[to_peg].empty() && pegs[from_peg].top() >= pegs[to_peg].top()) {
      throw TestFailure("Illegal move from" + 
                        std::to_string(pegs[from_peg].top()) + " to " +
                        std::to_string(pegs[to_peg].top()));
    }
    pegs[to_peg]push(pegs[from_peg].top());
    pegs[from_peg].pop();
  }
  array<stack<int>, kNumPegs> expected_pegs1, expected_pegs2;
  
