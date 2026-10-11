#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VCC = vector<VC>;
using VB = vector<bool>;
using VBB = vector<VB>;

int n, m;
VCC M;
VBB usado;
VC sol;
vector<int> v;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void escriure() {
    for ( auto x : sol ) cout << x;
    cout << endl;
}

bool check(int i, int j) {
    if ( i >= n or i < 0 or j >= m or j < 0 ) return false;
    return true;
}

void f(int i, int j) {
    
    if ( !check(i, j) ) return;
    if ( i == v[2] and j == v[3] ) {
        sol.push_back(M[i][j]);
        escriure();
        sol.pop_back();
        return;
    }

    for ( int k = 0; k < 4; ++k ) {

        if ( !usado[i][j] ) {
            usado[i][j] = true;
            sol.push_back(M[i][j]);
            f(i + dx[k], j + dy[k]);
            usado[i][j] = false;
            sol.pop_back();
        }
        
    }

}


int main() {
    cin >> n >> m;

    M = VCC(n, VC(m));
    usado = VBB(n, VB(m, false));
    
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m; ++j ) cin >> M[i][j];
    }

    int x;
    for ( int k = 0; k < 4; ++k ) {
        cin >> x; 
        v.push_back(x); 
    }

    f(v[0], v[1]);

}