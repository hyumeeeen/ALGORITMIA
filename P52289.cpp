#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VS = vector<string>; 
using VSS = vector<VS>;

int n, m;
string s1, s2;
VSS M;

string f(int i, int j) {
    //la subpalabra mas larga que empieza por la letra s1[i]


    if ( i >= n or j >= m ) return "";
    if ( M[i][j] != "" ) return M[i][j];
    
    string res = "";
    if ( s1[i] == s2[j] ) {
        res = s1[i]; 
        if ( j < m - 1 and i < n - 1 and s2[j + 1] == s1[i + 1] ) res += f(i + 1, j + 1);
    }

    if ( res.size() > f(i, j + 1).size() and res.size() > f(i + 1, j).size() ) return M[i][j] = res;
    if ( f(i, j + 1).size() > f(i + 1, j).size() ) return M[i][j] = f(i, j + 1);
    return M[i][j] = f()
    

}

int main() {

    while ( cin >> s1 >> s2 ) {
        
        n = s1.size();
        m = s2.size();

        M = VSS(n, VS(m, ""));

        cout << f(0, 0) << endl;

    }

}
