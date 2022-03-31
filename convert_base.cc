#include <numeric>
#include <string>

using std::accumulate;
using std::string;

string ConstructFromBase(int, int);

string ConvertBase(const string& num_as_string, int b1, int b2) {
  bool is_negative = num_as_string.front() == '-';
  
