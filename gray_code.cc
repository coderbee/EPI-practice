#include <algorithm>
#include <memory>
#include <unordered_set>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::unordered_set;
using std::vector;

bool DirectedGrayCode(int, unordered_set<int>*, vector<int>*);
bool DiffersByOneBit(int, int);

vector<int> GrayCode(int num_bits) {
  vector<int> result({0});
  DirectedGrayCode(num_bits,
                   make_unique<unordered_set<int>>(unordered_set<int>{0}).get(),
                   &result);
  return result;
}

bool DirectedGrayCode(int num_bits, unordered_set<int>* history,
                      vector<int>* result) {
  
