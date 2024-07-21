#include "Serialize.hpp"

// Constructors and Destructor
Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) {
  if (this != &src)
    *this = src;
  *this = src;
}

Serializer::~Serializer() {}

// Operator Overload
Serializer &Serializer::operator=(Serializer const &src) {
  if (this != &src)
    *this = src;
  return *this;
}

// Member Functions
uintptr_t Serializer::serialize(Data *ptr) {
  uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
  return (raw);
}

Data *Serializer::deserialize(uintptr_t raw) {
  Data *ptr = reinterpret_cast<Data *>(raw);
  return (ptr);
}
