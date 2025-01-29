#include<bits/stdc++.h>
using namespace std;
int main() {
	int n = 0;
	string s = "";
	getline(cin,s);
	for(int i=0; s[i]; i++) if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) n++;
	cout<<"# of letters: "<<n<<endl;
	return 0;
}
