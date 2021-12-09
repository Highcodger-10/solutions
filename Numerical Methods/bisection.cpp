#include<iostream>
#include<cmath>
using namespace std;

float function(float x) {
	return (sin(x)*x*cos(x) + 3*log(x));
}

int main() {
	float a, b, e, n;
	float c;
	float root;
	int k = 0;
	cout << "Enter the limits under which bisection is to be done " << endl;
	cin >> a;
	cin >> b;
	cout << "Enter the permissible error " << endl;
	cin >> e;
	n = (log(fabs(a - b)) - log(e)) / log(2);
	n = fabs(n);
	if (function(a) * function(b) > 0) {
		cout << "There is no any root within this interval " << endl;
	}
	else if (function(a) * function(b) == 0) {
		if (function(a) == 0 && function(b) == 0) {
			cout << "The roots are " << a << " and " << b << endl;
		}
		if (fabs(function(a)) < e) {
			root = a;
			cout << "The root of the given function is " << root << endl;
		}
		if(fabs(function(b)) < e) {
			root = b;
			cout << "The root of the given function is " << root << endl;
		}
	}
	else {
		do {
			c = (a + b) / 2;
			if (function(c) * function(a) < 0) {
				b = c;
			}
			if (function(c) * function(b) < 0) {
				a = c;
			}
			k++;
			if (k == (int)(2 * n)) {
				cout << "Function is discontinuous at this interval " << endl;
				return 0;
			}
		} while (fabs(function(c)) >= e);
	}
	if (fabs(function(c)) <= e) {
		root = c;
		cout << "The real root of the given equation at the given interval is " << root << endl;
	}
	return 0;
}
