#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VL = vector<ll>;

const int N = 1000;
VL F;
ll n, m;

ll f(ll n) {
    //hay un arbol fractal aqui
    /*
    lo que hago es ir hasta el dinal de la primera rama
    voy subiendo hasta acabar el lado izquierdo
    ahora voy a hacer lado derecho
    pero ya guarde muchos valores 
    tq en el lado derecho, me ahorro todo, porque tengo ya f(n - 2)
    */
    if ( F[n] != -1 ) return F[n] % m;
    if ( n <= 1 ) return F[n] = n % m;
    return F[n] = ( f(n - 2) + f(n - 1) ) % m;
}


int main() {

    //no voy a crear una matriz de 1000 x 10^8
    while( cin >> n >> m ) {
        F = VL(n + 1, -1);
        cout << f(n) << endl;
    }

}

