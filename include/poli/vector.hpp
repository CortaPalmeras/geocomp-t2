#ifndef GC_VECTOR_HPP
#define GC_VECTOR_HPP

#include <iostream>

#include "_declaraciones.hpp"

namespace geocomp {

template <typename T>
std::ostream &operator<<(std::ostream &out, Vector<T> const &v);

template <typename T>
class Vector {
public:
    Vector(T x, T y);
    Vector(const Punto<T> &p);

    T x() const;
    T y() const;

    double modulo() const;

    T punto(Vector<T> const &otro) const;
    T cruz(Vector<T> const &otro) const;

    Vector<T> operator+(Vector<T> const &otro) const;
    Vector<T> operator-(Vector<T> const &otro) const;
    Vector<T> operator*(T val) const;

    bool operator==(Vector<T> const &otro) const;
    bool operator!=(Vector<T> const &otro) const;

    bool operator<(Vector<T> const &otro) const;
    bool operator>(Vector<T> const &otro) const;
    bool operator<=(Vector<T> const &otro) const;
    bool operator>=(Vector<T> const &otro) const;

    friend std::ostream &operator<< <T>(std::ostream &out, Vector<T> const &v);

private:
    T _x, _y;
};

} // namespace geocomp

#endif // !GC_VECTOR_HPP
