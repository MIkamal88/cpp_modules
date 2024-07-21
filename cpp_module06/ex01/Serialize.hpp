#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <string>

// Color Macros
#define RESET "\e[m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"

typedef unsigned long int uintptr_t;

struct Data {
  int age;
  std::string name;
  std::string email;
};

class Serializer {
 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(Serializer const &copy);
  ~Serializer();
  Serializer &operator=(Serializer const &copy);
};

#endif
