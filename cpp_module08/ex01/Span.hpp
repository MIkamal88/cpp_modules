#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Color Macros
#define RESET "\e[m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

class Span {
 private:
  unsigned int _n;
  std::vector<int> _vec;

 public:
  // Constructors and Destructor
  Span(unsigned int n);
  Span(const Span &src);
  ~Span();

  // Operators overload
  Span &operator=(const Span &source);

  // Member functions
  void addNumber(int n);
  int shortestSpan(void);
  int longestSpan(void);

  // Getters and setters
  unsigned int getN(void) const;
  std::vector<int> getVec(void) const;

  // Exception classes
  class FullContainerException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return (YELLOW "Container is full." RESET);
    }
  };
  class NotEnoughElementsException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return (YELLOW "Not enough elements in container." RESET);
    }
  };
};

#endif  // !#ifndef SPAN_HPP
