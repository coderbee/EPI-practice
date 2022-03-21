#include <algorithm>
#include <string>
#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::swap;
using std::vector;

void Rearrange(vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  for (size_t i = 1; i < size(A); ++i) {
    if((!(i % 2) && A[i - 1] < A[i]) || ((i % 2) && A[i - 1] > A[i]))) {
      swap(A[i - 1], A[i]);
    }
  }
}

void CheckAnswer(const vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (i % 2) {
      if(A[i] < A[i - 1]) {
        throw TestFailure()
          .WithProperty(PropertyName::RESULT, A)
          .WithMismatchInfo(i, FmtStr("A[{}] <= A[{}]", i - 1, i),
                              FmtStr("{} > {}", A[i - 1], A[i]));
      }
    }
  }

