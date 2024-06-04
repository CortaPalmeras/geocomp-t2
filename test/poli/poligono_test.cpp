
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

#include "poligono.hpp"
#include "punto.hpp"

template <typename T>
void poligono_test_entero() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(2, 1), p2(3, -2), p3(3, 5), p4(-3, 4), p5(0, 2), p6(-1, -3);
    std::vector<geocomp::Punto<T>> v1({p1, p2, p3, p4, p5, p6});
    std::vector<geocomp::Punto<T>> v2({p2, p3, p4});
    std::vector<geocomp::Punto<T>> v3({p6, p5, p1, p2});
    geocomp::Poligono<T> pol1(v1), pol2(v2), pol3(v3);

    EXPECT_EQ(pol1.n_vertices(), 6);
    EXPECT_EQ(pol2.n_vertices(), 3);
    EXPECT_EQ(pol3.n_vertices(), 4);

    EXPECT_TRUE(pol1.es_ccw());
    EXPECT_TRUE(pol2.es_ccw());
    EXPECT_FALSE(pol3.es_ccw());

    EXPECT_EQ(pol1[0].x(), 2);
    EXPECT_EQ(pol1[1].x(), 3);
    EXPECT_EQ(pol1[2].x(), 3);
    EXPECT_EQ(pol1[3].x(), -3);
    EXPECT_EQ(pol1[4].x(), 0);
    EXPECT_EQ(pol1[5].x(), -1);

    EXPECT_EQ(pol1[0].y(), 1);
    EXPECT_EQ(pol1[1].y(), -2);
    EXPECT_EQ(pol1[2].y(), 5);
    EXPECT_EQ(pol1[3].y(), 4);
    EXPECT_EQ(pol1[4].y(), 2);
    EXPECT_EQ(pol1[5].y(), -3);

    EXPECT_FALSE(pol1.es_convexo());
    EXPECT_TRUE(pol2.es_convexo());
    EXPECT_TRUE(pol3.es_convexo());

    std::vector<geocomp::Punto<T>> v4({p1, p2, p3, p4, p5, p6});
    geocomp::Poligono<T> pol4(v1);
    EXPECT_TRUE(pol1 == pol1);
    EXPECT_TRUE(pol1 == pol4);
    EXPECT_TRUE(pol2 == pol2);
    EXPECT_FALSE(pol1 == pol2);
    EXPECT_FALSE(pol2 == pol4);
    EXPECT_FALSE(pol3 == pol1);

    EXPECT_FALSE(pol1 != pol1);
    EXPECT_FALSE(pol1 != pol4);
    EXPECT_FALSE(pol2 != pol2);
    EXPECT_TRUE(pol1 != pol2);
    EXPECT_TRUE(pol2 != pol4);
    EXPECT_TRUE(pol3 != pol1);

    oss << pol1;
    EXPECT_EQ(oss.str(), "[(2,1),(3,-2),(3,5),(-3,4),(0,2),(-1,-3)]");
    oss.str("");

    oss << pol2;
    EXPECT_EQ(oss.str(), "[(3,-2),(3,5),(-3,4)]");
    oss.str("");

    oss << pol3;
    EXPECT_EQ(oss.str(), "[(-1,-3),(0,2),(2,1),(3,-2)]");
}

template <typename T>
void poligono_test_real() {
    std::ostringstream oss;

    geocomp::Punto<T> p1(2.29, 1.84), p2(3.65, -2.38), p3(3.07, 5.11), p4(-3.9, 4.41), p5(0, 2.22),
        p6(-1.76, -3.82);

    std::vector<geocomp::Punto<T>> v1({p1, p2, p3, p4, p5, p6});
    std::vector<geocomp::Punto<T>> v2({p2, p3, p4});
    std::vector<geocomp::Punto<T>> v3({p6, p5, p1, p2});

    geocomp::Poligono<T> pol1(v1), pol2(v2), pol3(v3);

    EXPECT_EQ(pol1.n_vertices(), 6);
    EXPECT_EQ(pol2.n_vertices(), 3);
    EXPECT_EQ(pol3.n_vertices(), 4);

    EXPECT_EQ(pol1.es_ccw(), true);
    EXPECT_EQ(pol2.es_ccw(), true);
    EXPECT_EQ(pol3.es_ccw(), false);

    EXPECT_TRUE(std::abs(pol1[0].x() - 2.29) < 0.01);
    EXPECT_TRUE(std::abs(pol1[1].x() - 3.65) < 0.01);
    EXPECT_TRUE(std::abs(pol1[2].x() - 3.07) < 0.01);
    EXPECT_TRUE(std::abs(pol1[3].x() - -3.9) < 0.01);
    EXPECT_TRUE(std::abs(pol1[4].x() - 0.0) < 0.01);
    EXPECT_TRUE(std::abs(pol1[5].x() - -1.76) < 0.01);

    EXPECT_TRUE(std::abs(pol1[0].y() - 1.84) < 0.01);
    EXPECT_TRUE(std::abs(pol1[1].y() - -2.38) < 0.01);
    EXPECT_TRUE(std::abs(pol1[2].y() - 5.11) < 0.01);
    EXPECT_TRUE(std::abs(pol1[3].y() - 4.41) < 0.01);
    EXPECT_TRUE(std::abs(pol1[4].y() - 2.22) < 0.01);
    EXPECT_TRUE(std::abs(pol1[5].y() - -3.82) < 0.01);

    std::vector<geocomp::Punto<T>> v4({p1, p2, p3, p4, p5, p6});
    geocomp::Poligono<T> pol4(v1);
    EXPECT_TRUE(pol1 == pol1);
    EXPECT_TRUE(pol1 == pol4);
    EXPECT_TRUE(pol2 == pol2);
    EXPECT_FALSE(pol1 == pol2);
    EXPECT_FALSE(pol2 == pol4);
    EXPECT_FALSE(pol3 == pol1);

    EXPECT_FALSE(pol1 != pol1);
    EXPECT_FALSE(pol1 != pol4);
    EXPECT_FALSE(pol2 != pol2);
    EXPECT_TRUE(pol1 != pol2);
    EXPECT_TRUE(pol2 != pol4);
    EXPECT_TRUE(pol3 != pol1);

    oss << pol1;
    EXPECT_EQ(oss.str(), "[(2.29,1.84),(3.65,-2.38),(3.07,5.11),"
                         "(-3.9,4.41),(0,2.22),(-1.76,-3.82)]");
    oss.str("");

    oss << pol2;
    EXPECT_EQ(oss.str(), "[(3.65,-2.38),(3.07,5.11),(-3.9,4.41)]");
    oss.str("");

    oss << pol3;
    EXPECT_EQ(oss.str(), "[(-1.76,-3.82),(0,2.22),(2.29,1.84),(3.65,-2.38)]");
}

TEST(poligono_test, poligono_con_int) {
    poligono_test_entero<int>();
}

TEST(poligono_test, poligono_con_long) {
    poligono_test_entero<long>();
}

TEST(poligono_test, poligono_con_float) {
    poligono_test_real<float>();
}

TEST(poligono_test, poligono_con_double) {
    poligono_test_real<double>();
}
