
#ifndef FRACTION_8CC17_H
#define FRACTION_8CC17_H

#include <iostream>
#include <string>

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
};

std::ostream& operator<<(std::ostream& out, const Fraction& value);
#endif 

