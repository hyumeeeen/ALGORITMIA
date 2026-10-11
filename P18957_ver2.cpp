#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;

int n;
VS palabras;
VS almacen;

void escriure(int count) {  
    cout << "{";
    for ( int i = 0; i < n; ++i ) {
        if ( almacen[i] != "" ) {
            cout << almacen[i];
            --count;
            if ( count > 0 ) cout << ",";     
        }
    }
    cout << "}" << endl;
}
//muy feo, y vamos a recordar que podemos poner comas al principio XD
//vamos a ver3

void f(int i, int count) {
    if ( i == n ) return escriure(count);
    almacen[i] = "";
    f(i + 1, count);
    almacen[i] = palabras[i];
    f(i + 1, count + 1);
    //push_back no hace efecto porque estoy usando el mismo vector en todas estas llamadas
}

int main() {
    cin >> n;
    palabras = VS(n);
    almacen = VS(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> palabras[i];
    }
    f(0, 0);
}