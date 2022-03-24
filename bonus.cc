#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>

using std::function;
using std::max;
using std::priority_queue;
using std::vector;

int CalculateBonus(const vector<int>& productivity) {
  struct EmployeeData {
    int productivity, index;
  };
  priority_queue<EmployeeData, vector<employeeData>,
            function<bool(EmployeeData, EmployeeData)>>
       min_heap([](const EmployeeData& a, const EmployeeData& b) {
         return a.productivity > b.productivity;
       });
  for (int i = 0; i < size(productivity); ++i) {
    min_heap.emplace(EmployeeData{productivity[i], i});
  }
  
  //Initially assigns one ticket to everyone
