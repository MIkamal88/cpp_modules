#include "Base.hpp"

// Randomly instanciates a Base class
Base *generate(void) {
  int random = std::rand() % 3;

  switch (random) {
    case 0:
      return (new A);
    case 1:
      return (new B);
    case 2:
      return (new C);
    default:
      return (NULL);
  }
}

/*
** Identifies the type of the Base class using pointers
** ----------------------------------------------------
** When you use dynamic_cast with pointers, if the cast fails, the function
** returns a null pointer.
*/
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown Type" << std::endl;
}

/*
** Identifies the type of the Base class using references
** ----------------------------------------------------
** When you use dynamic_cast with references, if the cast fails, the function
** throws an std::badcast exception. References can not be NULL.
*/
void identify(Base &p) {
  try {
    if (dynamic_cast<A *>(&p)) {
      std::cout << "A" << std::endl;
      return;
    }
  } catch (const std::exception &e) {
  }
  try {
    if (dynamic_cast<B *>(&p)) {
      std::cout << "B" << std::endl;
      return;
    }
  } catch (const std::exception &e1) {
  }
  try {
    if (dynamic_cast<C *>(&p)) {
      std::cout << "C" << std::endl;
      return;
    }
  } catch (const std::exception &e2) {
  }
  std::cout << "Unknown Type" << std::endl;
}

int main(void) {
  Base *object1 = generate();
  std::cout << "Object1 is ";
  identify(object1);
  delete (object1);

  Base *object2 = generate();
  std::cout << "Object2 is ";
  identify(object2);
  delete (object2);

  Base *object3 = generate();
  Base &ref = *object3;
  std::cout << "Object3 is ";
  identify(ref);
  delete (object3);
}
