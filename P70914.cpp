#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
int n, y, x;
VI count;

void escriure() {
    
    cout << "{";
    bool primero = true;
    for ( int i = 1; i < n + 1; ++i ) {
        for ( int k = 0; k < count[i]; ++k ) {
            if ( primero ) primero = false;
            else cout << ",";
            cout << i;
        }
    } 
    cout << "}" << endl;

}

void f(int i) {

    if ( i == n + 1 ) return escriure();

    for ( int k = y; k <= x; ++k ) {
        count[i] = k;
        f(i + 1);
        count[i] = 0;
    }

}

int main() {
    cin >> n >> y >> x;
    count = VI(n + 1);
    f(1);
}
