#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VSS = vector<VS>;
using VI = vector<int>;

int n, p;
VS palabra;
VSS M;
VI posicion;


void escriure() {
    for ( int i = 0; i < p; ++i ) {
        cout << "subset " << i + 1 << ": ";
        cout << "{";
        bool primero = true;
        for ( int j = 0; j < n; ++j ) {
            if ( M[i][j] != "" ) {
                if ( primero ) primero = false;
                else cout << ",";
                cout << M[i][j];    
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
    return;
}

void f(int i) {

    if ( i == n ) return escriure();

    for ( int k = 0; k < p; ++k ) {
        M[k][i] = palabra[i];
        f(i + 1);
        M[k][i] = "";
    }


}

int main() {
    cin >> n;
    palabra = VS(n);
    posicion = VI(n);
    for ( int i = 0; i < n; ++i ) cin >> palabra[i];
    cin >> p;
    M = VSS(p, VS(n));
    f(0);
}