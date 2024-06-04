
#ifndef GC_GIFT_WRAPING_H
#define GC_GIFT_WRAPING_H

#include <vector>

#include "punto.hpp"
#include "poligono.hpp"

namespace geocomp {

template <typename T>
Poligono<T> incremental(std::vector< Punto<T> > const &puntos);
    
}

#endif // DEBUG

