
#ifndef FRACTION_8CC17_H
#define FRACTION_8CC17_H

#include <iostream>
#include <string>

class FractionException {
public:
	FractionException(const string&);
	string what() const;
private:
	string message;
};

class Fraction {
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	int numerator() const;
	int denominator() const;		
private:
	int num;
	int denom;
	int gcd(int, int);
	void normalize();
	int mod(int, int);
};

std::ostream& operator<<(std::ostream& out, const Fraction& value);
#endif 

