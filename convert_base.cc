#include <numeric>
#include <string>

using std::accumulate;
using std::string;

string ConstructFromBase(int, int);

string ConvertBase(const string& num_as_string, int b1, int b2) {
  bool is_negative = num_as_string.front() == '-';
  int num_as_int =
    accumulate(begin(num_as_string) + is_negative, end(num_as_string), 0
               [b1](int x, char c) {
                 return x * b1 + (isdigit(c) ? c - '0' : c - 'A' + 10);
               });
  return (is_negative ? "-" : "") + 
        (num_as_int == 0 ? "0" : ConstructFromBase(num_as_int, b2));
}

string ConstructFromBase(int num_as_int, int base) {
  return num_as_int == 0
          ? ""
          : ConstructFromBase(num_as_int / base, base) +
              static_cast<char>(num_as_int % base >= 10
                                ? 'A' + num_as_int % base - 10
                                : '0' + num_as_int % base);
}

