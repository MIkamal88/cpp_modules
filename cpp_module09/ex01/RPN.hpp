#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
 private:
  std::stack<int> _operands;

  bool _isOperator(const std::string &str) const;
  bool _isOperand(const std::string &str) const;
	void _doMath(char op);

 public:
  RPN(void);
  RPN(RPN const &src);
  ~RPN(void);

  RPN &operator=(RPN const &strc);
  int calculate(std::string expression);

  class EvaluateErrorException : public std::exception {
   public:
    EvaluateErrorException(const std::string &message) : _message(message){};
    virtual ~EvaluateErrorException() throw(){};
    virtual const char *what() const throw() { return _message.c_str(); };

   private:
    std::string _message;
  };
};

#endif
