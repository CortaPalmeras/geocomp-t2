
#include <vector>
#include <algorithm>

#include "punto.hpp"
#include "vector.hpp"
#include "poligono.hpp"

namespace geocomp {

using namespace std;

template <typename T>
Poligono<T> gift_wrapping(vector< Punto<T> > const &puntos) {
    // encontrar punto inferior
    auto min_iter = min_element(puntos.begin(), puntos.end());
    uint i_inferior = distance(puntos.begin(), min_iter);

    // crear arreglo de vectores (por conveniencia)
    vector< Vector<T> > vectores;
    for (auto p: puntos) {
        Vector<T> vec(p);
        vectores.push_back(vec);
    }

    vector<Punto<T>> cupula;

    // inicializar variables para iterar
    uint i_actual = i_inferior;
    uint i_previo;
    
    // v_diff es la diferencia entre el vector previo y el actual
    // comienza como el vector unitario en x
    Vector<T> v_diff(1, 0); 

    do {
        cupula.push_back(puntos[i_actual]);

        uint i_maximo = -1;
        double cos_maximo = -1;

        // en cada iteracion se busca el punto que genere el mayor coseno
        // entre v_diff y el vector formado entre el punto y v_actual
        for (uint i = 0; i < vectores.size(); i++) {
            if (i == i_actual) continue;

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
        v_diff   = vectores[i_actual] - vectores[i_previo];

    } while (i_actual != i_inferior);

    return {cupula};
}

template Poligono<int> gift_wrapping<int> (vector<Punto<int>> const& puntos);
template Poligono<long> gift_wrapping<long> (vector<Punto<long>> const& puntos);
template Poligono<float> gift_wrapping<float> (vector<Punto<float>> const& puntos);
template Poligono<double> gift_wrapping<double> (vector<Punto<double>> const& puntos);

}
