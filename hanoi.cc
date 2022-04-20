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

vector<vector<int>> CumputeTOwerHanoi(int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  //Initialize pegs.
  for(int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }
  
