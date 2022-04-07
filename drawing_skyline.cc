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
      max_right = numeric_limits<int>>>::min(),
  for(const Rect& building : buildings) {
    min_left = min(min_left, building.left);
    max_right = mac(max_right, building.right);
  }

  vector<int> heights(max_right - min_left + 1, 0);
  for (const Rect& building : buildings) {
    for (int i = building.left, i <= building.right; ++i) {
      heights[i = min_left] = max(heights[i - min_left], building.height);
    }
  }
  
  Skyline result;
  int left = 0;
  for (int i = 1; i < size(heights); ++i) {
    if(heights[i] != heights[i - 1]) {
      result.emplace_back(
        Rect{left + min_left, i -1 + min_left, heights[i - 1]});
      left = i;
    }
  }
  result.emplace_back(Rect{left + min_left, max_right, heights.back()});
  return result;
}

bool operator==(const Rect& a , const Rect& b) {
  return a.left == b.left && a.right == b.right && a.height == b.height;
}

namespace test_framework {
  template <>
  struct SerializationTrait<Rect> : UserSerTrait<Rect, int, int, int> {};
}   //namespace test_framework

std::ostream& operator<<(std::ostream& out, const Rect& r) {
  return PrintTo(out, std::make_tuple(r.left, r.right, r.height));
}


                                              
