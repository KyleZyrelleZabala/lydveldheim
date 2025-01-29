#include <bits/stdc++.h>
using namespace std;


int main() {
	int squaresum=0, sumsquare=0, sum=0, diff = 0;
	for (int i=1; i<101; i++) {
		sum+=i;
		squaresum=sum*sum;
		sumsquare+=(i*i);
		cout<<squaresum<<" "<<sumsquare<<endl;
	}
	
	diff = abs(sumsquare-squaresum);
	
	cout<<diff;
	
	return 0;
}
