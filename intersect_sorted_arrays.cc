#include <algorithm>
#include <vector>

using std::vector;
vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  vector<int> intersection_A_B;
  for (int i = 0; i < size(A); ++i) {
    if((!i || A[i] != A[i -1]) && find(begin(B), end(B), A[i]) != end(B)) {
      intersection_A_B.emplace_back(A[i]);
    }
  }
  return intersection_A_B;
}

