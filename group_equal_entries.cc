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
  unordered_map<int, int> age_to_offset;
  int offset = 0;
  for (const auto& [age, count] : age_to_count) {
    age_to_offset[age] = offset;
    offset += count;
  }
  
  while (!empty(age_to_offset)) {
    auto from = begin(age_to_offset);
    auto to = age_to_offset.find((*people)[from->second].age);
    swap((*people)[from->second], (*people)[to->second]);
    // Use age_to_count to see when we are finished with a particular age.
    --age_to_count[to->first];
    if(age_to_count[to->first] > 0) {
      ++to->second;
    } else {
      age_to_offset.erase(to);
    }
  }
}


