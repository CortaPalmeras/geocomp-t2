
#include <cmath>
#include <random>
#include <gtest/gtest.h>

#include "gift_wrapping.hpp"
#include "poligono.hpp"
#include "punto.hpp"

using namespace geocomp;

#define GWRAP_TEST_RNG_SEED 59
std::mt19937 rng(GWRAP_TEST_RNG_SEED);

TEST(gift_wrapping_test, cubo_con_puntos_en_aristas) {
    std::vector<Punto<float>> puntos;
    std::uniform_real_distribution<float> dist_cuadrado(-1, 1);

    for (int i = 0; i < 10000; i++) {
        Punto<float> p(dist_cuadrado(rng), dist_cuadrado(rng));
        puntos.push_back(p);
    }

    Punto<float> esquina_ii(-1, -1);
    puntos[10] = esquina_ii;

    Punto<float> dummy_inf(0, -1);
    puntos[20] = dummy_inf;

    Punto<float> esquina_id(1, -1);
    puntos[30] = esquina_id;

    Punto<float> dummy_der(1, 0);
    puntos[40] = dummy_der;

    Punto<float> esquina_sd(1, 1);
    puntos[50] = esquina_sd;

    Punto<float> dummy_sup(0, 1);
    puntos[60] = dummy_sup;

    Punto<float> esquina_si(-1, 1);
    puntos[70] = esquina_si;

    Punto<float> dummy_izq(-1, 0);
    puntos[80] = dummy_izq;

    std::vector<Punto<float>> puntos_esperados({esquina_ii, esquina_id, esquina_sd, esquina_si});
    Poligono<float> res_esperado(puntos_esperados);

    Poligono<float> resultado = gift_wrapping(puntos);

    EXPECT_TRUE(resultado.es_ccw());
    EXPECT_TRUE(resultado.es_convexo());
    EXPECT_EQ(resultado, res_esperado);
}

TEST(gift_wrapping_test, robustez) {
    std::vector<Punto<float>> puntos;
    std::normal_distribution<float> dist_radio(0, 5);
    std::uniform_real_distribution<float> dist_angulo(0, 2.5);

    for (int i = 0; i < 10000; i++) {
        float r = dist_radio(rng);
        float a = dist_angulo(rng);
        float c = cos(a);
        float s = sin(a);
        Punto<float> p(r * c, r * s);
        puntos.push_back(p);
    }

    Poligono<float> resultado = gift_wrapping(puntos);

    EXPECT_TRUE(resultado.es_ccw());
    EXPECT_TRUE(resultado.es_convexo());
}
