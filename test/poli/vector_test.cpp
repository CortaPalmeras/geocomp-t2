
#include <gtest/gtest.h>
#include <sstream>

#include "punto.hpp"
#include "vector.hpp"

template <typename T>
void vector_test_entero() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(5, 1);

    geocomp::Vector<T> v1(3, -7), v2(p1), v3(5, 1);

    EXPECT_EQ(v1.x(), 3);
    EXPECT_EQ(v1.y(), -7);
    EXPECT_EQ(v2.x(), 5);
    EXPECT_EQ(v2.y(), 1);

    EXPECT_LT(std::abs(v1.modulo() - 7.61577), 0.0001);
    EXPECT_LT(std::abs(v2.modulo() - 5.09902), 0.0001);

    EXPECT_EQ(v1.punto(v2), 8);
    EXPECT_EQ(v1.punto(v1), 58);
    EXPECT_EQ(v2.punto(v3), 26);

    EXPECT_EQ(v1.cruz(v2), 38);
    EXPECT_EQ(v1.cruz(v1), 0);
    EXPECT_EQ(v2.cruz(v3), 0);

    geocomp::Vector<T> v4 = v1 + v2 + v3;
    EXPECT_EQ(v4.x(), 13);
    EXPECT_EQ(v4.y(), -5);

    v4 = v1 * 3;
    EXPECT_EQ(v4.x(), 9);
    EXPECT_EQ(v4.y(), -21);

    EXPECT_TRUE(v1 == v1);
    EXPECT_FALSE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
    EXPECT_TRUE(v2 == v3);

    EXPECT_FALSE(v1 != v1);
    EXPECT_TRUE(v1 != v2);
    EXPECT_TRUE(v1 != v3);
    EXPECT_FALSE(v2 != v3);

    geocomp::Vector<T> v5(1, -7);
    EXPECT_TRUE(v1 < v2);
    EXPECT_TRUE(v1 <= v3);
    EXPECT_TRUE(v2 <= v3);
    EXPECT_TRUE(v5 < v1);
    EXPECT_FALSE(v2 < v3);
    EXPECT_FALSE(v3 < v1);
    EXPECT_FALSE(v1 <= v5);

    EXPECT_TRUE(v5 > v4);
    EXPECT_TRUE(v1 > v5);
    EXPECT_TRUE(v3 >= v2);
    EXPECT_FALSE(v4 >= v3);
    EXPECT_FALSE(v5 > v1);

    oss << v1;
    EXPECT_EQ(oss.str(), "(3,-7)");
    oss.str("");
    oss << v2;
    EXPECT_EQ(oss.str(), "(5,1)");
}

template <typename T>
void vector_test_real() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(0.4, -3.72);

    geocomp::Vector<T> v1(2.65, 8.1), v2(p1), v3(0.4, -3.72);

    EXPECT_LT(std::abs(v1.x() - 2.65), 0.0001);
    EXPECT_LT(std::abs(v1.y() - 8.1), 0.0001);
    EXPECT_LT(std::abs(v2.x() - 0.4), 0.0001);
    EXPECT_LT(std::abs(v2.y() - -3.72), 0.0001);

    EXPECT_LT(v1.modulo() - 8.52247, 0.0001);
    EXPECT_LT(v2.modulo() - 3.74144, 0.0001);

    EXPECT_LT(std::abs(v1.punto(v2) - -29.072), 0.0001);
    EXPECT_LT(std::abs(v1.punto(v1) - 72.6325), 0.0001);

    EXPECT_LT(std::abs(v1.cruz(v2) - (-13.098)), 0.0001);
    EXPECT_LT(std::abs(v1.cruz(v1)), 0.0001);

    geocomp::Vector<T> v4 = v1 + v2;
    EXPECT_LT(std::abs(v4.x() - 3.05), 0.0001);
    EXPECT_LT(std::abs(v4.y() - 4.38), 0.0001);

    v4 = v1 * 3;
    EXPECT_LT(std::abs(v4.x() - 7.95), 0.0001);
    EXPECT_LT(std::abs(v4.y() - 24.3), 0.0001);

    EXPECT_TRUE(v1 == v1);
    EXPECT_FALSE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
    EXPECT_TRUE(v2 == v3);

    EXPECT_FALSE(v1 != v1);
    EXPECT_TRUE(v1 != v2);
    EXPECT_TRUE(v1 != v3);
    EXPECT_FALSE(v2 != v3);

    /*geocomp::Vector<T> v1(2.65, 8.1), v2(p1), v3(0.4, -3.72);*/
    geocomp::Vector<T> v5(-4.66, 8.1);
    EXPECT_TRUE(v3 < v1);
    EXPECT_TRUE(v2 <= v3);
    EXPECT_TRUE(v5 < v1);
    EXPECT_FALSE(v1 <= v3);
    EXPECT_FALSE(v2 < v3);
    EXPECT_FALSE(v1 < v2);
    EXPECT_FALSE(v1 <= v5);

    EXPECT_TRUE(v4 >= v3);
    EXPECT_TRUE(v1 > v5);
    EXPECT_TRUE(v3 >= v2);
    EXPECT_FALSE(v5 > v4);
    EXPECT_FALSE(v5 > v1);

    oss << v1;
    EXPECT_EQ(oss.str(), "(2.65,8.1)");
    oss.str("");
    oss << v2;
    EXPECT_EQ(oss.str(), "(0.4,-3.72)");
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
