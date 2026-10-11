#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;
using VB = vector<bool>;
using VBB = vector<VB>;

VBB ocupado;
VII pieza;
VB p_usada;
VII pintar;
int n, m, r;

bool poder(int i, int j, int k) {

    int dx = pieza[0][k];
    int dy = pieza[1][k];

    if ( i + dx - 1 >= n or j + dy - 1 >= m ) return false;
    
    for ( int o = 0; o < dx; ++o ) {
        for ( int p = 0; p < dy; ++p ) {
            if ( ocupado[i + o][j + p] ) return false;
        } 
    }

    return true;

}

//lol, se me olvido chekcear que a demas de que no se salga, 
//que no tenga nada icupado por donde vaya a ocupar
void ocupar(int i, int j, int k, bool u) {

    int dx = pieza[0][k];
    int dy = pieza[1][k];

    
    for ( int o = 0; o < dx; ++o ) {
        for ( int p = 0; p < dy; ++p ) {
            ocupado[i + o][j + p] = u;
        } 
    }

}

int f(int i, int j, int count) {

    if ( count == r ) {
        return 1;
    }

    if ( j == m ) return f(i + 1, 0, count);
    if ( i == n ) return 0;

    int suma = 0;

    if ( ocupado[i][j] ) return f(i, j + 1, count); 

    for ( int k = 0; k < r; ++k ) {
        
        if ( !p_usada[k] ) {
            
            if ( poder(i, j, k) ) {

                ocupar(i, j, k, true);
                p_usada[k] = true;
                suma += f(i, j + 1, count + 1);
                p_usada[k] = false;
                ocupar(i, j, k, false);
            
            } 
        
        }

    }

    return suma;

}

int main() {

    int i = 1;
    while ( cin >> n >> m >> r ) {
        
        ocupado = VBB(n, VB(m, false));
        pintar = VII(n, VI(m, -1));
        pieza = VII(2, VI(r));
        p_usada = VB(r, false);
        for ( int i = 0; i < r; ++i ) {
            cin >> pieza[0][i];
            cin >> pieza[1][i];
        }

        cout << "#" << i << ": ";
        cout << f(0, 0, 0) << endl;
        ++i;

    }

}