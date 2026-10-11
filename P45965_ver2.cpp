#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

int n, m;
VI v;

void escriure() {
    for ( int i = 0; i < n; ++i ) {
        cout << ( i != 0 ? " " : "" ) << v[i];
    }
    cout << endl;
}

void f(int i, int a, int b) {

    if ( a > n - m or b > m ) return;

    if ( i == n ) {
        return escriure();
    }

    v[i] = 0;
    f(i + 1, a + 1, b);
    v[i] = 1;    
    f(i + 1, a, b + 1);            


}


int main() {
    
    cin >> n >> m;
    v = VI(n);
    f(0, 0, 0);

}