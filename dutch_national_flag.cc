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

    
  
