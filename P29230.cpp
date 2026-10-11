#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
int n;
VI num = {50, 20, 10, 5, 2, 1};
VI sol;

void escriure() {
    for ( int i = 0; i < (int)sol.size(); ++i  ) {
        cout << ( i != 0 ? " " : "" ) << sol[i];
    }
    cout << endl;
}

void f(int count, int p) {

    if ( count > n ) return;
    if ( count == n ) return escriure();

    for ( int k = p; k < 6; ++k ) {
        sol.push_back(num[k]);
        f(count + num[k], k);
        sol.pop_back();
    }

}

int main() {
    while ( cin >> n ) {
        f(0, 0);
        cout << endl;
    } 

}
