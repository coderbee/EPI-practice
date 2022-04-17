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
  if(size(*result) == (1 << num_bits)) {
    //Check if first and last codes differ by 1 bit.
    return DiffersByOneBit(result->front(), result->back());
  }
  
  for (int i = 0; i < num_bits, ++i ) {
    int previous_code = result->back();
    int candidate_next_code = previous_code ^ (1 << i);
    if(history->emplace(candidate_next_code).second) {
      result->emplace_back(candidate_next_code);
      if(DirectedGrayCode(num_bits, history, result)) {
        return true;
      }
      result->pop_back();
      history->erase(candidate_next_code);
    }
  }
  return false;
}

bool DiffersByOneBit(int x, int y) {
  int bit_difference = x^y;
  return bit_difference && !(bit_difference & (bit_difference - 1));
}

void GrayCodeWrapper(TImedExecutor& executor, int num_bits) {  
