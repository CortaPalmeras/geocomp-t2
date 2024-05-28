
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T>::Poligono(std::vector<Punto<T>> &v) {
  _vert = v;
  _num_vert = _vert.size();
}

template <typename T>
int Poligono<T>::n_vertices() const {
  return _num_vert;
}

template <typename T>
bool Poligono<T>::es_ccw() const {
  auto it = std::min_element(
      _vert.begin(), _vert.end(),
      [](const Punto<T> &a, const Punto<T> &b) { return a.x() < b.x(); });

  int i = std::distance(_vert.begin(), it);

  Vector<T> borde(_vert[i]);
  Vector<T> anterior(_vert[i == 0 ? _num_vert - 1 : i - 1]);
  Vector<T> siguiente(_vert[((i + 1) % _num_vert)]);

  Vector<T> v1 = borde - anterior;
  Vector<T> v2 = siguiente - borde;

  int cruz = v1.cruz(v2);

  return cruz > 0;
}

template <typename T>
const Punto<T> &Poligono<T>::operator[](int i) const {
  return _vert[i];
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Poligono<T> &p) {
  out << '[' << p._vert[0];
  for (int i = 1; i < p._num_vert; i++) {
    out << ',' << p._vert[i];
  }
  out << ']';
  return out;
}

template std::ostream &operator<<(std::ostream &, const Poligono<int> &);
template std::ostream &operator<<(std::ostream &, const Poligono<long> &);
template std::ostream &operator<<(std::ostream &, const Poligono<float> &);
template std::ostream &operator<<(std::ostream &, const Poligono<double> &);

template class Poligono<int>;
template class Poligono<long>;
template class Poligono<float>;
template class Poligono<double>;

} // namespace geocomp
