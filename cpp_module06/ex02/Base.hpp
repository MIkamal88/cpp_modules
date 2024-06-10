#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Color Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
