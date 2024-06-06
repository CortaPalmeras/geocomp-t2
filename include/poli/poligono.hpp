#ifndef GC_POLIGONO_H
#define GC_POLIGONO_H

#include <iostream>
#include <vector>

#include "_declaraciones.hpp"

namespace geocomp {

template <typename T>
std::ostream &operator<<(std::ostream &out, Poligono<T> const &p);

template <typename T>
class Poligono {
    public:
    Poligono(std::vector<Punto<T>> const &v);

    int n_vertices() const;

    bool es_ccw() const;
    bool es_convexo() const;

    const Punto<T> &operator[](int i) const;

    bool operator==(Poligono<T> const &otro) const;
    bool operator!=(Poligono<T> const &otro) const;

    friend std::ostream &operator<< <T>(std::ostream &out, Poligono<T> const &p);

    private:
    std::vector<Punto<T>> _vert;

    int _num_vert;
};
} // namespace geocomp

#endif // !GC_POLIGONO_H
