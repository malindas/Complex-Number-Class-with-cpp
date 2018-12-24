#include <iostream>
#include "complex.h"
#include "Plotter.h"

using namespace std;

int main ( int argc, char** argv ) {

	// Heap allocation
	complex *z1 = new complex( 1,54 );
				
	// Stack allocation
	complex z2 ( 3.5,7.6 );

	// Sample use of the complex class
	cout << *z1 << endl;			// printing the value
	cout << z2 << endl;			// printing the value
	cout << (*z1 + z2) << endl;	// addition
	cout << (*z1 - z2) << endl; // subtraction
	cout << (*z1 * z2) << endl; // multiplication
	cout << (*z1 / z2) << endl; // division
	cout << (~(*z1)) << endl;	// conjugate
	complex::showPolar ( ~(*z1) );	// ploarform
	

	
	cin.get();
	return 0;
}