#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;
int n;
int const N = 500001;
VI v(N, -1);
VI ok = {1, 5, 8, 14};

int f(int i) {
    
    if ( v[i] != -1 ) return v[i];
    
    int res = N;
    for ( int k = 0; k < 4 and i > ok[k]; ++k ) {
        res = min(res, 1 + f(i - ok[k]));
    } 
    return v[i] = res;

}

int main() {
    
    v[0] = 0;
    v[1] = 1;
    v[5] = 1;
    v[8] = 1;
    v[14] = 1;
    
    while ( cin >> n and n != -1 ) {
        
        cout << f(n) << endl;
    
    }
    
}
