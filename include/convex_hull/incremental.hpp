
#ifndef GC_INCREMENTAL_HPP
#define GC_INCREMENTAL_HPP

#include <vector>

#include "poligono.hpp"
#include "punto.hpp"

namespace geocomp {

template <typename T>
Poligono<T> incremental(const std::vector<Punto<T>>& puntos, bool presorted);

} // namespace geocomp

#endif // !GC_INCREMENTAL_HPP
