#include <iostream>
#include <cmath>
using namespace std;

#include "fraction_8cc17.h"

Fraction::Fraction() : num(0), denom(1) { }
Fraction::Fraction(int n) : num(n), denom(1) { }
Fraction::Fraction(int n, int d) : num(n), denom(d) {
	normalize();
}

int Fraction::numerator() const { return num; }
int Fraction::denominator() const { return denom; }

void Fraction::normalize() {
	int divisor;
	divisor = gcd(num, denom);
	if (divisor > 1) {
		num /= divisor;
		denom /= divisor;	
	}
	if (divisor < 0) {
		num = -num;
		denom = -denom;	
	}
}

int Fraction::gcd(int a, int b) {
	if (b <= a && a % b == 0) return b;
	else if (a < b) return gcd(b, a); 	
	else return gcd(b, a % b);
}

ostream& operator<<(ostream& out, const Fraction& value) {
	out << value.numerator() << "/" << value.denominator();
}



