#include <bitset>
#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::bitset;
using std::invalud_argument;
using std::vector;

int FindMissingElement(vector<int>::const_iterator stream_begin,
                       const vector<int>::const_iterator& stream_end) {
  const int kNumBucket = 1 << 16;
  vector<size_t> counter(kNumBucket, 0);
  vector<int>::const_iterator stream_begin_copy = stream_begin;
  while (stream_begin != stream_end) {
    int uper_part_x = *stream_begin >> 16;
    ++counter[upper_part_x];
    ++stream_begin;
  }
  
