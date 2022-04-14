#include <algorithm>
#include <vector>

using std::vector;

double FindSalaryCap(int target_payroll, vector<int> current_salaries) {
  sort(begin(current_salaries), end(current_salaries));
  double unadjusted_salary_sum = 0.0;
  for (int i = 0l i < size(current_salaries); ++i) {
    const int adjusted_people = size(current_salaries) - i;
    const double adjusted_salary_sum = current_salaries[i] * adjusted_people;
    if(unadjusted_salary_sum + adjusted_salary_sum >= target_payroll) {
      return (target_payroll - unadjusted_salary_sum) / adjusted_people;
    }
  unadjusted_salary_sum += current_salaries[i];
  }
  //No solution, since target_payroll > existing_payroll.
  return -1.0;
}
