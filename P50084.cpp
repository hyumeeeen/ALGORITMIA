#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
VI num;
VB esp;
long long n;

//me ha dado time limit exceeded por power creo
//y tambien tengo que cambiar las cosas a long long wait me

long long potencia(int p) {
    long long e = 1;
    for ( int i = 0; i < p; ++i ) {
        e *= 10;
    }
    return e;
}

long long calcular(int i) {

    int k = i - 1;
    int p = 1;
    long long suma = num[i];
    while ( k >= 0 and !esp[k] ) {
        suma += num[k] * potencia(p);
        ++p;
        --k; 
    }

    return suma;

}

void escriure(int& x) {
    cout << n << " = "; 
    for ( int i = 0; i < x; ++i ) {
        cout << num[i];
        if ( i < x - 1 ) {
            if ( esp[i] ) cout << ' ' << "+" << ' ';
        }
    }
    cout << endl;
}

void f(int& x, int i, long long count, bool& respuesta) {

    if ( count > n ) return;
    if ( i == x - 1 ) {
        if ( count + calcular(i) == n ) {
            respuesta = true;
            return escriure(x);
        } 
        return;
    }

    esp[i] = true;
    f(x, i + 1, count + calcular(i), respuesta);
    esp[i] = false;
    f(x, i + 1, count, respuesta);
    
}

int main() {
    while( cin >> n ) {
        string s;
        cin >> s;
        int x = s.size();
        num = VI(x);
        esp = VB(x - 1, false);
        for ( int i = 0; i < x; ++i ) {
            num[i] = s[i] - '0';
        }

        bool respuesta = false;
        f(x, 0, 0, respuesta);
        if ( !respuesta ) {
            cout << "No solution for " << n << " " << s << "." << endl;
        }
    }
}