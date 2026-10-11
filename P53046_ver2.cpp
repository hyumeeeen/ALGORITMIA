#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int n;
VI v;
VB usado;

void escriure() {
    cout << "(";
    bool primero = true;
    for ( int i = 1; i < n + 1; ++i ) {
        if ( primero ) primero = false;
        else cout << ",";
        cout << v[i];
    }
    cout << ")" << endl;
}

void f(int cur, int i) {
    
    //voy saltando, asi no tengo que preocuparme por ir a un sitio incorrecto
    if ( i == n ) {
        v[cur] = 1;
        return escriure();
    }
    //pregunta, porque no puede pasar que en la poscion 3 de v sea el numero 3
    //porque vamos en orden y vamos usando los numeros
    //para llegar a la posicion 3 necesito usar el numero 3
    //asi voy evitando hasta que solo me quede un sitio para rellenar, donde pongo numero 1 
    //la logica del problema es cerrar el ciclo, cuando vuelvo a la primera posicion, lo he cerrado!!!!!
    for ( int k = 2; k < n + 1; ++k ) {
        if ( !usado[k] ) {
            v[cur] = k;
            usado[k] = true;
            f(k, i + 1);
            usado[k] = false;
        }
    }
    
}

int main() {
    cin >> n;
    v = VI(n + 1);
    usado = VB(n + 1);
    f(1, 1);
}