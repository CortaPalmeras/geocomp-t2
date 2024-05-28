
#include <iostream>

void puntoTest();
void vectorTest();
void poligonoTest();

int main() {

  std::cout << "Ejecutando tests..." << std::endl;

  puntoTest();
  vectorTest();
  poligonoTest();

  std::cout << "Todos los tests pasaron!" << std::endl;

  return 0;
}
