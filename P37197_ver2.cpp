#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VBB = vector<vector<bool>>;
int n, m;
vector<bool> usado;
VC v;
vector<int> idx;
VC show;
VBB M;

int asignar(char a) {
    if ( isupper(a) ) return a - 'A' + 26;
        else return a - 'a';    
}

void escriure() {
    for ( int i = 0; i < n; ++i ) cout << show[i];
    cout << endl;
    return;
}

void f(int i) {
    
    if ( i == n ) return escriure();

    for ( int k = 0; k < n; ++k ) {
        int x = idx[k];
        if ( !usado[x]) {
            if ( i == 0 ) {
                usado[x] = true;
                show[i] = v[k];
                f(i + 1);
                usado[x] = false;
            }
            else if ( !M[asignar(show[i - 1])][x] ) {
                usado[x] = true;
                show[i] = v[k];
                f(i + 1);
                usado[x] = false;
            }
        } 
    }
}



int main() {
    cin >> n;
    v = VC(n);
    idx = vector<int>(n);
    show = VC(n);
    usado = vector<bool>(52, false);
    M = VBB(52, vector<bool>(52, false));
    
    for ( int i = 0; i < n; ++i ) {
        cin >> v[i];
        idx[i] = asignar(v[i]);
    }
    
    cin >> m;
    char a, b;
    for ( int i = 0; i < m; ++i ) {    
        cin >> a >> b;
        int x, y;
        x = asignar(a);
        y = asignar(b);
        M[x][y] = M[y][x] = true;
    }
    f(0);
} 