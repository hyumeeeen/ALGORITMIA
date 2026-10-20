#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;
using VC = vector<char>;

string s;
int p;
VII M;

int min3(int a, int b, int c) {
    
    if ( a <= b and a <= c ) return a;
    if ( b <= a and b <= c ) return b;
    return c;

}

int f(int i, int j) {

    if ( i >= j ) return 0;
    if ( M[i][j] != -1 ) return M[i][j];

    if ( s[i] == s[j] ) {
        return M[i][j] = min3(f(i + 1, j - 1), 1 + f(i + 1, j), 1 + f(i, j - 1));
    }

    return M[i][j] = min(1 + f(i + 1, j), 1 + f(i, j - 1));

}

int main() {

    while ( cin >> s ) {

        p = s.size();
        M = VII(p, VI(p, -1));
        if ( f(0, p - 1) == 0 ) cout << "Supera el Dislex-Wonga test" << endl;
        else cout << f(0, p - 1) << endl;

    }


}
