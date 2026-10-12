#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VL = vector<ll>;
using VLL = vector<VL>;

int n, m;
VLL M(26, VL(26, -1));

ll f(int i, int j) {
    
    if ( i == -3 ) return 1;
    if ( i <= 0 ) return 0; 
    if ( M[i][j] != -1 ) return M[i][j];
    if ( i % 2 == 0 ) return M[i][j] = 0;
    if ( i < 6 ) return M[i][j] = j;

    ll res = 0;
    for ( int p = 1; p <= n - 2; ++p ) {
        res += f(p, j) * f(n - 5 - p, j);
    }

    return M[i][j] = res;

}

int main() {
    
    while ( cin >> n >> m ) {
        cout << f(n, m) << endl;
    }

}
