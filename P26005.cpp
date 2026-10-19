#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;

string p1, p2;
int k, n, m;
VI c;
VII M;
VI c1, c2;
VI r1, r2;

int min3(int a, int b, int c) {
    
    if ( a <= b and a <= c ) return a;
    if ( b <= a and b <= c ) return b;
    return c;

}

int f(int i, int j) {

    if ( i >= n ) {
        if ( j < m ) return r2[j];
        return 0; 
    }

    if ( j >= m ) {
        if ( i < n ) return r1[i];
        return 0;
    }

    if ( M[i][j] != -1 ) return M[i][j];

    int res = 0;
    if ( p1[i] == p2[j] ) {
        res = f(i + 1, j + 1); 
        return M[i][j] = min3(res, c1[i] + f(i + 1, j), c2[j] + f(i, j + 1));
    }

    return M[i][j] = min(c1[i] + f(i + 1, j), c2[j] + f(i, j + 1));
    
}

int main() {

    while ( cin >> k ) {

        c = VI(k);
        for ( int i = 0; i < k; ++i ) cin >> c[i];
        
        cin >> p1 >> p2;
        
        n = p1.size();
        m = p2.size();
        
        c1 = VI(n);
        c2 = VI(m);
        r1 = VI(n, 0);
        r2 = VI(m, 0);

        for ( int i = 0; i < n; ++i ) {
            c1[i] = c[p1[i] - 'a'];
        } 
        for ( int i = 0; i < m; ++i ) {
            c2[i] = c[p2[i] - 'a'];
        }

        for ( int i = n - 1; i >= 0; --i ) {
            if ( i == n - 1 ) r1[i] = c1[i];
            else {
                r1[i] = c1[i] + r1[i + 1];
            }
        }
        for ( int i = m - 1; i >= 0; --i ) {
            if ( i == m - 1 ) r2[i] = c2[i];
            else {
                r2[i] = c2[i] + r2[i + 1];
            }
        }

        M = VII(n, VI(m, -1));
        
        cout << f(0, 0) << endl;

    }
    


}
