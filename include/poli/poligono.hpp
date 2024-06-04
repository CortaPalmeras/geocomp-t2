
#ifndef GC_POLIGONO_H
#define GC_POLIGONO_H

#include <iostream>
#include <vector>

#include "punto.hpp"

namespace geocomp {

template <typename T>
class Poligono;

template <typename T>
std::ostream &operator<<(std::ostream &out, const Poligono<T> &p);

template <typename T>
class Poligono {
    public:
    Poligono(std::vector<Punto<T>> &v);

    int n_vertices() const;

    bool es_ccw() const;
    bool es_convexo() const;

    const Punto<T> &operator[](int i) const;

    bool operator==(Poligono<T> const &otro) const;
    bool operator!=(Poligono<T> const &otro) const;

    friend std::ostream &operator<< <T>(std::ostream &out, const Poligono<T> &p);

    private:
    std::vector<Punto<T>> _vert;

    int _num_vert;
};
} // namespace geocomp

#endif // !GC_POLIGONO_H

