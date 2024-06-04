
#include <assert.h>
#include <gtest/gtest.h>
#include <sstream>

#include "punto.hpp"
#include "vector.hpp"

template <typename T>
void vector_test_entero() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(5, 1);

    geocomp::Vector<T> v1(3, -7), v2(p1), v3(5, 1);

    assert(v1.x() == 3);
    assert(v1.y() == -7);
    assert(v2.x() == 5);
    assert(v2.y() == 1);

    assert(v1.modulo() - 7.61577 < 0.01);
    assert(v2.modulo() - 5.09902 < 0.01);

    assert(v1.punto(v2) == 8);
    assert(v1.punto(v1) == 58);
    assert(v2.punto(v3) == 26);

    assert(v1.cruz(v2) == 38);
    assert(v1.cruz(v1) == 0);
    assert(v2.cruz(v3) == 0);

    geocomp::Vector<T> v4 = v1 + v2 + v3;
    assert(v4.x() == 13);
    assert(v4.y() == -5);

    v4 = v1 * 3;
    assert(v4.x() == 9);
    assert(v4.y() == -21);

    assert(v1 == v1);
    assert(!(v1 == v2));
    assert(!(v1 == v3));
    assert(v2 == v3);

    assert(!(v1 != v1));
    assert(v1 != v2);
    assert(v1 != v3);
    assert(!(v2 != v3));

    oss << v1;
    assert(oss.str() == "(3,-7)");
    oss.str("");
    oss << v2;
    assert(oss.str() == "(5,1)");
}

template <typename T>
void vector_test_real() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(0.4, -3.72);

    geocomp::Vector<T> v1(2.65, 8.1), v2(p1), v3(0.4, -3.72);

    assert(std::abs(v1.x() - 2.65) < 0.01);
    assert(std::abs(v1.y() - 8.1) < 0.01);
    assert(std::abs(v2.x() - 0.4) < 0.01);
    assert(std::abs(v2.y() - -3.72) < 0.01);

    assert(v1.modulo() - 8.52247 < 0.01);
    assert(v2.modulo() - 3.74144 < 0.01);

    assert(std::abs(v1.punto(v2) - -29.072) < 0.01);
    assert(std::abs(v1.punto(v1) - 72.6325) < 0.01);

    assert(std::abs(v1.cruz(v2) - (-13.098)) < 0.01);
    assert(std::abs(v1.cruz(v1)) < 0.01);

    geocomp::Vector<T> v4 = v1 + v2;
    assert(std::abs(v4.x() - 3.05) < 0.01);
    assert(std::abs(v4.y() - 4.38) < 0.01);

    v4 = v1 * 3;
    assert(std::abs(v4.x() - 7.95) < 0.1);
    assert(std::abs(v4.y() - 24.3) < 0.1);

    assert(v1 == v1);
    assert(!(v1 == v2));
    assert(!(v1 == v3));
    assert(v2 == v3);

    assert(!(v1 != v1));
    assert(v1 != v2);
    assert(v1 != v3);
    assert(!(v2 != v3));

    oss << v1;
    assert(oss.str() == "(2.65,8.1)");
    oss.str("");
    oss << v2;
    assert(oss.str() == "(0.4,-3.72)");
}

TEST(vector_test, vector_con_int) {
    vector_test_entero<int>();
}

TEST(vector_test, vector_con_long) {
    vector_test_entero<long>();
}

TEST(vector_test, vector_con_float) {
    vector_test_real<float>();
}

TEST(vector_test, vector_con_double) {
    vector_test_real<double>();
}
