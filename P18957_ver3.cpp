#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VB = vector<bool>;

int n;
VS palabras;
VB almacen;

void escriure() {  
    cout << "{";
    bool primero = true;
    for ( int i = 0; i < n; ++i ) {
        if ( almacen[i] ) {
            if ( primero ) primero = false;
            else cout << ",";
            cout << palabras[i];
        }
    }
    cout << "}" << endl;
}


void f(int i) {

    if ( i == n ) return escriure();

    almacen[i] = false;
    f(i + 1);
    almacen[i] = true;
    f(i + 1);

}

int main() {
    cin >> n;
    palabras = VS(n);
    almacen = VB(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> palabras[i];
    }
    f(0);
}