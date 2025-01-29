#include <iostream>
using namespace std;

string ones[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string worded (long n) {
    if (n < 10) return ones[n];
	else if (n < 20) return teens [n - 10];
	else if (n < 100) return tens[n / 10] + ((n % 10 != 0) ? " " + worded(n % 10) : "");
	else if (n < 1000) return worded(n / 100) + " hundred" + ((n % 100 != 0) ? " " + worded(n % 100) : "");
	else if (n < 1000000) return worded(n / 1000) + " thousand" + ((n % 1000 != 0) ? " " + worded(n % 1000) : "");
	else if (n < 1000000000) return worded(n / 1000000) + " million" + ((n % 1000000 != 0) ? " " + worded(n % 1000000) : "");
	else if (n < 1000000000000) return worded(n / 1000000000) + " billion" + ((n % 1000000000 != 0) ? " " + worded(n % 1000000000) : "");
    return "Number is too large";
}

int main() {
    long input;
    cout << "Please enter a positive integer: ";    
    cin >> input;
    cout << "\n" << worded(input) << endl;
    return 0;
}
