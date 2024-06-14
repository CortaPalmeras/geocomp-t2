#ifndef CONVEX_HULL_TEST_HPP
#define CONVEX_HULL_TEST_HPP

#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <vector>
#include <cmath>

#include "poligono.hpp"
#include "punto.hpp"

const int TEST_SEED = 129391;

namespace geocomp {
using std::vector, std::pair;

template <typename T, typename dist_t>
vector<Punto<T>> conjunto_prueba_rectangulo(T in, T su, T iz, T de, int n_puntos) {
    std::default_random_engine rng(TEST_SEED);

    dist_t dist_x(iz, de);
    dist_t dist_y(in, su);

    vector<Punto<T>> puntos;
    puntos.reserve(n_puntos);

    T cx = (de + iz) / 2;
    T cy = (su + in) / 2;

    vector<Punto<T>> puntos_predefinidos = {
        {iz, in}, // esquina izquierda inferior
        {iz, su}, // esquina izquierda superior
        {de, in}, // esquina derecha inferior
        {de, su}, // esquina derecha superior
        {cx, in}, // arista inferior
        {cx, su}, // arista superior
        {de, cy}, // arista derecha
        {iz, cy}, // arista izquierda
    };

    for (int i = 0; i < 8; ++i) {
        puntos.push_back(puntos_predefinidos.at(i % 8));
    }

    for (int i = 8; i < n_puntos; ++i) {
        puntos.emplace_back(dist_x(rng), dist_y(rng));
    }

    std::shuffle(puntos.begin(), puntos.end(), rng);

    return puntos;
}

template <typename T>
Poligono<T> resultado_esperado_rectangulo(T in, T su, T iz, T de) {
    return {{
        {iz, in}, // esquina izquierda inferior
        {de, in}, // esquina derecha inferior
        {de, su}, // esquina derecha superior
        {iz, su}, // esquina izquierda superior
    }};
}


template <typename T, typename dist_t>
vector<Punto<T>> conjunto_prueba_cruz(T alto, T largo, T ancho, int n_puntos) {
    std::default_random_engine rng(TEST_SEED);

    dist_t dist_alto(-alto, alto);
    dist_t dist_largo(-largo, largo);
    dist_t dist_ancho(-ancho, ancho);

    vector<Punto<T>> puntos;
    puntos.reserve(n_puntos);

    vector<Punto<T>> puntos_predefinidos = {
        {-ancho, -alto },
        { ancho, -alto },
        { largo, -ancho},
        { largo,  ancho},
        { ancho,  alto },
        {-ancho,  alto },
        {-largo,  ancho},
        {-largo, -ancho},
    };

    for (int i = 0; i < 8; ++i) {
        puntos.push_back(puntos_predefinidos[i]);
    }

    int mitad_puntos = n_puntos / 2;

    for (int i = 8; i < mitad_puntos; ++i) {
        puntos.emplace_back(dist_ancho(rng), dist_alto(rng));
    }

    for (int i = mitad_puntos; i < n_puntos; ++i) {
        puntos.emplace_back(dist_largo(rng), dist_ancho(rng));
    }

    std::shuffle(puntos.begin(), puntos.end(), rng);

    return puntos;
}

template <typename T>
Poligono<T> resultado_esperado_cruz(T alto, T largo, T ancho) {
    return {{
        {-ancho, -alto },
        { ancho, -alto },
        { largo, -ancho},
        { largo,  ancho},
        { ancho,  alto },
        {-ancho,  alto },
        {-largo,  ancho},
        {-largo, -ancho},
    }};
}

template <typename T, typename dist_t>
vector<Punto<T>> conjunto_prueba_random(T a, T b, int n_puntos) {
    std::default_random_engine rng(TEST_SEED);

    dist_t dist(a, b);

    std::vector<geocomp::Punto<T>> puntos;
    puntos.reserve(n_puntos);

    for (int i = 0; i < n_puntos; ++i) {
        puntos.emplace_back(dist(rng), dist(rng));
    }

    return puntos;
}

template <typename T, typename dist_t>
vector<Punto<T>> conjunto_prueba_radial(T radio, int n_cupula, int n_internos) {
    std::default_random_engine rng(TEST_SEED);

    double dos_pi = 6.28318530718;
    double step = (dos_pi) / n_cupula;
    T r_cupula = radio + 1;

    std::uniform_real_distribution<double> dist_angulo(0, dos_pi);
    dist_t dist_radio(0, radio);

    std::vector<geocomp::Punto<T>> puntos;
    puntos.reserve(n_cupula + n_internos);

    for (int i = 0; i < n_cupula; ++i) {
        double a = step * i;
        T c = cos(a);
        T s = sin(a);
        puntos.emplace_back(r_cupula * s, -r_cupula * c);
    }

    for (int i = 0; i < n_internos; ++i) {
        T r = dist_radio(rng);
        T a = dist_angulo(rng);
        T c = cos(a);
        T s = sin(a);
        puntos.emplace_back(r * c, r * s);
    }

    std::shuffle(puntos.begin(), puntos.end(), rng);

    return puntos;
}

template <typename T>
Poligono<T> resultado_esperado_radial(T radio, int n_cupula) {
    double dos_pi = 6.28318530718;
    double step = (dos_pi) / n_cupula;
    T r_cupula = radio + 1;

    std::uniform_real_distribution<double> dist_angulo(0, dos_pi);

    std::vector<geocomp::Punto<T>> puntos;
    puntos.reserve(n_cupula);

    for (int i = 0; i < n_cupula; ++i) {
        double a = step * i;
        T c = cos(a);
        T s = sin(a);
        puntos.emplace_back(r_cupula * s, -r_cupula * c);
    }

    return {puntos};
}

} // namespace geocomp

#endif // !CONVEX_HULL_TEST_HPP
