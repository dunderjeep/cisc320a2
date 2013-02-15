
#ifndef FRACTION_8CC17_H
#define FRACTION_8CC17_H

#include <iostream>
#include <string>

class Fraction {
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	int getNumerator() const;
	int getDenominator() const;
private:
	int numerator;
	int denominator;
};

std::ostream& operator<<(std::ostream& out, const Fraction& value);
#endif 

