#include <iostream>
#include <vector>
using namespace std;

int N = 1e7;
using VI = vector<int>;
using VB = vector<bool>;
int n;
VI num;
VI v;
VB usado;

int f(int i) {

    
    if ( i == n ) return 1;
    if ( i > 0 and v[i - 1] < v[i] ) return 0;
    
    int suma = 0;
    for ( int k = 0; k < n; ++k ) {
        if ( !usado[k] ) {
            usado[k] = true;
            v[i] = num[k];
            suma += f(i + 1);
            usado[k] = false;
            v[i] = 0;
        }
    }

    return suma;

}

int main() {

    while ( cin >> n ) {
        v = VI(n, 0);
        num = VI(n);
        usado = VB(n, false);
        for ( int i = 0; i < n; ++i ) cin >> num[i]; 
        cout << f(0) << endl;
    } 

}
