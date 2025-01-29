#include<iostream>
using namespace std;

int d[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
string r[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
 
void d2r(int num){
	int i=0;
    while(num) {
        while(num/d[i]) {
            cout<<r[i];
            num-=d[i];
        }
        i++;
    }
}

int main() {
	int n=0;
    cin>>n;
    d2r(n);
    return 0;
}
