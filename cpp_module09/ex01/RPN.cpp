#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &src) {
  *this = src;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &src) {
  if (this != &src) {
    this->_operands = src._operands;
  }
  return *this;
}

/**
 * calculate()
 * @brief Evaluates the expression passed as a parameter and calculates the
 * result.
 *
 * @param std::string The expression.
 * @return integer result of the calculation.
 */
int RPN::calculate(std::string expression) {
  std::istringstream stream(expression);
  std::string token;

  while (stream >> token) {
    if (_isOperand(token))
      _operands.push(std::atoi(token.c_str()));
    else if (_isOperator(token))
      try {
        _doMath(token.begin()[0]);
      } catch (std::exception &e) {
        throw EvaluateErrorException(e.what());
      }
    else
      throw EvaluateErrorException("Error");
  }
  if (_operands.size() != 1)
    throw EvaluateErrorException("Error");
  return _operands.top();
}

/*
 * _isOperator()
 * @brief Checks if the character passed as parameter is an operator.
 *
 * @param std::string The expression.
 * @return boolean whether the token is an operator or not.
 */
bool RPN::_isOperator(const std::string &token) const {
  if (token == "+" || token == "-" || token == "*" || token == "/")
    return (true);
  return (false);
}

/*
 * _isOperand()
 * @brief iterates through the stack and checks if the character passed as
 * parameter is an operand.
 *
 * @param std::string The expression.
 * @return boolean whether the token is an operand or not.
 */
bool RPN::_isOperand(const std::string &token) const {
  int num;

  for (std::string::const_iterator it = token.begin(); it != token.end(); it++)
    if (!std::isdigit(*it))
      return false;
  num = std::atoi(token.c_str());
  if (num < 0 || num > 9)
    return false;
  return true;
}

void RPN::_doMath(char op) {
  int result = 0;
  int op1 = 0;
  int op2 = 0;

  if (_operands.size() < 2)
    throw EvaluateErrorException("Error");
  op2 = _operands.top();
  _operands.pop();
  op1 = _operands.top();
  _operands.pop();

  switch (op) {
    case '+':
      result = op1 + op2;
      break;
    case '-':
      result = op1 + op2;
      break;
    case '*':
      result = op1 * op2;
      break;
    case '/':
      if (op2 == 0) {
        throw EvaluateErrorException("Error: Division by Zero");
        return;
      }
      result = op1 / op2;
      break;
    default:
      throw EvaluateErrorException("Error");
  }
  _operands.push(result);
  return;
}
