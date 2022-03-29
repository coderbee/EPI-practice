#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

using std::overflow_error;
using std::to_string;
using std::unordered_set;
using std::vector;

bool TestCollatzConjecture (int n) {
  //Stores odd numbers already tested to converge to 1.
  
  //Starts from 3 since hypothesis holds trivially for 1 and 2.
  for (int i = 3; i <= n; i+=2) {
    unordered_set<long long> verified_numbers;
    long long 
