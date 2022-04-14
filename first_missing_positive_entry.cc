#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

//A is passed by value argument, since we caught it.
int FondFirstMissingPositive(vector<int> A) {
  //Record which values are present by writing A[i] to index A[i] - 1
