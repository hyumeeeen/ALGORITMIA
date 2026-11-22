#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;
using VB = vector<bool>;
using Q = queue<int>;

int n, m;
VII arestas;
VI color;
//VB usado;

//he usado BFS, he ido por niveles
/*
bool f(int i) {
    if ( usado[i] ) return true;
    Q q;
    usado[i] = true;
    if ( color[i] == -1 ) color[i] = 0;
    int pintar = ( color[i] + 1 ) % 2;
    for ( int o : arestas[i] ) {
        if ( color[o] == -1 ) color[o] = pintar;
        else if ( color[i] == color[o] ) return false;
        q.push(o);
    }
    while ( not q.empty() ) {
        int x = q.front();
        q.pop();
        if ( !f(x) ) return false;
    } 
    return true;
}

int main() {
    while ( cin >> n >> m ) {
        arestas = VII(n);        
        color = VI(n, -1); 
        usado = VB(n, false);
        int a, b;
        for ( int i = 0; i < m; ++i ) {
            cin >> a >> b;
            arestas[a].push_back(b);
            arestas[b].push_back(a);
        }
        usado = VB(n, false);        
        bool ok = true;
        for ( int i = 0; i < n and ok; ++i ) {
            ok = f(i);
        }
        if ( ok ) cout << "yes" << endl;
        else cout << "no" << endl;

    } 
}

*/
//lo que fallaba es no usar bien queue
bool f(int i) {
    Q q;
    color[i] = 0;
    q.push(i);

    while ( not q.empty() ) {
        int x = q.front();
        int pintar = ( color[x] + 1 ) % 2;
        q.pop();
        for ( int o : arestas[x] ) {
            if ( color[o] == -1 ) {
                color[o] = pintar;
                q.push(o);
            } else if( color[o] == color[x] ) return false;
        }
    }
    return true;
}

int main() {
    while ( cin >> n >> m ) {
        arestas = VII(n);        
        color = VI(n, -1); 
        int a, b;
        for ( int i = 0; i < m; ++i ) {
            cin >> a >> b;
            arestas[a].push_back(b);
            arestas[b].push_back(a);
        }

        bool ok = true;
        for ( int i = 0; i < n and ok; ++i ) {
            if ( color[i] == -1 ) ok = f(i);
        }
        if ( ok ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
