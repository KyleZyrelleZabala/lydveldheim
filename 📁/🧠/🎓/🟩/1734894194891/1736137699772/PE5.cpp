#include<iostream>
using namespace std;

void gcd(int);
bool good[20];
void check(int);

void gcd(int num) {
	for (int i=1; i<21; i++) {
		if (num%i==0 && num>i) {
			good[i-1]=1;
			cout<<num<<" "<<i<<" GOOD"<<endl;
		}
		else {
			cout<<num<<" "<<i<<" "<<endl;
			check(num);
		}
	}
}
void check(int num) {
	for (int i=1; i<21; i++) {
		if (!good[i-1]) gcd(num*=i);
	}
}
int main() {
	for (int i=0; i<20; i++) {
		good[i]=0;
	}
	gcd(2);
	system("pause");
	return 0;
}   
