
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T>::Poligono(const std::vector<Punto<T>>& v) {
    _vert = v;
    _num_vert = _vert.size();
}

template <typename T>
int Poligono<T>::n_vertices() const {
    return _num_vert;
}

template <typename T>
bool Poligono<T>::es_ccw() const {
    auto it = std::min_element(_vert.begin(), _vert.end());

    int i = std::distance(_vert.begin(), it);

    Vector<T> borde(_vert[i]);
    Vector<T> anterior(_vert[i == 0 ? _num_vert - 1 : i - 1]);
    Vector<T> siguiente(_vert[((i + 1) % _num_vert)]);

    Vector<T> v1 = borde - anterior;
    Vector<T> v2 = siguiente - borde;

    T cruz = v1.cruz(v2);

    return cruz > 0;
}

template <typename T>
bool Poligono<T>::es_convexo() const {
    T factor;
    if (es_ccw()) {
        factor = 1;
    } else {
        factor = -1;
    }

    auto it1 = _vert.begin();
    auto it2 = it1 + 1;
    auto it_last = _vert.end() - 1;

    T x1 = it1->x() - it_last->x();
    T y1 = it1->y() - it_last->y();

    T x2 = it2->x() - it1->x();
    T y2 = it2->y() - it1->y();

    while (it2 != it_last) {
        T p_cruz = x1 * y2 - x2 * y1;
        if (p_cruz * factor <= 0) {
            return false;
        }

        x1 = x2;
        y1 = y2;

        it1++;
        it2++;

        x2 = it2->x() - it1->x();
        y2 = it2->y() - it1->y();
    }
    return true;
}

template <typename T>
const Punto<T>& Poligono<T>::operator[](int i) const {
    return _vert[i];
}

template <typename T>
bool Poligono<T>::operator==(const Poligono<T>& otro) const {
    return _vert == otro._vert;
}

template <typename T>
bool Poligono<T>::operator!=(const Poligono<T>& otro) const {
    return _vert != otro._vert;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Poligono<T>& p) {
    out << '[' << p._vert[0];
    for (int i = 1; i < p._num_vert; i++) {
        out << ',' << p._vert[i];
    }
    out << ']';
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Poligono<int>& p);
template std::ostream& operator<<(std::ostream& out, const Poligono<long>& p);
template std::ostream& operator<<(std::ostream& out, const Poligono<float>& p);
template std::ostream& operator<<(std::ostream& out, const Poligono<double>& p);

template class Poligono<int>;
template class Poligono<long>;
template class Poligono<float>;
template class Poligono<double>;

} // namespace geocomp
