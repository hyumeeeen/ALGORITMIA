#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
using VL = vector<ll>;
int n;

VL an(151, -1);
VL bn(151, -1);
VL cn(151, -1);
VL fn(151, -1);

ll a(int i);
ll b(int i);
ll c(int i);

ll a(int i) {
    if ( i == 2 ) return an[i] = 1;
    if ( i == 3 ) return an[i] = 2;
    if ( an[i] != -1 ) return an[i];
    return an[i] = a(i - 2) + b(i - 2);
}

ll c(int i) {
    if ( i == 2 ) return cn[i] = 1;
    if ( i == 3 ) return cn[i] = 1;
    if ( cn[i] != -1 ) return cn[i];
    return cn[i] = a(i - 2);

}

ll b(int i) {
    if ( i == 2 ) return bn[i] = 1;
    if ( i == 3 ) return bn[i] = 1;
    if ( bn[i] != -1 ) return bn[i];
    return bn[i] = c(i - 2) + b(i - 2);
}

ll f(int i) {

    if ( i == 0 ) return 1;
    if ( i == 1 ) return 2;
    if ( fn[i] != -1 ) return fn[i];
    return fn[i] = a(i) + b(i) + c(i); 
    
}

int main() {
    while ( cin >> n ) {
        cout << f(n) << endl;
    }
}
