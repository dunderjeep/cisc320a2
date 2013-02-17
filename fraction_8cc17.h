
#ifndef FRACTION_8CC17_H
#define FRACTION_8CC17_H

#include <iostream>
#include <string>
#include <sstream>

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
	
	Fraction& operator+=(const Fraction& right);	
	Fraction& operator++(); // Pre-increment
	Fraction operator++(int); // Post-increment

	int compare(const Fraction& other) const;
private:
	int num;
	int denom;
	int gcd(int, int);
	void normalize();
	int mod(int, int);

friend Fraction operator+(const Fraction& left, const Fraction& right);
friend Fraction operator-(const Fraction& left, const Fraction& right);
friend Fraction operator*(const Fraction& left, const Fraction& right);
friend Fraction operator/(const Fraction& left, const Fraction& right);
friend Fraction operator-(const Fraction& frac);

friend bool operator==(const Fraction& left, const Fraction& right);
friend bool operator!=(const Fraction& left, const Fraction& right);
friend bool operator<(const Fraction& left, const Fraction& right);
friend bool operator<=(const Fraction& left, const Fraction& right);
friend bool operator>(const Fraction& left, const Fraction& right);
friend bool operator>=(const Fraction& left, const Fraction& right);

friend std::ostream& operator<<(std::ostream& out, const Fraction& value);
friend std::istream& operator>>(std::istream&, Fraction& value);
};


#endif 

