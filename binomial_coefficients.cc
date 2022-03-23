#include <memory>
#include <vector>

using std::make_unique;
using std::min;
using std::vector;

int ComupteXChooseY(int, int, vector<vector<int>>*);

int ComputeBinomialCoefficient(int n, int k) {
  return ComputeXChooseY( n, k,
           make_unique<vector<vector<int>>>(n+1, vector<int>(k + 1, 0)).get());
}

