#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;

VI v;
VL sol;
string s;

ll f(int i) {

    if ( i == 0 ) return sol[i] = 0;
    if ( sol[i] != -1 ) return sol[i];

    ll prev = f(i - 1);
    ll acaban = 0;
    for ( int p = i - 1; p >= 0; --p ) {
        if ( v[i] > v[p] ) acaban += sol[p] + 1;
    }

    sol[i] = acaban;
    return acaban + prev;
    //aqui hay que diferenciar dos cosas, una cosa es la sol y otra f(i)
    // f(i) nos da la cantidad de palabras crecientes que hay hasta la posicion i
    // sol[i] nos da la cantidad de palabras crecientes que terminan en i
    
}

int main() {

    while ( cin >> s ) {
        
        int n = s.size();
        //no se porque siempre pongo VI v(n), y esto es una variable local, pero en mi f uso la v de variable global.
        v = VI(n);
        for ( int i = 0; i < n; ++i ) {
            int x = s[i] - 'a'; 
            v[i] = x;
        }

        sol = VL(n, -1);
        cout << f(n - 1) << endl;

    }


}
