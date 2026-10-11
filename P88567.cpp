#include <iostream>
#include <vector>
using namespace std;

using ll = long long; 
using VL = vector<ll>;
using VLL = vector<VL>;
using VS = vector<string>;

int n, m;
VL ABC;
VS letra;
VLL aux;
VLL M;

ll a(int i) {

    if ( ABC[i] != 0 ) return ABC[i];
    if ( i == 0 ) return ABC[i] = 1;
    return ABC[i] += a(i - 1) + i + 1;

}

ll f(int i , int j) {

    if (i < 0 or j < 0 ) return 0;
    if ( i == 0 and j == 0 ) return M[i][j] = aux[i][j];
    if ( M[i][j] != 0 ) return M[i][j];
    return M[i][j] += aux[i][j] + f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);

}

int main() {
    
    ABC = VL(27, 0);
    a(26);
    
    string s;
    while ( cin >> s ) letra.push_back(s);
    
    n = letra.size();
    m = s.size();
    aux = VLL(n, VL(m));
    M = VLL(n, VL(m));
    
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) aux[i][j] = ABC[letra[i][j] - 'A'];
    }

    f(n - 1, m - 1);
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) {
            cout << ( j != 0 ? " " : "" ) << M[i][j];
        }
        cout << endl;
    }

}