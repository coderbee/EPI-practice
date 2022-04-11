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
    if(num_right_parens_needed) {
      result->emplace_back(valid_prefix);
      return;
    }
    
    if(num_left_parens_needed > 0) { //Able to insert '('.
      DirectedGenerateBalancedParentheses(num_left_parens_needed - 1,
                                          num_right_parens_needed,
                                          valid_prefix + '(', result);
    }
    
    if (num_left_parens_needed < num_right_parens_needed) {
      //Able to insert ')'.
      DirectedGenerateBalancedParentheses(num_left_parens_needed,
                                          num_right_parens_needed - 1,
                                          valid_prefix + ')', result);
    }
  }
  
