#include<bits/stdc++.h>
using namespace std;
int main() {
	int sum=0;
	for(int i=1; i<10; i++) {
		if(i%3==0 || i%5==0) {
			cout<<i<<"\n";
			sum+=i;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
