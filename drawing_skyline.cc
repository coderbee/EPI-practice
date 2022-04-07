#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

struct Rect {
  int left, right, height;
};
using Skyline = vector<Rect>;

Skyline ComputeSkyline(const vector<Rect>& buildings) {
  int min_left = numeric_limits<int>::max(),
  
