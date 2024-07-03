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
using namespace std;
using hrclock = chrono::high_resolution_clock;

void test_radial(ofstream& fout, const vector<int>& cantidades_puntos_total,
                 const vector<int>& cantidades_puntos_cupula) {
    fout << "numero_puntos,n_puntos_cupula,"
         << "t_gift_wrapping,t_incremental,t_incremental_nosort,"
         << "correcto_gw,correcto_inc,correcto_incns" << endl;

    double r = 10;
    for (int n_puntos : cantidades_puntos_total) {
        cout << "Testeando con " << n_puntos << " puntos" << endl;

        for (int n_cupula : cantidades_puntos_cupula) {
            if (n_puntos < n_cupula) {
                break;
            }

            fout << n_puntos << ',' << n_cupula << ',';

            int n_internos = n_puntos - n_cupula;
            vector<Punto<double>> puntos =
                conjunto_prueba_radial<double, double_dist>(r, n_cupula, n_internos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_gw = gift_wrapping(puntos);
            auto fin = hrclock::now();
            chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            sort(puntos.begin(), puntos.end());

            inicio = hrclock::now();
            Poligono<double> cupula_incns = incremental(puntos, true);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            Poligono<double> r_esperado = resultado_esperado_radial<double>(r, n_cupula);
            fout << (cupula_gw == r_esperado) << ',' << (cupula_inc == r_esperado) << ','
                 << (cupula_incns == r_esperado) << endl;
        }
    }
}

TEST(Experimentaicion, RadialGrande) {
    ofstream fout("radial_grande.csv");

    vector<int> cantidades_puntos_total;
    for (int i = 2500; i <= 50000; i += 2500) {
        cantidades_puntos_total.push_back(i);
    }

    test_radial(fout, cantidades_puntos_total, cantidades_puntos_total);
    fout.close();
}

TEST(Experimentaicion, RadialPequeno) {
    ofstream fout("radial_pequeno.csv");

    vector<int> cantidades_puntos_total;
    for (int i = 100; i <= 1000; i += 100) {
        cantidades_puntos_total.push_back(i);
    }

    vector<int> cantidades_puntos_cupula;
    for (int i = 10; i <= 1000; i += 10) {
        cantidades_puntos_cupula.push_back(i);
    }

    test_radial(fout, cantidades_puntos_total, cantidades_puntos_cupula);
    fout.close();
}

TEST(Experimentaicion, RadialCupulasPequenas) {
    ofstream fout("radial_cupulas_pequenas.csv");

    vector<int> cantidades_puntos_total;
    for (int i = 5000; i <= 100000; i += 5000) {
        cantidades_puntos_total.push_back(i);
    }

    vector<int> cantidades_puntos_cupula;
    for (int i = 100; i <= 1000; i += 100) {
        cantidades_puntos_cupula.push_back(i);
    }

    test_radial(fout, cantidades_puntos_total, cantidades_puntos_cupula);
    fout.close();
}

TEST(Experimentaicion, Random) {
    ofstream fout("random.csv");

    fout << "numero_puntos,t_gift_wrapping,t_incremental,t_incremental_nosort,"
         << "igual_gw_inc,igual_gw_incns,igual_inc_incns,"
         << "n_cupula_gw,n_cupula_inc,n_cupula_incns" << endl;

    double a = -10;
    double b = 10;
    for (int n_puntos = 5000; n_puntos <= 200000; n_puntos += 5000) {
        cout << "Testeando con " << n_puntos << " puntos" << endl;

        for (int i = 0; i < 10; i++) {
            fout << n_puntos << ',';
            vector<Punto<double>> puntos =
                conjunto_prueba_random<double, double_dist>(a, b, n_puntos);

            auto inicio = hrclock::now();
            Poligono<double> cupula_gw = gift_wrapping(puntos);
            auto fin = hrclock::now();
            chrono::duration<double> dif = fin - inicio;
            fout << dif.count() << ',';

            inicio = hrclock::now();
            Poligono<double> cupula_inc = incremental(puntos, false);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            sort(puntos.begin(), puntos.end());

            inicio = hrclock::now();
            Poligono<double> cupula_incns = incremental(puntos, true);
            fin = hrclock::now();
            dif = fin - inicio;
            fout << dif.count() << ',';

            fout << (cupula_gw == cupula_inc) << ',' << (cupula_gw == cupula_incns) << ','
                 << (cupula_inc == cupula_incns) << ',' << cupula_gw.n_vertices() << ','
                 << cupula_inc.n_vertices() << ',' << cupula_incns.n_vertices() << endl;
        }
    }
    fout.close();
}
