#ifndef GC_VECTOR_HPP
#define GC_VECTOR_HPP

#include <iostream>

#include "_nombres.hpp"

namespace geocomp {

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

template <typename T>
class Vector {
public:
    Vector(T x, T y);
    Vector(const Punto<T>& p);

    T x() const;
    T y() const;

    double modulo() const;

    T punto(const Vector<T>& otro) const;
    T cruz(const Vector<T>& otro) const;

    Vector<T> operator+(const Vector<T>& otro) const;
    Vector<T> operator-(const Vector<T>& otro) const;
    Vector<T> operator*(T val) const;

    bool operator==(const Vector<T>& otro) const;
    bool operator!=(const Vector<T>& otro) const;

    bool operator<(const Vector<T>& otro) const;
    bool operator>(const Vector<T>& otro) const;
    bool operator<=(const Vector<T>& otro) const;
    bool operator>=(const Vector<T>& otro) const;

    friend std::ostream& operator<< <T>(std::ostream& out, const Vector<T>& v);

private:
    T _x, _y;
};

} // namespace geocomp

#endif // !GC_VECTOR_HPP
