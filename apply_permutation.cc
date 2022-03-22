#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

void ApplyPermutation(vector<int> perm, vector<int>* A_Ptr) {
  vector<int>& A = *A_ptr;
  for(int i = 0; i < size(A); ++i) {
    while (perm[i] != i ) {
      swap(A[i], A[perm[i]]);
      swap(perm[i], perm[perm[i]]};
    }
  }
}

          
