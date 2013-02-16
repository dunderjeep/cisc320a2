#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

#include "fraction_8cc17.h"

FractionException::FractionException(const string& m) : message(m) { }
string FractionException::what() const { return message; }

Fraction::Fraction() : num(0), denom(1) { }
Fraction::Fraction(int n) : num(n), denom(1) { }
Fraction::Fraction(int n, int d) : num(n), denom(d) {
	if (denom == 0)
		throw FractionException("Illegal denominator: 0");
	if (denom < 0) {
		num *= -1;
		denom *= -1;	
	}	
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
}

int Fraction::gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, mod(a,b));
}

int Fraction::mod(int a, int b) {
	if (b < 0)
		return mod(-a, -b);
	int ret = a % b;
	if (ret < 0)
		ret += b;
	return ret;
}

ostream& operator<<(ostream& out, const Fraction& value) {
	out << value.numerator() << "/" << value.denominator();
}

Fraction operator+(const Fraction& left, const Fraction& right) {
	int n = left.numerator() * right.denominator() + left.denominator() * right.numerator();	
	int d = left.denominator() * right.denominator();
	cout << "denom:" << d;
	cout << "num: " << n;	
	return Fraction(n,d);
}



