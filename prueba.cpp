#include <vector>
#include <iostream>

using namespace std;

class cosito {
private:
    int num;
    bool state;

public:
    cosito() {
        num = 0;
        state = false;
        cout << "cosito creado." << endl;
    }

    cosito(const cosito &otro) {
        num = otro.num;
        state = otro.state;
        cout << "cosito copiado." << endl;
    }

    cosito(int n, bool s) {
        num = n;
        state = s;
        cout << "cosito creado con num y state." << endl;
    }

    cosito(int n) {
        num = n;
        state = false;
        cout << "cosito creado con num." << endl;
    }

    cosito(bool s) {
        num = 0;
        state = s;
        cout << "cosito creado con state." << endl;
    }

    ~cosito() {
        cout << "cosito eliminado." << endl;
    }
};

vector<cosito> crear(int num) {
    vector<cosito> v(4);
    cout << "v creado" << endl;
    vector<cosito> b(4);
    cout << "b creado" << endl;
    if (num % 2 == 0)
        return v;
    else
        return b;
}

int main(int argc, char**) {
    cout << "funcion llamada" << endl;
    vector<cosito> v = crear(argc);
    cout << "funcion finalizada" << endl;
    return 0;
}



