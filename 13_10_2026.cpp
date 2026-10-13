//SETS AND MAPS
#include <iostream>
#include <set>
using namespace std;

int main() {
  
    set<int> s;
  
    s.insert(1);
    s.inser(1);
    s.insert(40);
    s.insert(-1);
    s.erase(123);
    /*
    si insertas una cosa que ya esta, no da error, si borras una cosa que no esta, no da error
    */
    int x; 
    cin >> x;

    if ( s.find(x) != s.end() ) {
        cout << "yes" << endl;
    }

    for ( int x : s ) cout << x << endl;
    // nos da los elementos del set que estan en orden
    
}
