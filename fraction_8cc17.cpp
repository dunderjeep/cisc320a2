#include <iostream>
#include <cmath>
using namespace std;

#include "fraction_8cc17.h"

Fraction::Fraction() : numerator(0), denominator(1) { }

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

ostream& operator<<(ostream& out, const Fraction& value) {
	out << value.getNumerator() << "/" << value.getDenominator();
}



