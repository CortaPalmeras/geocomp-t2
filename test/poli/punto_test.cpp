
#include <assert.h>
#include <iostream>
#include <sstream>

#include "punto.hpp"

template <typename T>
void puntoTestEntero() {
  std::ostringstream oss;

  geocomp::Punto<T> p1(2, 4), p2(1, -6), p3(2, 4);

  assert(p1.x() == 2);
  assert(p1.y() == 4);
  assert(p2.x() == 1);
  assert(p2.y() == -6);

  assert(p1 == p1);
  assert(!(p1 == p2));
  assert(!(p2 == p3));
  assert(p1 == p3);

  assert(!(p1 != p1));
  assert(p1 != p2);
  assert(p2 != p3);
  assert(!(p1 != p3));

  oss << p1;
  assert(oss.str() == "(2,4)");
  oss.str("");
  oss << p2;
  assert(oss.str() == "(1,-6)");
}

template <typename T>
void puntoTestReal() {
  std::ostringstream oss;
  geocomp::Punto<T> p1(1.53, -14.08), p2(9.5, 3.17), p3(1.53, -14.08);

  assert(std::abs(p1.x() - 1.53) < 0.001);
  assert(std::abs(p1.y() - (-14.08)) < 0.001);
  assert(std::abs(p2.x() - 9.5) < 0.001);
  assert(std::abs(p2.y() - 3.17) < 0.001);

  assert(p1 == p1);
  assert(!(p1 == p2));
  assert(!(p2 == p3));
  assert(p1 == p3);

  assert(!(p1 != p1));
  assert(p1 != p2);
  assert(p2 != p3);
  assert(!(p1 != p3));

  oss << p1;
  assert(oss.str() == "(1.53,-14.08)");
  oss.str("");
  oss << p2;
  assert(oss.str() == "(9.5,3.17)");
}

void puntoTest() {
  std::cout << "Testeando clase 'Punto' en enteros: ";
  puntoTestEntero<int>();
  puntoTestEntero<long>();
  std::cout << "Tests pasados." << std::endl;

  std::cout << "Testeando clase 'Punto' en reales: ";
  puntoTestReal<float>();
  puntoTestReal<double>();
  std::cout << "Tests pasados." << std::endl;
}
