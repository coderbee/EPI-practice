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
    result_ptr->
  
