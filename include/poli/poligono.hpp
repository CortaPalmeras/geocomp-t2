#ifndef GC_POLIGONO_HPP
#define GC_POLIGONO_HPP

#include <iostream>
#include <vector>

#include "_nombres.hpp"

namespace geocomp {

template <typename T>
std::ostream& operator<<(std::ostream& out, const Poligono<T>& p);

template <typename T>
class Poligono {
public:
    Poligono(const std::vector<Punto<T>>& v);

    int n_vertices() const;

    bool es_ccw() const;
    bool es_convexo() const;

    const Punto<T>& operator[](int i) const;

    bool operator==(const Poligono<T>& otro) const;
    bool operator!=(const Poligono<T>& otro) const;

    friend std::ostream& operator<< <T>(std::ostream& out, const Poligono<T>& p);

private:
    std::vector<Punto<T>> _vert;

    int _num_vert;
};
} // namespace geocomp

#endif // !GC_POLIGONO_HPP
