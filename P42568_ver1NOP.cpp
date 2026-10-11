#include <iostream>
#include <vector>
using namespace std;

struct ok{
    char a;
    bool y;
};

using VC = vector<char>;

VC vowel;
vector<ok> abc;
VC solucion;

int n, v, x;

void escriure() {
    for ( int i = 0; i < n; ++i ) cout << solucion[i];
    cout << endl;
}

void f(int i, int nv, int nc) {
    
    if ( i > 1 and i <= n and solucion[i - 2] != ' ' and solucion[i - 1] != ' ' ) {
        int p = solucion[i - 1] - 'a';
        int q = solucion[i - 2] - 'a';
        if ( !abc[p].y and !abc[q].y ) return;
    }

    if ( nv > v or nc > n - v ) return;
    if ( i == n ) return escriure();

    for ( int k = 0; k < x; ++k ) {
        solucion[i] = abc[k].a;
        if ( abc[k].y == true ) f(i + 1, nv + 1, nc);
        else f(i + 1, nv, nc + 1);
        solucion[i] = ' ';   
    }

}

int main() {
    cin >> n >> v >> x;
    
    abc = vector<ok>(26, {' ', false});
    vowel = VC{'a', 'e', 'i', 'o', 'u'};
    solucion = VC(n, ' ');
    
    int j = 0;
    for ( int i = 0; i < 26; ++i ) {
        abc[i].a = 'a' + i;
        if ( j < 5 and 'a' + i == vowel[j] ) {
            ++j;
            abc[i].y = true;
        }
    }

    f(0, 0, 0);
}