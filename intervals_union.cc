#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;

struct Interval {
  struct Endpoint {
  bool is_closed;
  int val;
  };
  
  Endpoint left, right;
};

vector<Interval> UnionOfIntervals (vector<Interval> intervals) {
  //Empty input.
  if(empty(intervals)) {
    return {};
  }
  
  
  
