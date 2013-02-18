// CISC 320 Assignment 2 
// Cliff Coulter 04192150
// Feb 18 2013
// A Class for creating Fractions with overloaded operations

#include <iostream>
#include <sstream>
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

Fraction& Fraction::operator+=(const Fraction& right) {
	num = num*right.denom + right.num*denom;
	denom = denom * right.denom;
	normalize();
	return *this;
}

//Pre-increment
Fraction& Fraction::operator++() {
	num += denom;
	return *this;
}

//Post-increment
Fraction Fraction::operator++(int unused) {
	Fraction clone(num, denom);
	num += denom;
	return clone;
}

int Fraction::compare(const Fraction& other) const {
	return numerator() * other.denominator() - denominator() * other.numerator();
}

bool operator==(const Fraction& left, const Fraction& right) {
	return left.compare(right) == 0;
}

bool operator!=(const Fraction& left, const Fraction& right) {
	return left.compare(right) != 0;
}

bool operator>(const Fraction& left, const Fraction& right) {
	return left.compare(right) > 0;
}

bool operator>=(const Fraction& left, const Fraction& right) {
	return left.compare(right) >= 0;
}

bool operator<(const Fraction& left, const Fraction& right) {
	return left.compare(right) < 0;
}

bool operator<=(const Fraction& left, const Fraction& right) {
	return left.compare(right) <= 0;
}

Fraction operator+(const Fraction& left, const Fraction& right) {
	int n = left.numerator() * right.denominator() + left.denominator() * right.numerator();	
	int d = left.denominator() * right.denominator();
	return Fraction(n,d);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
	int n = left.numerator() * right.denominator() - left.denominator() * right.numerator();	
	int d = left.denominator() * right.denominator();
	return Fraction(n,d);
}

Fraction operator*(const Fraction& left, const Fraction& right) {
	int n = left.numerator() * right.numerator();	
	int d = left.denominator() * right.denominator();
	return Fraction(n,d);
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	int n = left.numerator() * right.denominator();	
	int d = left.denominator() * right.numerator();
	return Fraction(n,d);
}

Fraction operator-(const Fraction& frac) {
	return Fraction(-frac.numerator(), frac.denominator());
}

ostream& operator<<(ostream& out, const Fraction& value) {
	out << value.numerator() << "/" << value.denominator();
}

istream& operator>>(istream& in, Fraction& value) {
	int n = 0;
    	int d = 1;
    	char peekchar;
 
	in >> n; 
	peekchar = in.peek();

	if(n == 0) {
		value = Fraction();
		return in;
	}
	if(in && peekchar == '/') {
		in.get(); // skip
		in >> d;
		if (d == 0) throw FractionException("Bad Fraction!");
	}
 
	value = Fraction(n, d);
 
	return in;

}
