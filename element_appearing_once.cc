#include <array>
#include <vector>

using std::array;
using std::vector;

int FindElementAppearsOnce(const vector<int> &A) {
  array<int, 32> counts = {};
  for(int x : A) {
    for(int i = 0; i < 32; i++) {
      counts[i] += x & 1;
      x >>= 1;
    }
  }
  
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    result |= (counts[i] % 3) << i;
  }
  return result;
}

