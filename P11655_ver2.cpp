#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int s, n;
VI num;
VB usado;

void escriure() {

}

void f(int i) {

    
}


int main() {
    cin >> s >> n;
    num = VI(n);
    usado = VB(n, false);

    for ( int i = 0; i < n; ++i ) cin >> num[i];
    sort(num.begin(), num.end());


}