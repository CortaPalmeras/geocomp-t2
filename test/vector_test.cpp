
#include <assert.h>
#include <iostream>
#include <sstream>

#include "punto.hpp"
#include "vector.hpp"

template <typename T>
void vectorTestEntero() {
  std::ostringstream oss;

  geocomp::Punto<T> p1(5, 1);

  geocomp::Vector<T> v1(3, -7), v2(p1), v3(5, 1);

  assert(v1.x() == 3);
  assert(v1.y() == -7);
  assert(v2.x() == 5);
  assert(v2.y() == 1);

  assert(v1.modulo() - 7.61577 < 0.01);
  assert(v2.modulo() - 5.09902 < 0.01);

  assert(v1.punto(v2) == 8);
  assert(v1.punto(v1) == 58);
  assert(v2.punto(v3) == 26);

  assert(v1.cruz(v2) == 38);
  assert(v1.cruz(v1) == 0);
  assert(v2.cruz(v3) == 0);

  geocomp::Vector<T> v4 = v1 + v2 + v3;
  assert(v4.x() == 13);
  assert(v4.y() == -5);

  v4 = v1 * 3;
  assert(v4.x() == 9);
  assert(v4.y() == -21);

  assert(v1 == v1);
  assert(!(v1 == v2));
  assert(!(v1 == v3));
  assert(v2 == v3);

  assert(!(v1 != v1));
  assert(v1 != v2);
  assert(v1 != v3);
  assert(!(v2 != v3));

  oss << v1;
  assert(oss.str() == "(3,-7)");
  oss.str("");
  oss << v2;
  assert(oss.str() == "(5,1)");
}

template <typename T>
void vectorTestReal() {
  std::ostringstream oss;

  geocomp::Punto<T> p1(0.4, -3.72);

  geocomp::Vector<T> v1(2.65, 8.1), v2(p1), v3(0.4, -3.72);

  assert(std::abs(v1.x() - 2.65) < 0.01);
  assert(std::abs(v1.y() - 8.1) < 0.01);
  assert(std::abs(v2.x() - 0.4) < 0.01);
  assert(std::abs(v2.y() - -3.72) < 0.01);

  assert(v1.modulo() - 8.52247 < 0.01);
  assert(v2.modulo() - 3.74144 < 0.01);

  assert(std::abs(v1.punto(v2) - -29.072) < 0.01);
  assert(std::abs(v1.punto(v1) - 72.6325) < 0.01);

  assert(std::abs(v1.cruz(v2) - (-13.098)) < 0.01);
  assert(std::abs(v1.cruz(v1)) < 0.01);

  geocomp::Vector<T> v4 = v1 + v2;
  assert(std::abs(v4.x() - 3.05) < 0.01);
  assert(std::abs(v4.y() - 4.38) < 0.01);

  v4 = v1 * 3;
  assert(std::abs(v4.x() - 7.95) < 0.1);
  assert(std::abs(v4.y() - 24.3) < 0.1);

  assert((v1 * -2 + v2 * 3).y() == 17);
  assert((v1 * 0 + v2 * 4).x() == 20);
  
  assert(v1 == v1);
  assert(!(v1 == v2));
  assert(!(v1 == v3));
  assert(v2 == v3);

  assert(!(v1 != v1));
  assert(v1 != v2);
  assert(v1 != v3);
  assert(!(v2 != v3));

  oss << v1;
  assert(oss.str() == "(2.65,8.1)");
  oss.str("");
  oss << v2;
  assert(oss.str() == "(0.4,-3.72)");
}

void vectorTest() {
  std::cout << "Testeando clase 'Vector' en enteros: ";
  vectorTestEntero<int>();
  vectorTestEntero<long>();
  std::cout << "Tests pasados." << std::endl;

  std::cout << "Testeando clase 'Vector' en reales: ";
  vectorTestReal<float>();
  vectorTestReal<double>();
  std::cout << "Tests pasados." << std::endl;
}
