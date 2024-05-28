
#include <cmath>
#include <iostream>

#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Vector<T>::Vector(T x, T y) {
  _x = x;
  _y = y;
}

template <typename T>
Vector<T>::Vector(const Punto<T> &p) {
  _x = p.x();
  _y = p.y();
}

template <typename T>
T Vector<T>::x() const {
  return _x;
}

template <typename T>
T Vector<T>::y() const {
  return _y;
}

template <typename T>
double Vector<T>::modulo() const {
  return std::sqrt((_x * _x + _y * _y));
}

template <typename T>
T Vector<T>::punto(const Vector<T> &otro) const {
  return _x * otro.x() + _y * otro.y();
}

template <typename T>
T Vector<T>::cruz(const Vector<T> &otro) const {
  return _x * otro.y() - _y * otro.x();
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &otro) const {
  return Vector<T>(_x + otro.x(), _y + otro.y());
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &otro) const {
  return Vector<T>(_x - otro.x(), _y - otro.y());
}

template <typename T>
Vector<T> Vector<T>::operator*(T val) const {
  return Vector<T>(_x * val, _y * val);
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &otro) const {
  return _x == otro.x() && _y == otro.y();
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &otro) const {
  return !operator==(otro);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &v) {
  return os << '(' << v.x() << ',' << v.y() << ')';
}

template std::ostream &operator<<(std::ostream &, const Vector<int> &);
template std::ostream &operator<<(std::ostream &, const Vector<long> &);
template std::ostream &operator<<(std::ostream &, const Vector<float> &);
template std::ostream &operator<<(std::ostream &, const Vector<double> &);

template class Vector<int>;
template class Vector<long>;
template class Vector<float>;
template class Vector<double>;

} // namespace geocomp
