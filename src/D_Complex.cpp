#include "D_Complex.hpp"
#include "iostream"

Lab5::D_Complex::D_Complex()
{
	this->a = 1;
	this->b = 1;
}

Lab5::D_Complex::D_Complex(double a, double b): D_Complex()
{
	this->a = a;
	this->b = b;
}

Lab5::D_Complex::D_Complex(float a, float b) : D_Complex((double)a, (double)b) {}


Lab5::D_Complex::D_Complex(int a, int b): D_Complex((double)a, (double)b) {}

Lab5::D_Complex::D_Complex(const D_Complex &objToCopy) {
	this->a = objToCopy.a;
	this->b = objToCopy.b;
}


Lab5::D_Complex::~D_Complex()
{
	std::cout << "Class deleted" << std::endl;
}

Lab5::D_Complex& Lab5::D_Complex::operator=(const D_Complex& d_complex)
{
	if (&d_complex != this) {
		this->a = d_complex.a;
		this->b = d_complex.b;
	}
	return *this;
}



