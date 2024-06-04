
#include "punto.hpp"
#include <iostream>

namespace geocomp {

template <typename T>
Punto<T>::Punto(T x, T y) : coords(x, y) {};

template <typename T>
Punto<T>::Punto() : coords(T(), T()) {}

template <typename T>
T Punto<T>::x() const {
    return coords.first;
}

template <typename T>
T Punto<T>::y() const {
    return coords.second;
}

template <typename T>
bool Punto<T>::operator==(const Punto<T> &other) const {
    return x() == other.x() && y() == other.y();
}

template <typename T>
bool Punto<T>::operator!=(const Punto<T> &otro) const {
    return !operator==(otro);
}

template <typename T>
bool Punto<T>::operator<(const Punto<T> &otro) const {
    return y() < otro.y() || (y() == otro.y() && x() < otro.x());
}

template <typename T>
bool Punto<T>::operator<=(const Punto<T> &otro) const {
    return y() < otro.y() || (y() == otro.y() && x() <= otro.x());
}

template <typename T>
bool Punto<T>::operator>(const Punto<T> &otro) const {
    return y() > otro.y() || (y() == otro.y() && x() > otro.x());
}

template <typename T>
bool Punto<T>::operator>=(const Punto<T> &otro) const {
    return y() > otro.y() || (y() == otro.y() && x() >= otro.x());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Punto<T> &p) {
    return os << '(' << p.x() << ',' << p.y() << ')';
}

template std::ostream &operator<<(std::ostream &, const Punto<int> &);
template std::ostream &operator<<(std::ostream &, const Punto<long> &);
template std::ostream &operator<<(std::ostream &, const Punto<float> &);
template std::ostream &operator<<(std::ostream &, const Punto<double> &);

template class Punto<int>;
template class Punto<long>;
template class Punto<float>;
template class Punto<double>;

} // namespace geocomp
