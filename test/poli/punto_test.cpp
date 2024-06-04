
#include <assert.h>
#include <sstream>
#include <gtest/gtest.h>

#include "punto.hpp"

template <typename T>
void punto_test_entero() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(2, 4), p2(1, -6), p3(2, 4);

    EXPECT_EQ(p1.x(), 2);
    EXPECT_EQ(p1.y(), 4);
    EXPECT_EQ(p2.x(), 1);
    EXPECT_EQ(p2.y(), -6);

    EXPECT_TRUE(p1 == p1);
    EXPECT_FALSE(p1 == p2);
    EXPECT_FALSE(p2 == p3);
    EXPECT_TRUE(p1 == p3);

    EXPECT_FALSE(p1 != p1);
    EXPECT_TRUE(p1 != p2);
    EXPECT_TRUE(p2 != p3);
    EXPECT_FALSE(p1 != p3);

    geocomp::Punto<T> p4(0, 4);
    EXPECT_TRUE(p2 <  p4);
    EXPECT_TRUE(p2 <= p4);
    EXPECT_TRUE(p4 >  p2);
    EXPECT_TRUE(p4 >= p2);

    EXPECT_TRUE(p1 >  p4);
    EXPECT_TRUE(p1 >= p4);
    EXPECT_TRUE(p4 <  p1);
    EXPECT_TRUE(p4 <= p1);

    EXPECT_FALSE(p1 <  p2);
    EXPECT_FALSE(p1 <= p2);
    EXPECT_FALSE(p2 >  p1);
    EXPECT_FALSE(p2 >= p1);

    EXPECT_FALSE(p1 < p3);
    EXPECT_TRUE(p1 <= p3);
    EXPECT_FALSE(p1 > p3);
    EXPECT_TRUE(p1 >= p3);

    oss << p1;
    EXPECT_EQ(oss.str(), "(2,4)");
    oss.str("");
    oss << p2;
    EXPECT_EQ(oss.str(), "(1,-6)");
}

template <typename T>
void punto_test_real() {
    std::ostringstream oss;
    geocomp::Punto<T> p1(1.53, -14.08), p2(9.5, 3.17), p3(1.53, -14.08);

    EXPECT_LT(std::abs(p1.x() - 1.53),     0.001);
    EXPECT_LT(std::abs(p1.y() - (-14.08)), 0.001);
    EXPECT_LT(std::abs(p2.x() - 9.5),      0.001);
    EXPECT_LT(std::abs(p2.y() - 3.17),     0.001);

    EXPECT_TRUE(p1 == p1);
    EXPECT_FALSE(p1 == p2);
    EXPECT_FALSE(p2 == p3);
    EXPECT_TRUE(p1 == p3);

    EXPECT_FALSE(p1 != p1);
    EXPECT_TRUE(p1 != p2);
    EXPECT_TRUE(p2 != p3);
    EXPECT_FALSE(p1 != p3);

    geocomp::Punto<T> p4(7.44, 3.17);
    EXPECT_TRUE(p4 <  p2);
    EXPECT_TRUE(p4 <= p2);
    EXPECT_TRUE(p2 >  p4);
    EXPECT_TRUE(p2 >= p4);

    EXPECT_TRUE(p4 >  p1);
    EXPECT_TRUE(p4 >= p1);
    EXPECT_TRUE(p1 <  p4);
    EXPECT_TRUE(p1 <= p4);

    EXPECT_FALSE(p2 <  p1);
    EXPECT_FALSE(p2 <= p1);
    EXPECT_FALSE(p1 >  p2);
    EXPECT_FALSE(p1 >= p2);

    EXPECT_FALSE(p1 < p3);
    EXPECT_TRUE(p1 <= p3);
    EXPECT_FALSE(p1 > p3);
    EXPECT_TRUE(p1 >= p3);

    oss << p1;
    EXPECT_EQ(oss.str(), "(1.53,-14.08)");
    oss.str("");
    oss << p2;
    EXPECT_EQ(oss.str(), "(9.5,3.17)");
}

TEST(punto_test, punto_con_int) {
    punto_test_entero<int>();
}

TEST(punto_test, punto_con_long) {
    punto_test_entero<long>();
}

TEST(punto_test, punto_con_float) {
    punto_test_real<float>();
}

TEST(punto_test, punto_con_double) {
    punto_test_real<double>();
}
