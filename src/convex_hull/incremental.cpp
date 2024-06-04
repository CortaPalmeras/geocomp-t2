
#include <vector>
#include <algorithm>

#include "punto.hpp"
#include "vector.hpp"
#include "poligono.hpp"

namespace geocomp {

using namespace std;

template <typename T>
Poligono<T> incremental(vector< Punto<T> > const &puntos);

}
