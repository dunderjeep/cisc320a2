#define FRACTION_8CC17_MAIN
#include <iostream>
using namespace std;

#include "fraction_8cc17.h"

int main(int argc, char * argv[]) {

	// Test constructors and << operator overloading
	Fraction test1;
	cout << "Should be \"0/1\": " << test1 << endl;
	Fraction test2(4);
	cout << "Should be \"4/1\": " << test2 << endl;
	Fraction test3(20, 30);
	cout << "Should be \"2/3\": " << test3 << endl;
	Fraction test4(210, -60);
	cout << "Should be \"-7/2\": " << test4 << endl;

	// Test exception for when denominator is zero
	try {
		Fraction test5(4, 0);
		cout << "Should not get here: " << test5 << endl;
	} catch (FractionException &e) {
		cout << "Exception message should indicate illegal denominator: " << e.what() << endl;
	}

	// Test accessors
	cout << "Numerator should be -7: " << test4.numerator() << endl;
	cout << "Denominator should be 2: " << test4.denominator() << endl;
	
	return 0;
}
