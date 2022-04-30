#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

struct Interval {
  int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals,
                             Interval new_interval) {
size_t i = 0;
vector<Interval> result;
  
  
