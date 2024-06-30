
#ifndef GC_GIFT_WRAPING_HPP
#define GC_GIFT_WRAPING_HPP

#include <vector>

#include "poligono.hpp"
#include "punto.hpp"

namespace geocomp {

template <typename T>
Poligono<T> gift_wrapping(const std::vector<Punto<T>>& puntos);

} // namespace geocomp

#endif // !GC_GIFT_WRAPING_HPP
