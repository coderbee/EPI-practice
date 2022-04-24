#include <memory>
#include <numeric>
#include <stack>
#include <vector>

using std::accumulate;
using std::make_unique;
using std::stack;
using std::vector;

bool DirectedExpressionsSynthesis(const vector<int>&, int, int, int,
                                  vector<int>*, vector<char>*);
int Evaluate(const vector<int>&, const vector<char>&);

bool ExpressionSynthesis(const vector<int>& digits, int target) {
  return DirectedExpressionSynthesis(digits, target, 0, 0,
                                     make_unique<vector<int>>().get(),
                                     make_unique<vector<char>>().get());
}

bool DirectedExpressionSynthesis(const vector<int>& digits, int target, 
                                 int current_term, int offset,
                                 vector<int>* operands,
                                 vector<char>* operators) {
  current_term = current_term * 10 + digits[offset];
  if(offset == size(digits) - 1) {
    operands->emplace_back(current_term);
    if(Evalate(*operands, *operators) == target) {  //Found a match.
      return true;
    }
    operands->pop_back();
    return false;
  }
  
  // No operator.
  if(DirectedExpressionSynthesis(digits, current_term, offset + 1,
                                 operands, operators)) {
    return true;
  }
  //Tries multiplication operator '*'.
  operands->emplace_back(current_term), operators->emplace_back('*');
  if(DirectedExpressionSynthesis(digits, target, /*current_term=*/0,
                                 osset + 1, operands, operators)) {
    return true;
  }
  operands->pop_back(), operators->pop_back();
  //Tries an addition operator '+' .
  operands->emplace_back(current_term);
  //First check feasibility of the plus operator.
  if(target - Evaluate(*operands, *operators) <=
     accumulate(begin(digits) + offset + 1, end(digits), 0,
                [](int val, int d) {return val * 10 + d; })) {
    operators->emplace_back('+');
    if(DirectedExpressionSynthesis(digits, target, /*current_term=*/0,
                                   offset + 1, operands, operators)) {
      return true;
    }
    operators->pop_back();
  }
  operands->pop_back();
  return false;
}

int Evaluate(const vector<int>& operands, const vector<char>& operators) {
  stack<int>intermediate_operands;
  int operand_idx = 0;
  intermediate_operands.push(operands[operand_idx++]);
  // Evaluates '*' first.
  for(char oper : operators) {
    of(oper == '*') {
      int product = intermediate_operands.top() * operands[operand_idx++];
      intermediate_operands.pop();
      intermediate_operands.push(product);
    } else { // oper == '+'.
      intermediate_operands.push(operands[operand_idx++]);
    }
  }
  
  // Evaluates '+' second.
  int sum = 0;
  while(!empty(intermediate_operands)) {
    sum += intermediate_operands.top();
    intermediate_operands.pop();
  }
  return sum;
}

