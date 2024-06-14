
#include <gtest/gtest.h>
#include <random>

#include "convex_hull_test.hpp"
#include "incremental.hpp"
#include "poligono.hpp"
#include "punto.hpp"

using int_dist = std::uniform_int_distribution<int>;
using long_dist = std::uniform_int_distribution<long>;
using float_dist = std::uniform_real_distribution<float>;
using double_dist = std::uniform_real_distribution<double>;

using namespace geocomp;

// Int
TEST(IncrementalInt, Rectangulo) {
    vector<Punto<int>> puntos = conjunto_prueba_rectangulo<int, int_dist>(-1, 1, -1, 1, 10000);
    Poligono<int> cupula = incremental(puntos);
    Poligono<int> esperado = resultado_esperado_rectangulo<int>(-1, 1, -1, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_rectangulo<int, int_dist>(-19, -4, -5, 8, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_rectangulo<int>(-19, -4, -5, 8);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}


TEST(IncrementalInt, Cruz) {
    vector<Punto<int>> puntos = conjunto_prueba_cruz<int, int_dist>(5, 5, 2, 10000);
    Poligono<int> cupula = incremental(puntos);
    Poligono<int> esperado = resultado_esperado_cruz<int>(5, 5, 2);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_cruz<int, int_dist>(10, 20, 1, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_cruz<int>(10, 20, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalInt, Random) {
    vector<Punto<int>> puntos = conjunto_prueba_random<int, int_dist>(-1000, 1000, 10000);
    Poligono<int> cupula = incremental(puntos);

    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

// Long
TEST(IncrementalLong, Rectangulo) {
    vector<Punto<long>> puntos = conjunto_prueba_rectangulo<long, long_dist>(-1, 1, -1, 1, 10000);
    Poligono<long> cupula = incremental(puntos);
    Poligono<long> esperado = resultado_esperado_rectangulo<long>(-1, 1, -1, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_rectangulo<long, long_dist>(-19, -4, -5, 8, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_rectangulo<long>(-19, -4, -5, 8);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}


TEST(IncrementalLong, Cruz) {
    vector<Punto<long>> puntos = conjunto_prueba_cruz<long, long_dist>(5, 5, 2, 10000);
    Poligono<long> cupula = incremental(puntos);
    Poligono<long> esperado = resultado_esperado_cruz<long>(5, 5, 2);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_cruz<long, long_dist>(10, 20, 1, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_cruz<long>(10, 20, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalLong, Random) {
    vector<Punto<long>> puntos = conjunto_prueba_random<long, long_dist>(-1000, 1000, 10000);
    Poligono<long> cupula = incremental(puntos);

    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

// Float
TEST(IncrementalFloat, Rectangulo) {
    vector<Punto<float>> puntos = conjunto_prueba_rectangulo<float, float_dist>(-1, 1, -1, 1, 10000);
    Poligono<float> cupula = incremental(puntos);
    Poligono<float> esperado = resultado_esperado_rectangulo<float>(-1, 1, -1, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_rectangulo<float, float_dist>(-19, -4, -5, 8, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_rectangulo<float>(-19, -4, -5, 8);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}


TEST(IncrementalFloat, Cruz) {
    vector<Punto<float>> puntos = conjunto_prueba_cruz<float, float_dist>(5, 5, 2, 10000);
    Poligono<float> cupula = incremental(puntos);
    Poligono<float> esperado = resultado_esperado_cruz<float>(5, 5, 2);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_cruz<float, float_dist>(10, 20, 1, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_cruz<float>(10, 20, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalFloat, Random) {
    vector<Punto<float>> puntos = conjunto_prueba_random<float, float_dist>(-1000, 1000, 10000);
    Poligono<float> cupula = incremental(puntos);

    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalFloat, Radial) {
    vector<Punto<float>> puntos = conjunto_prueba_radial<float, float_dist>(5, 100, 10000);
    Poligono<float> cupula = incremental(puntos);
    Poligono<float> esperado = resultado_esperado_radial<float>(5, 100);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_radial<float, float_dist>(3, 10, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_radial<float>(3, 10);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

// Double
TEST(IncrementalDouble, Rectangulo) {
    vector<Punto<double>> puntos = conjunto_prueba_rectangulo<double, double_dist>(-1, 1, -1, 1, 10000);
    Poligono<double> cupula = incremental(puntos);
    Poligono<double> esperado = resultado_esperado_rectangulo<double>(-1, 1, -1, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_rectangulo<double, double_dist>(-19, -4, -5, 8, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_rectangulo<double>(-19, -4, -5, 8);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}


TEST(IncrementalDouble, Cruz) {
    vector<Punto<double>> puntos = conjunto_prueba_cruz<double, double_dist>(5, 5, 2, 10000);
    Poligono<double> cupula = incremental(puntos);
    Poligono<double> esperado = resultado_esperado_cruz<double>(5, 5, 2);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_cruz<double, double_dist>(10, 20, 1, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_cruz<double>(10, 20, 1);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalDouble, Random) {
    vector<Punto<double>> puntos = conjunto_prueba_random<double, double_dist>(-1000, 1000, 10000);
    Poligono<double> cupula = incremental(puntos);

    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

TEST(IncrementalDouble, Radial) {
    vector<Punto<double>> puntos = conjunto_prueba_radial<double, double_dist>(5, 100, 10000);
    Poligono<double> cupula = incremental(puntos);
    Poligono<double> esperado = resultado_esperado_radial<double>(5, 100);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());

    puntos = conjunto_prueba_radial<double, double_dist>(3, 10, 10000);
    cupula = incremental(puntos);
    esperado = resultado_esperado_radial<double>(3, 10);

    EXPECT_EQ(cupula, esperado);
    EXPECT_TRUE(cupula.es_ccw());
    EXPECT_TRUE(cupula.es_convexo());
}

