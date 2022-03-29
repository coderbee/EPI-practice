#include <stdexcept>

using std::invalid_argument;

unsigned long long ClosestIntSameBitCount(unsigned long long x ) {
  const static int kNumUnsignedBits = 64;
  for(int (i = 0; i < kNumUnsignedBits - 1; ++i) {
    if(((x >> i ) & 1) != ((x >>(i + 1)) & 1)) {
      x ^= (1UL << i) | (1UL << (i + 1)); //Swaps bit i and bit i + 1.
      return x;
    }
  }
    
  //THrow error if all bits are 0 or 1.
  throw invalid_argument("All bits are 0 or 1");
}
      
