#define FRACTION_8CC17_MAIN
#include <iostream>
using namespace std;

#include "fraction_8cc17.h"

int main(int argc, char * argv[]) {

	Fraction test1;
	cout << test1 << endl;
	Fraction test2(4);
	cout << test2 << endl;
	Fraction test3(20, 30);
	cout << test3 << endl;
	return 1;
}
