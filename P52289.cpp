#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

using VS = vector<string>;
using VSS = vector<VS>;
using VI = vector<int>;
using VII = vector<VI>;

int n, m;
string s1, s2;
VII M;

bool f(int maxim, int i, int j, string& s) {

    string p = "";
    for ( int k = 0; k < maxim; ++k ) {
        if ( s1[i + k] != s2[j + k] ) return false;
        else p += s1[i + k];
    } 

    s = p;
    return true;

}

string c(VI& v, int maxim) {
    
    vector<string> a;
    for ( int k = 0; k < (int)v.size(); ++k ) {
        string s = "";
        for ( int p = 0; p < maxim; ++p ) {
            s += s1[v[k] + p];
        }
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    return a[0];

}

int main() {

    while ( cin >> s1 >> s2 ) {
        
        n = s1.size();
        m = s2.size();

        VI v;
        M = VII(n, VI(m, 0));

        int maxim1 = 0;
        for( int i = n - 1; i >= 0; --i ) {

            int maxim2 = 0;
            for ( int j = 0; j < m; ++j ) {        

                if ( s1[i] == s2[j] ) {
                    M[i][j] += 1;
                    if ( i + 1 < n and j + 1 < m ) M[i][j] += M[i + 1][j + 1];
                }

                if ( M[i][j] > maxim2 ) {
                    maxim2 = M[i][j];
                }

            }

            if ( maxim2 > maxim1 ) {
                v.clear();
                v.push_back(i);
                maxim1 = maxim2;
            }
            if ( maxim2 == maxim1 ) v.push_back(i);

        }

        if ( maxim1 != 0 ) cout << c(v, maxim1) << endl;
        else cout << endl;


        

    }

}
