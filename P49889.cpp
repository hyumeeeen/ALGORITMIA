#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using VB = vector<bool>;

VC v;
VC cons;
VC vow;
VB usado_c;
VB usado_v;

int n;
void escriure() {
    for ( int i = 0; i < 2 * n; ++i ) cout << v[i];
    cout << endl;
}

void leer(VC& a) {
    for ( int i = 0; i < n; ++i ) cin >> a[i];
}

void f(int i) {

    if ( i == 2 * n ) return escriure();

    for ( int k = 0; k < n; ++k ) {
        if ( i % 2 == 0 ) {
            if ( !usado_c[k] ) {
                usado_c[k] = true;
                v[i] = cons[k];
                f(i + 1);
                usado_c[k] = false;
            }    
        } 
        if ( i % 2 == 1) {
            if ( !usado_v[k] ) {
                usado_v[k] = true;
                v[i] = vow[k];
                f(i + 1);
                usado_v[k] = false;
            }    
        }
        
    }      
}



int main() {
    cin >> n;
    cons = VC(n);
    vow = VC(n);
    leer(cons);
    leer(vow);

    v = VC(2 * n);
    usado_c = VB(n, false);
    usado_v = VB(n, false);

    f(0);

}