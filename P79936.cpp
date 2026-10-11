#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;
VII M;
VII U;
VI cd(2);
int w, h, c, k;


int f(int i, int j, int& sol) {

    if ( i < 0 or j < 0 ) return 0;
    if ( U[i][j] != -1 ) return U[i][j];

    U[i][j] = M[i][j] + f(i, j - 1, sol) + f(i - 1, j, sol) - f(i - 1, j - 1, sol);
    
    //es verdad que no recorro en orden las cosas
    int res = U[i][j] - f(i, j - c, sol) - f(i - c, j, sol) + f(i - c, j - c, sol);
    if ( res > sol and i - k >= 0 and j - k >= 0) {
        cd = {i - k, j - k};
        sol = res;
    }

    return U[i][j];
    
}

int main() {
    
    cin >> w >> h >> c;
    k = c - 1;
    M = VII(h, VI(w));    
    U = VII(h, VI(w, -1));
    for ( int i = 0; i < h; ++i ) {
        for ( int j = 0; j < w; ++j ) cin >> M[i][j]; 
    }

    U[0][0] = M[0][0];

    int sol = U[0][0];
    f(h - 1, w - 1, sol);
    cout << cd[0] << " " << cd[1] << endl;

}