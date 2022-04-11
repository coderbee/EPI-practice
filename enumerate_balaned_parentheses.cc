#include <string>
#include <vector>

using std::string;
using std::vector;

void DirectedGenerateBalancedParentheses(int, int, string&, vector<string>*);

vector<string> GenerateBalancedParentheses(int num_pairs) {
  vector<string>result;
  DirectedGenerateBalancedParentheses(int num_left_parens_needed,
                                      int num_right_parens_needed,
                                      const string& valid_prefix,
                                      vector<string>*result) {
    if(nim_right_parens_needed) {
      result->emplace_back(valid_prefix);
      return;
    }
