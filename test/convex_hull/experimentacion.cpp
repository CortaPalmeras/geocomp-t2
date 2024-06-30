#include <algorithm>
#include <chrono>
#include <fstream>
#include <gtest/gtest.h>
#include <vector>

#include "convex_hull_test.hpp"
#include "gift_wrapping.hpp"
#include "incremental.hpp"
#include "poligono.hpp"

using namespace geocomp;
using std::vector;
using hrclock = std::chrono::high_resolution_clock;

TEST(Experimentaicion, Random) {
    std::ofstream fout("random.csv");

    fout << "numero_puntos,t_gift_wrapping,t_incremental,t_incremental_nosort,"
         << "iguales,n_puntos_cupula_gw,n_puntos_cupula_inc" << std::endl;

    double a = -10;
    double b = 10;
    for (int n_puntos = 5000; n_puntos <= 200000; n_puntos += 5000) {
        std::cout << "Testeando con " << n_puntos << " puntos" << std::endl;

        for (int i = 0; i < 10; i++) {
            fout << n_puntos << ',';
            vector<Punto<double>> puntos =
                conjunto_prueba_random<double, double_dist>(a, b, n_puntos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_gw = gift_wrapping(puntos);
            auto fin = hrclock::now();
            std::chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            std::sort(puntos.begin(), puntos.end());

            inicio = hrclock::now();
            Poligono<double> cupula_inc_nosort = incremental(puntos, true);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            fout << (cupula_gw == cupula_inc) << ','
                 << cupula_gw.n_vertices() << ','
                 << cupula_inc.n_vertices() << std::endl;
        }
    }
    fout.close();
}

TEST(Experimentaicion, Radial) {
    std::ofstream fout("radial_cupulas_grandes.csv");

    fout << "numero_puntos,n_puntos_cupula,"
         << "t_gift_wrapping,t_incremental,"
         << "correcto_gw,correcto_inc" << std::endl;

    vector<int> cantidades_puntos;

    for (int i = 2500; i < 50000; i += 2500) {
        cantidades_puntos.push_back(i);
    }

    double r = 10;
    for (unsigned int i = 0; i < cantidades_puntos.size(); i++) {
        int n_puntos = cantidades_puntos[i];
        std::cout << "Testeando con " << n_puntos << " puntos" << std::endl;

        for (unsigned int j = 0; j <= i; j++) {
            int n_cupula = cantidades_puntos[j];
            int n_internos = n_puntos - n_cupula;

            fout << n_puntos << ',' << n_cupula << ',';
            vector<Punto<double>> puntos =
                conjunto_prueba_radial<double, double_dist>(r, n_cupula, n_internos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_gw = gift_wrapping(puntos);
            auto fin = hrclock::now();
            std::chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            Poligono<double> r_esperado = resultado_esperado_radial<double>(r, n_cupula);
            fout << (cupula_gw == r_esperado) << ','
                 << (cupula_inc == r_esperado) << std::endl;
        }
    }
    fout.close();
}

TEST(Experimentaicion, RadialIncremental) {
    std::ofstream fout("radial_incremental.csv");

    fout << "numero_puntos,n_puntos_cupula,"
         << "t_incremental,t_incremental_presort,"
         << "correcto_inc,correcto_incps" << std::endl;

    vector<int> cantidades_puntos;

    for (int i = 5000; i < 200000; i += 5000) {
        cantidades_puntos.push_back(i);
    }

    double r = 10;
    for (unsigned int i = 0; i < cantidades_puntos.size(); i++) {
        int n_puntos = cantidades_puntos[i];
        std::cout << "Testeando con " << n_puntos << " puntos" << std::endl;

        for (unsigned int j = 0; j <= i; j++) {
            int n_cupula = cantidades_puntos[j];
            int n_internos = n_puntos - n_cupula;

            fout << n_puntos << ',' << n_cupula << ',';
            vector<Punto<double>> puntos =
                conjunto_prueba_radial<double, double_dist>(r, n_cupula, n_internos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            auto fin = hrclock::now();
            std::chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            std::sort(puntos.begin(), puntos.end());

            inicio = hrclock::now();
            Poligono<double> cupula_incps = incremental(puntos, true);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            Poligono<double> r_esperado = resultado_esperado_radial<double>(r, n_cupula);

            fout << (cupula_inc == r_esperado) << ',' 
                 << (cupula_incps == r_esperado) << std::endl;
        }
    }
    fout.close();
}

TEST(Experimentaicion, RadialCupulasPequenas) {
    std::ofstream fout("radial_cupulas_pequenas.csv");

    fout << "numero_puntos,n_puntos_cupula,"
         << "t_gift_wrapping,t_incremental,"
         << "correcto_gw,correcto_inc" << std::endl;

    vector<int> cantidades_puntos;

    for (int i = 25; i <= 1000; i += 25) {
        cantidades_puntos.push_back(i);
    }

    double r = 10;
    for (unsigned int i = 0; i < cantidades_puntos.size(); i++) {
        int n_puntos = cantidades_puntos[i];
        std::cout << "Testeando con " << n_puntos << " puntos" << std::endl;

        for (unsigned int j = 0; j <= i; j++) {
            int n_cupula = cantidades_puntos[j];
            int n_internos = n_puntos - n_cupula;

            fout << n_puntos << ',' << n_cupula << ',';
            vector<Punto<double>> puntos =
                conjunto_prueba_radial<double, double_dist>(r, n_cupula, n_internos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_gw = gift_wrapping(puntos);
            auto fin = hrclock::now();
            std::chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            Poligono<double> r_esperado = resultado_esperado_radial<double>(r, n_cupula);
            fout << (cupula_gw == r_esperado) << ','
                 << (cupula_inc == r_esperado) << std::endl;
        }
    }
    fout.close();
}

