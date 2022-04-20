#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

int HIndex(vector<int> citations) {
  sort(begin(citations), end(citations));
  const int n = citations.size();
  for(int i = 0; i < citations.size(); ++i) {
    if(citations[i] >- n -i) {
      return n - i;
    }
  }
  return 0;
}
