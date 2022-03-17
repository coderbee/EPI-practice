#include <cmath>
#include <functional>
#include <set>
#include <vector>

#include "test_framework/generic_test.h"

using std::function;
using std::set;
using std::vector;

// These numbers have very interesting property, and people called it ugly
// numbers. It is also called Quadratic integer rings.

struct Number {
  Number(int a, int b) : a(a), b(b), val(a + b * sqrt(2)) {}
  
  int a, b;
  double val;
};

vector<double> GenerateFirstKABSqrt2(int k) { 
