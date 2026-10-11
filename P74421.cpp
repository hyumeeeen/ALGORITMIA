#include <iostream>
#include <vector>
using namespace std;

using ll = long long; 
using VL = vector<ll>;

int n;
int q;
//es ilegal hacer VL aux(n), antes de que leyera n
VL aux;
VL v;

ll f(int i) {
    
    if ( v[i] != 0 ) return v[i]; 
    if ( i <= 1 ) return aux[i];
    return v[i] += f(i - 1) + aux[i];

}

int main() {
    
    int count = 1;
    while ( cin >> n ) {

        aux = VL(n + 1);
        aux[0] = 0;
        v = VL(n + 1, 0);
        
        for ( int i = 1; i <= n; ++i ) cin >> aux[i];
        
        cin >> q;
        cout << "#" << count << endl;
        for ( int i = 0; i < q; ++i ) {
            int x, y;
            cin >> x >> y;
            if ( x > y ) swap(x, y);
            cout << f(y) - f(x - 1) << endl;
        }
        
        ++count;
    }

}