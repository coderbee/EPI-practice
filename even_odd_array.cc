#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

using std::swap;
using std::vector;

void EvenOdd(vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  int next_even = 0, next_odd = size(A) - 1;
  while(next_even < next_odd) {
    if(A[next_even] % 2 == 0) {
      ++next_even;
    } else {
      swap(A[next_even], A[next_odd--]);
    }
  }
}

void EvenOddWrapper(TmedExecutor& executor, vector<int> A) {
  std::multiset<int> before(begin(A), end(A));
  executor.Run([&] { EvenOdd(&A); });
  
  bool in_odd = false;
  for(int a : A) {
    if (a % 2 ==0) {
      if(in_odd) {
        throw TestFailure("Even elements appear in oddd part");
      }
    } else {
      in_odd = true;
    }
  }
  
  std::Multiset<int> after(begin(A), end(A));
  if( before != after) {
    throw TestFailure("Elements mismatch");
  }
}
