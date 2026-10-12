#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct par {
    int num;
    int pos;
};

using VP = vector<par>;
using VI = vector<int>;
using VII = vector<VI>;
int m, n;
VP A;
VP B;
VP C;
VP D;
VII M;

bool comp(par a, par b) {

    if ( a.num == b.num ) return a.pos < b.pos;
    else return a.num < b.num;

}

int esta(int x) {

}

int f(int i, int j, int& maximo) {


    if ( M[i][j] != -1 ) return M[i][j];

    int k = esta(i);
    if ( k == -1 ) return M[i][j] = 0;
    else return M[i][j] = 1;

    maximo = max(M[i][j], maximo);
    return M[i][j] = f(i + 1, k, maximo);



}

int main() {

    while ( cin >> m >> n ) {

        A = VP(m);
        B = VP(n);
        M = VII(m, VI(n, -1));
        for ( int i = 0; i < m; ++i ) {
            cin >> A[i].num;
            A[i].pos = i;
        }
        for ( int i = 0; i < n; ++i ) {
            cin >> B[i].num;
            B[i].pos = i;
        }
        
        C = A;
        D = B;
        sort(C.begin(), C.end(), comp);
        sort(D.begin(), D.end(), comp);
        //suponemos aqui que m >= n
        
        int maximo = 0;
        cout << f(0, 0, maximo) << endl;
        


    }

}
