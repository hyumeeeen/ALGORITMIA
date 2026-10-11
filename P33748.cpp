#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VI = vector<int>;

int m, n;
VS palabra;
VI v;

void escriure() {

    bool primero = true;
    cout << "{";
    for ( int i = 0; i < n; ++i ) { 
        if ( v[i] ) {
            if ( primero ) primero = false;
            else cout << ",";
            cout << palabra[i];
        }
    }
    cout << "}" << endl;

}

void f(int i, int u, int p) {

    if ( u < 0 or p < 0) return;
    if ( i == n ) return escriure();

    v[i] = 0;
    f(i + 1, u, p - 1);
    v[i] = 1;
    f(i + 1, u - 1, p);

}

int main() {
    cin >> m >> n;
    v = VI(n);
    palabra = VS(n);
    for ( int i = 0; i < n; ++i ) cin >> palabra[i];
    f(0, m, n - m);
}