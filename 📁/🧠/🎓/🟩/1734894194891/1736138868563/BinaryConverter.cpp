#include<bits/stdc++.h>
using namespace std;

int main() {
	int input, x=-1;
	
	cin>>input;
	char bin[100]="";
	int i=0;
	while(input>0){
		if(input & 1) bin[i]='1';
		else bin[i]='0';
		i++;
		input/=2;
	}
	cout<<strrev(bin);
	return 0;
}
