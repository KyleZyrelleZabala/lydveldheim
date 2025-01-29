#include <bits/stdc++.h>
using namespace std;

struct Seed {
	vector<long long> sequence;
	int seed;
};
struct by_length {
    bool operator() (Seed const &a, Seed const &b) { 
        return a.sequence.size() < b.sequence.size();
    }
};
vector<Seed> collatz;

Seed chain(long long, Seed);
void output(Seed);

Seed chain(long long num, Seed me) {
	me.sequence.push_back(num);
	cout<<me.sequence.at(me.sequence.size()-1)<<endl;
	if (num!=1) {
		if (num%2==0) return chain(num/2, me);
		else return chain(1+num*3, me);
	}
	me.seed = me.sequence.at(0);
	return me;
}
void output(Seed s) {
	cout<<"SEED: " <<s.sequence.at(0)<<endl;
	cout<<"LENGTH: " <<s.sequence.size()<<endl;
}
int main() {
	for (int i=837700; i<837800; i++) {
		cout<<"\n\nBEGIN: ";
		Seed root;
		Seed grow = chain(i,root);
		output(grow);
		collatz.push_back(grow);
	}

	sort(collatz.begin(), collatz.end(), by_length());
	cout<<"FINAL: "<<endl;
	output(collatz.at(collatz.size()-1));
}
