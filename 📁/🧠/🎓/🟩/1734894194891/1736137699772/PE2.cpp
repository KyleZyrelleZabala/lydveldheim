#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	
	long sum = 0;
	long prev = 1;
	long curr = 2;
	long next;
	
	while (prev<=4000000) {
		if (prev%2==0) sum+=prev;
		cout<<prev<<" ";
		next = prev + curr;
        prev = curr;
        curr = next;
	}
		
			
	cout << "\nSUM:" << sum;
	
	cout<<endl;
	
	return 0;
}


