#include "Serialize.hpp"

int main(void) {
  std::cout << std::endl << YELLOW << "Creating data..." << RESET << std::endl;
  Data *data = new Data;
  data->age = 42;
  data->name = "John Doe";
  data->email = "awesomesauce@42.com";

  std::cout << "Data is in pointer: \t\t" << data << std::endl;
  std::cout << "Data is: \t\t\t" << data->age << "\n\t\t\t\t" << data->name
            << "\n\t\t\t\t" << data->email << std::endl;

  std::cout << std::endl << YELLOW << "Serializing..." << RESET << std::endl;
  uintptr_t raw = Serializer::serialize(data);
  std::cout << "Raw pointer is: \t\t" << raw << std::endl;

  std::cout << std::endl << YELLOW << "Deserializing..." << RESET << std::endl;
  Data *ptr = Serializer::deserialize(raw);
  std::cout << "Raw is still pointing at: \t" << ptr << std::endl;
  std::cout << "Raw Data is: \t\t\t" << ptr->age << "\n\t\t\t\t" << ptr->name
            << "\n\t\t\t\t" << ptr->email << std::endl;
  std::cout << std::endl;

  delete data;
  return (0);
}
