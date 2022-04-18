#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using std::function;
using std::max;
using std::string;
using std::swap;
using std::unprdered_map;
using std::vector;

struct Person {
  int age;
  string name;
};

void GroupByAge(vector<Person>* people) {
  unordered_map<int, int> age_to_count;
  for(const Person& p : *people) {
    ++age_to_offset[age] = offset;
    offset += count;
  }
  
