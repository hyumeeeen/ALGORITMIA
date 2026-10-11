#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

VI v;
int n;

void escriure() {
    for ( int i = 0; i < n; ++i ) {
        cout << ( i != 0 ? " " : "" ) << v[i];
        //si i es distinto de 0, devuelve espacio, sino devuelve nada
    }
    cout << endl;
}

void f( int i ) {

    if ( i == n ) return escriure();

    v[i] = 0;
    f(i + 1);
    v[i] = 1;
    f(i + 1);

}

int main() {
    
    cin >> n;
    v = VI(n);
    //datazo, si no pones, v de default es todo 0
    f(0);

}