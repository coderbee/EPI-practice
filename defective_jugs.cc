#include <algorithm>
#include <memory>
#include <unordered_set>
#include <vector>

using std::make_unique;
using std::unordered_set;
using std::vector;

struct Jug;
struct VolumeRange;
struct HashVolumeRange;

bool CheckFeasibleHelper(const vector<Jug>&, int, int,
                         unordered_set<VolumeRange, HashVolumeRange>*);

struct Jug {
  int low, high;
};

struct VolumeRange {
  int low, high;

  bool operator==(const VolumeRange& that) const {
    return low == that.low && high == that.high;
  }
};

struct HasVolumeRange {
  size_t operator() (const VolumeRange& p) const {
    return static_cast<size_t>(31) * p.low + p.high;
  }
};

bool CheckFeasible(const vector<Jug>& jugs, int L, int H) {
  return CheckFeasibleHelper(
    jugs, L, H,
    make_unique<unordered_set<VolumeRange, HasVolumeRange>>().get());
}

bool CheckFeasibleHelper(const vector<Jug>& jugs, int L, int H,
                         unordered_set<VolumeRange, HasVolumeRange>* c) {
  if( L > H || c->count({L,H}) || (L < 0 && H < 0)) {
    return false;
  }
  
  //Checks the volume for each jug to see if it is possible.
  if(any_of(begin(jugs), end(jugs), [&](const Jug& j) {
    return (L <= j.low && j.high <= H) ||
      CHeckFeasibleHelper(jugs, L - j.low, H - j.high, c);
  })) {
    return true;
  }
  c->emplace(VolumeRange{L, H}); //Marks this as impossible.
  return false;
}

namespace test_framework {
  template <>
  struct SerializationTrait<Jug> : UserSerTrait<Jug, int, int> {};
} //namespace test_framework

bool operator==(const Jug& lhs, const Jug& rhs) {
  return lhs.low == rhs.low && lhs.high == rhs.high;
}

 
     
