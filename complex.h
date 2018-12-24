#pragma once
/*===========================================================
*
*___________________Complex Number Class_____________________
*
* Author: Malinda Sulochana Silva
* Date	: 2018.12.22
* bugs	: No known bugs
*
*
============================================================*/

/* Includes */
#include <cmath>
#include <iostream>


/* Class Definition */
class complex
{

private:
	
	// private containers
	struct complexVal{
		float real;
		float img;
	}compVal;

	struct rtheta {
		float r;
		float theta;
	}rtheta;

	
public:

	// Constructor
	complex (float x = 0.0, float y = 0.0 ) {
		this->compVal.real = x;
		this->compVal.img = y;
	}

	// Setter Method
	inline void setValue ( float real, float img ) { 
		this->compVal.real = real;
		this->compVal.img = img;
	} 

	// Getter Method
	inline complexVal getValue ( ) { return this->compVal; }
	inline float argZ () {
		return  atanf(compVal.img /compVal.real);
	}

	/*----------------
	* Special Methods
	------------------*/

	// Method for absolute value
	inline float absZ () {
		return sqrtf ( powf (compVal.real, 2.0 ) + powf (compVal.img, 2.0 ) );
	}

	// Method for showing in polar view
	inline static void showPolar ( complex x ) {
		std::cout << x.absZ() << " {cos(" << x.argZ() << ") + i" <<
							  "sin(" << x.argZ() << ")}\n"; 
	}
	
	
	/*-------------------
	* Operator Overloads 
	---------------------*/
	
	// Print to console
	friend std::ostream&  operator<<( std::ostream& stream, complex x ) {
		if (x.getValue().img > 0 )
			stream << x.getValue ( ).real << " + " << x.getValue ( ).img << "i";
		else
			stream << x.getValue ( ).real << " - " << abs(x.getValue ( ).img) << "i";

		return stream;
	}

	// Complex addition
	friend complex complex::operator+( complex& x, complex& y ) {
		complex ret;
		ret.setValue(x.getValue().real + y.getValue ( ).real,
					x.getValue ( ).img + y.getValue ( ).img);
		
		return ret;
	}

	// Complex Subtraction
	friend complex complex::operator-( complex& x, complex& y ) {
		complex ret;
		ret.setValue ( x.getValue ( ).real - y.getValue ( ).real,
					   x.getValue ( ).img - y.getValue ( ).img );

		return ret;
	}

	// Complex multiplication
	friend complex complex::operator*( complex& x ,complex& y) {
		complex ret; 
		float realValue = (x.getValue ( ).real * y.getValue ( ).real) + (x.getValue ( ).img * y.getValue ( ).img);
		float imgValue = (x.getValue ( ).real * y.getValue ( ).img) + x.getValue ( ).img * y.getValue ( ).real;
		ret.setValue ( realValue,imgValue );
		return ret;
	}

	
	// Complex Division
	friend complex complex::operator/( complex& x, complex& y ) {
		complex ret;
		ret.setValue ( (x * (~y)).getValue ( ).real / ( y * (~y)).absZ() ,
			(x * (~y)).getValue ( ).img / ( y * (~y) ).absZ() );
		return ret;
	}

	// Complex conjugate
	friend complex complex::operator~( complex& x) {
		complex ret;
		ret.setValue ( x.getValue ( ).real,x.getValue ( ).img * -1);
		return ret;
	}
	

	~complex ( ) {
	};
}; 

