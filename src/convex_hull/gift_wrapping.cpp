
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T> gift_wrapping(const std::vector<Punto<T>>& puntos) {
    size_t n = puntos.size();
    size_t i_inferior = 0;

    std::vector<Vector<T>> vectores;
    vectores.reserve(n);

    for (size_t i = 0; i < n; i++) {
        vectores.emplace_back(puntos[i]);
        i_inferior = puntos[i] < puntos[i_inferior] ? i : i_inferior;
    }

    std::vector<Punto<T>> cupula;

    size_t i_actual = i_inferior;

    // v_diff es la diferencia entre el vector previo y el actual
    // comienza como el vector unitario en x
    Vector<T> v_diff(-1, 0);

    do {
        cupula.push_back(puntos[i_actual]);

        size_t i_maximo = -1;

        // en cada iteracion se busca el punto que genere el mayor coseno
        // entre v_diff y el vector formado entre el punto y v_actual
        for (size_t i = 0; i < n; i++) {
            if (i == i_actual)
                continue;

            Vector<T> v_candidato = vectores[i] - vectores[i_actual];
            T prod_cruz = v_candidato.cruz(v_diff);

            if (prod_cruz > 0) {
                i_maximo = i;
                v_diff = v_candidato;

            } else if (prod_cruz == 0) {
                if ((v_diff).modulo() < v_candidato.modulo()) {
                    i_maximo = i;
                    v_diff = v_candidato;
                }
            }
        }

        v_diff = vectores[i_actual] - vectores[i_maximo];
        i_actual = i_maximo;

    } while (i_actual != i_inferior);

    return {cupula};
}

template Poligono<int> gift_wrapping<int>(const std::vector<Punto<int>>& puntos);
template Poligono<long> gift_wrapping<long>(const std::vector<Punto<long>>& puntos);
template Poligono<float> gift_wrapping<float>(const std::vector<Punto<float>>& puntos);
template Poligono<double> gift_wrapping<double>(const std::vector<Punto<double>>& puntos);

} // namespace geocomp
