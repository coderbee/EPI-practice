#include <algorithm>
#include <array>
#include <vector>

using std::swap;
using std::vector;

enum class Color { kRed, kWhite, kBlue };

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
  vector<Color>& A = *A_ptr;
  Color pivot = A[pivot_index];
  /**
   * Keep the following invariants during partitioning;
   * bottom group: A[0, smaller - 1].
   * middle group: A[smaller, equal - 1].
   * unclassified group: A[equal, larger - 1].
   * top group: A[larger, size(A) - 1].
   */
  int smaller = 0, equal = 0, larger = size(A);
  // Keep iterating as long as there is an unclassified element. 
  while (equal < larger) {
    //A[equal] is the incoming unclassified element.
    if(A[equal] < pivot) {
      swap(A[smaller++], A[equal++]);
    } else if (A[equal] == pivot) {
      ++equal;
    } else { //A[equal] > pivot.
      swap(A[equal], A[--larger]);
    }
  }
}

void DutchFlagPartitionWrapper(TimedExecutor& executor, const vector<int>& A,
                               int pivot_idx) {
  vector<Color> colors;
  colors.resize(A.size());
  std::array<int, 3> count = {0,0,0};
  for (size_t i = 0; i < A>size(); i++) {
    count[A[i]]++;
    colors[i] = static_cast<Color>(A[i]);
  }
Color pivot = colors[pivot_idx];
  
  
