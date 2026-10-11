#include <iostream>
#include <vector>
using namespace std;

struct ok{
    char a;
    bool y;
};
struct ok2{
    char a;
    int y;
};

using VC = vector<char>;

vector<ok2> vowel;
vector<ok> abc;
VC solucion;

int n, v, x;

void escriure() {
    for ( int i = 0; i < n; ++i ) cout << solucion[i];
    cout << endl;
}

void f(int i, int nv, int nc, bool cons) {
    
    if ( nv < 0 or nc < 0 ) return;
    if ( i == n ) return escriure();
    if ( ( n - i ) - nv > nv + 1 ) return;

    if ( cons ) {
        
        for ( int k = 0; k < 5; ++k ) {
            if ( vowel[k].y >= x ) return;
            else solucion[i] = vowel[k].a;
            f(i + 1, nv - 1, nc, false);
        }

    } else {
        
        for ( int k = 0; k < x; ++k ) {
            solucion[i] = abc[k].a;
            if ( abc[k].y == true ) f(i + 1, nv - 1, nc, false);
            else f(i + 1, nv, nc - 1, true);   
        }

    }
    
}

int main() {
    cin >> n >> v >> x;
    
    abc = vector<ok>(26, {' ', false});
    vowel = vector<ok2>{
        {'a', 'a' - 'a'},
        {'e', 'e' - 'a'},
        {'i', 'i' - 'a'},
        {'o', 'o' - 'a'},
        {'u', 'u' - 'a'},
    };
    solucion = VC(n, ' ');
    
    int j = 0;
    for ( int i = 0; i < 26; ++i ) {
        abc[i].a = 'a' + i;
        if ( j < 5 and i == vowel[j].y ) {
            ++j;
            abc[i].y = true;
        }
    }

    f(0, v, n - v, false);
}