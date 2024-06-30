
#include <algorithm>
#include <deque>
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"
#include "vector.hpp"

namespace geocomp {

template <typename T>
Poligono<T> incremental(const std::vector<Punto<T>>& puntos, bool presorted) {
    size_t n = puntos.size();

    if (n <= 3) {
        return {puntos};
    }

    std::vector<Vector<T>> vectores;
    vectores.reserve(n);
    for (const auto& p : puntos) {
        vectores.emplace_back(p);
    }

    if (!presorted) {
        std::sort(vectores.begin(), vectores.end());
    }

    Vector<T> unit_x(1, 0);
    std::deque<Vector<T>> cupula_der;
    cupula_der.push_back(vectores[0] - unit_x);
    cupula_der.push_back(vectores[0]);

    for (auto it = vectores.begin() + 1; it != vectores.end(); it++) {
        while (true) {
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
    cupula_izq.push_back(vectores[vectores.size() - 1] + unit_x);
    cupula_izq.push_back(vectores[vectores.size() - 1]);

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

    for (const auto& v : cupula_der) {
        cupula.emplace_back(v);
    }

    for (const auto& v : cupula_izq) {
        cupula.emplace_back(v);
    }

    return {cupula};
}

template Poligono<int> incremental<int>(const std::vector<Punto<int>>& puntos, bool presorted);
template Poligono<long> incremental<long>(const std::vector<Punto<long>>& puntos, bool presorted);
template Poligono<float> incremental<float>(const std::vector<Punto<float>>& puntos, bool presorted);
template Poligono<double> incremental<double>(const std::vector<Punto<double>>& puntos,
                                              bool presorted);

} // namespace geocomp
