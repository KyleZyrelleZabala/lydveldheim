#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum = 1000;
    int a,b,c;
    for (a = 1; a <= sum/3; a++) {
        for (b = a + 1; b <= sum/2; b++) {
            c = sum - a - b;
            if ( a*a + b*b == c*c ) {
            	cout <<"a: " << a  <<" b: " << b  <<" c: " << c << " abc: " <<a*b*c << endl;
			}
        }
    }
    return 0;
}
