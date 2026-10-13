#include <iostream>
#include <string>
#include <set>
using namespace std;

struct cmp {
    bool operator() (string a, string b) const {
        if ( a.size() != b.size() ) return a.size() < b.size();
        else return a < b;    
    }
};

int main() {
    
    set<string> S;
    set<string> aux;
    string str;
    
    while ( cin >> str ) {

        if ( str == "END" or str == "QUIT" ) {
            
            cout << "HAS:" << endl;
            for ( string s : S ) cout << s << endl;
            S.clear; // borro todo

            cout << "HAD:" << endl;
            for ( string s : aux ) cout << s << endl;
            aux.clear();
        }
        
        if ( S.find(str) == S.end() ) {
            S.insert(str);
            aux.erase(str);
        }
        else {
            S.erase(str);
            aux.insert(str);
        } 
    
    }
}
