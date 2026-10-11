#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VCC = vector<VC>;
using VI = vector<int>;
using VII = vector<VI>;

int n, total;
VCC M;
VII ocupado;
VI dx = {0, 0, 1, -1, 1, 1, -1, -1};
VI dy = {-1, 1, 0, 0, 1, -1, 1, -1};

void escriure() {
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) cout << M[i][j];
        cout << endl;
    }
    cout << "----------" << endl; 
}

void ocupar(int i, int j, int u) {

    for ( int k = 0; k < 8; ++k ) {
        int x = i + dx[k];
        int y = j + dy[k];
        if ( x < n and y < n and y >= 0 and x >= 0 ) ocupado[x][y] += u;
    }
    
}

void f(int i, int j, int count) {

    if ( count == total ) return escriure();
    if ( count > total or i >= n ) return;
    if ( j == n ) return f(i + 1, 0, count);
    // si no pongo un return arriba, significa que seguira ejecutandose con las lineas de abajo

    if ( ocupado[i][j] == 0 ) {
        
        M[i][j] = 'K';
        ++ocupado[i][j];
        ocupar(i, j, 1);
        
        f(i, j + 1, count + 1);
        
        M[i][j] = '.';
        --ocupado[i][j];
        ocupar(i, j, -1);
        //no pudo hacer la misma estructura de BOOL de toda la vida porque cuando quito un rey
        //y quito TODO su alrededor, estoy ignorando lo que hace otros reys
        //por eso tengo que poner int, para contar cuantas veces lo quito
    
    }
    f(i, j + 1, count);
    
}

int main() {
    
    cin >> n >> total;
    M = VCC(n, VC(n, '.'));
    ocupado = VII(n, VI(n, 0));
    f(0, 0, 0);

}