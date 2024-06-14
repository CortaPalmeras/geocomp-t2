#ifndef GC_PUNTO_HPP
#define GC_PUNTO_HPP

#include <iostream>

#include "_declaraciones.hpp"

namespace geocomp {

template <typename T>
std::ostream &operator<<(std::ostream &out, const Punto<T> &p);

template <typename T>
class Punto {
public:
    Punto();
    Punto(T x, T y);
    Punto(Vector<T> const &v);

    T x() const;
    T y() const;

    bool operator==(Punto<T> const &otro) const;
    bool operator!=(Punto<T> const &otro) const;

    bool operator<(Punto<T> const &otro) const;
    bool operator>(Punto<T> const &otro) const;
    bool operator<=(Punto<T> const &otro) const;
    bool operator>=(Punto<T> const &otro) const;

    friend std::ostream &operator<< <T>(std::ostream &out, Punto<T> const &p);

private:
    std::pair<T, T> coords;
};
} // namespace geocomp

#endif // !GC_PUNTO_HPP
