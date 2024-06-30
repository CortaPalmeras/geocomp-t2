#ifndef GC_PUNTO_HPP
#define GC_PUNTO_HPP

#include <iostream>

#include "_nombres.hpp"

namespace geocomp {

template <typename T>
std::ostream& operator<<(std::ostream& out, const Punto<T>& p);

template <typename T>
class Punto {
public:
    Punto();
    Punto(T x, T y);
    Punto(const Vector<T>& v);

    T x() const;
    T y() const;

    bool operator==(const Punto<T>& otro) const;
    bool operator!=(const Punto<T>& otro) const;

    bool operator<(const Punto<T>& otro) const;
    bool operator>(const Punto<T>& otro) const;
    bool operator<=(const Punto<T>& otro) const;
    bool operator>=(const Punto<T>& otro) const;

    friend std::ostream& operator<< <T>(std::ostream& out, const Punto<T>& p);

private:
    std::pair<T, T> coords;
};
} // namespace geocomp

#endif // !GC_PUNTO_HPP
