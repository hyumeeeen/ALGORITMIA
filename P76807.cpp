#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;
using VBB = vector<VB>;
using VBBB = vector<VBB>;
using VI = vector<int>;
using VII = vector<VI>;

VI asignacion;
VBB fila;
VBB columna;
VBBB cuad;
VII M;

void cuadrante(VI& v) {
    for ( int k = 0; k < 3; ++k ) {
        for ( int i = 3 * k; i < 3 + k * 3; ++i ) v[i] = k;
    }
}

//aqui x es de 1 a 9
void use(int i, int j, int x) {
    fila[i][x] = true;
    columna[j][x] = true;
    int n = asignacion[i];
    int m = asignacion[j];
    cuad[n][m][x] = true;
}

void un_use(int i, int j, int x) {
    fila[i][x] = false;
    columna[j][x] = false;
    int n = asignacion[i];
    int m = asignacion[j];
    cuad[n][m][x] = false;
}
//aqui x es de 1 a 9
bool check(int i, int j, int x) {
    if ( fila[i][x] or columna[j][x] or cuad[asignacion[i]][asignacion[j]][x] ) return false;
    return true;
}

void escriure() {
    for ( int i = 0; i < 9; ++i ) {
        bool primero = true;
        for ( int j = 0; j < 9; ++j ) {
            if ( primero ) primero = false;
            else cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}

bool f(int i, int j) {
    
    if ( i >= 9 ) {
        escriure();
        return true;
    }
    //necesito poner return f(i + 1, 0) para no seguir las operaciones siguentes con j >= 9.
    if ( j == 9 ) return f(i + 1, 0);
   
    //si en la M_original ya estaba, return f..., para no proseguir con las siguientes operaciones
    if ( M[i][j] != 0 ) return f(i, j + 1);

    for ( int k = 1; k <= 9; ++k ) {
        if ( check(i, j, k - 1) ) {
            use(i, j, k - 1);
            M[i][j] = k;
            //si la rama que entro es correcta
            if ( f(i, j + 1) ) return true;
            // si la rama donde he entrado devuelve falso al final,
            //deshago el hecho, y sigo con la k
            un_use(i, j, k - 1);
            M[i][j] = 0;
        }
    }
    
    return false;
    
}

int main() {

    int n;
    cin >> n;
    cout << n << endl;

    asignacion = VI(9);
    cuadrante(asignacion);
    for ( int p = 0; p < n; ++p ) {
        
        cout << endl;
        M = VII(9, VI(9, 0));
        fila = VBB(9, VB(9, false));
        columna = VBB(9, VB(9, false));
        cuad = VBBB(3, VBB(3, VB(9, false)));

        char c;
        for ( int i = 0; i < 9; ++i ) {
            for ( int j = 0; j < 9; ++j ) {
                cin >> c;
                if ( isdigit(c) ) {
                    int x = c - '0';
                    M[i][j] = x;
                    use(i, j, x - 1);
                }
            }
        }
        f(0, 0);
    }


}