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

//Process intervals in disjoint_intervals which come becore new_interval.
while (i < size(disjoint_intervals) &&
       new_interval.left > disjoint_intervals[i].right) {
  result.emplace_back(disjoint_intervals[i++]);
}

//Process intervals in disjoint_intervals which overlap with
// new_interval.
while (i < size(disjoint_intervals) && 
       new_interval.right >= disjoint_intervals[i].left) {
  // If [a, b] and [c, d] overlap, their union is [min(a, c), max(b, d)].
  new_interval = {min(new_interval.left, disjoint_intervals[i].left),
                  max(new_interval.right, disjoint_intervals[i].right)};
  ++i;
}
result.emplace_back(new_interval);
//Pricesses intervals in disjoint_intervals which come after new_interval.
result.insert(end(result), begin(disjoint_intervals) + i,
              end(disjoint_intervals));
return result;
}

  
