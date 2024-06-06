
#ifndef GC_GIFT_WRAPING_H
#define GC_GIFT_WRAPING_H

#include <vector>

#include "poligono.hpp"
#include "punto.hpp"

namespace geocomp {

template <typename T>
Poligono<T> incremental(std::vector<Punto<T>> const &puntos);

} // namespace geocomp

#endif // DEBUG
