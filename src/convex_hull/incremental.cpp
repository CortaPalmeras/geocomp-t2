
#include <algorithm>
#include <deque>
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T> incremental(std::vector<Punto<T>> const &puntos) {
    size_t n = puntos.size();

    if (n <= 3) {
        return {puntos};
    }

    // crear lista de vectores
    std::vector<Vector<T>> vectores;
    vectores.reserve(n);
    for (const auto &p : puntos) {
        vectores.emplace_back(p);
    }

    std::sort(vectores.begin(), vectores.end());

    Vector<T> unit_x(1, 0);

    // como operador < ordena los vectores en el eje y
    // se crea cupula derecha e izquierda.
    std::deque<Vector<T>> cupula_der;
    cupula_der.push_back(vectores[0] - unit_x);
    cupula_der.push_back(vectores[0]);

    for (auto it = vectores.begin() + 1; it != vectores.end(); it++) {
        while (1) {
            auto ult = cupula_der.end() - 1;

            Vector<T> actual = *ult - *(ult - 1);
            Vector<T> siguiente = *it - *(ult - 1);

            if (actual.cruz(siguiente) > 0 || cupula_der.size() <= 2) {
                break;
            } else {
                cupula_der.pop_back();
            }
        }
        cupula_der.push_back(*it);
    }

    cupula_der.pop_front();

    std::deque<Vector<T>> cupula_izq;
    cupula_izq.push_back(vectores[n - 1] + unit_x);
    cupula_izq.push_back(vectores[n - 1]);

    for (auto it = vectores.rbegin() + 1; it != vectores.rend(); ++it) {
        while (true) {
            auto ult = cupula_izq.end() - 1;

            Vector<T> actual = *ult - *(ult - 1);
            Vector<T> siguiente = *it - *(ult - 1);

            if (actual.cruz(siguiente) > 0 || cupula_izq.size() <= 2) {
                break;
            } else {
                cupula_izq.pop_back();
            }
        }
        cupula_izq.push_back(*it);
    }

    cupula_izq.pop_front();
    cupula_izq.pop_front();
    cupula_izq.pop_back();

    std::vector<Punto<T>> cupula;
    cupula.reserve(cupula_der.size() + cupula_izq.size());

    for (const auto &v : cupula_der) {
        cupula.emplace_back(v);
    }

    for (const auto &v : cupula_izq) {
        cupula.emplace_back(v);
    }

    return {cupula};
}

template Poligono<int> incremental<int>(std::vector<Punto<int>> const &puntos);
template Poligono<long> incremental<long>(std::vector<Punto<long>> const &puntos);
template Poligono<float> incremental<float>(std::vector<Punto<float>> const &puntos);
template Poligono<double> incremental<double>(std::vector<Punto<double>> const &puntos);

} // namespace geocomp
