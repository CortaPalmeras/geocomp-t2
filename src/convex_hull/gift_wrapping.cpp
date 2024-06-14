
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T> gift_wrapping(std::vector<Punto<T>> const &puntos) {
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
    size_t i_previo;

    // v_diff es la diferencia entre el vector previo y el actual
    // comienza como el vector unitario en x
    Vector<T> v_diff(1, 0);

    do {
        cupula.push_back(puntos[i_actual]);

        size_t i_maximo = -1;
        double cos_maximo = -1;

        // en cada iteracion se busca el punto que genere el mayor coseno
        // entre v_diff y el vector formado entre el punto y v_actual
        for (size_t i = 0; i < n; i++) {
            if (i == i_actual)
                continue;

            Vector<T> v_candidato = vectores[i] - vectores[i_actual];
            T prod_punto = v_diff.punto(v_candidato);
            double cos_candidato = prod_punto / (v_candidato.modulo() * v_diff.modulo());

            if (cos_maximo < cos_candidato) {
                cos_maximo = cos_candidato;
                i_maximo = i;
            } else if (cos_maximo == cos_candidato) {
                if ((vectores[i_maximo] - vectores[i_actual]).modulo() < v_candidato.modulo()) {
                    cos_maximo = cos_candidato;
                    i_maximo = i;
                }
            }
        }

        i_previo = i_actual;
        i_actual = i_maximo;
        v_diff = vectores[i_actual] - vectores[i_previo];

    } while (i_actual != i_inferior);

    return {cupula};
}

template Poligono<int> gift_wrapping<int>(std::vector<Punto<int>> const &puntos);
template Poligono<long> gift_wrapping<long>(std::vector<Punto<long>> const &puntos);
template Poligono<float> gift_wrapping<float>(std::vector<Punto<float>> const &puntos);
template Poligono<double> gift_wrapping<double>(std::vector<Punto<double>> const &puntos);

} // namespace geocomp
