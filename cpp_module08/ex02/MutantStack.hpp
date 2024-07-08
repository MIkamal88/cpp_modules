#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <list>

// Color Macros
#define RESET "\e[m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  // Constructors and Destructor
  MutantStack(void) : std::stack<T>() {}
  MutantStack(MutantStack const &src) : std::stack<T>(src) {}
  virtual ~MutantStack(void) {}

  // Operator Overload
  MutantStack &operator=(MutantStack const &src) {
    if (this != &src)
      std::stack<T>::operator=(src);
    return *this;
  }
  // Member functions
  typedef typename std::stack<T>::container_type::iterator iterator;
  iterator begin(void) { return (std::stack<T>::c.begin()); }
  iterator end(void) { return (std::stack<T>::c.end()); }
};
