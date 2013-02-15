#include <iostream>
#include <cmath>
using namespace std;

#include "fraction_8cc17.h"

Fraction::Fraction() : numerator(0), denominator(1) { }
Fraction::Fraction(int n) : numerator(n), denominator(1) { }
Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
	normalize();
}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::normalize() {
	int divisor;
	divisor = gcd(numerator, denominator);
	if (divisor > 1) {
		numerator /= divisor;
		denominator /= divisor;	
	}
	if (divisor < 0) {
		numerator = -numerator;
		denominator = -denominator;	
	}
}

int Fraction::gcd(int a, int b) {
	if (b <= a && a % b == 0) return b;
	else if (a < b) return gcd(b, a); 	
	else return gcd(b, a % b);
}

ostream& operator<<(ostream& out, const Fraction& value) {
	out << value.getNumerator() << "/" << value.getDenominator();
}



