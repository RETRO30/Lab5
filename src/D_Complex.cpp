#include "D_Complex.hpp"
#include "iostream"
#include <string>
#include <limits>
#include <cmath>

Lab5::D_Complex::D_Complex()
{
	this->a = 1;
	this->b = 1;
}

Lab5::D_Complex::D_Complex(double a, double b) : D_Complex()
{
	this->a = a;
	this->b = b;
}

Lab5::D_Complex::D_Complex(const D_Complex& objToCopy) {
	this->a = objToCopy.a;
	this->b = objToCopy.b;
}


Lab5::D_Complex::~D_Complex()
{
	std::cout << "Class deleted" << std::endl;
}

Lab5::D_Complex& Lab5::D_Complex::operator=(const D_Complex& dComplex)
{
	if (&dComplex != this) {
		this->a = dComplex.a;
		this->b = dComplex.b;
	}
	return *this;
}

Lab5::D_Complex Lab5::D_Complex::operator+(const D_Complex& dComplex) {
	return D_Complex(this->a + dComplex.a, this->b + dComplex.b);
}

Lab5::D_Complex Lab5::D_Complex::operator+(double realNum)
{
	return D_Complex(this->a + realNum, this->b);
}

Lab5::D_Complex& Lab5::D_Complex::operator+=(const D_Complex& dComplex) {
	this->a += dComplex.a;
	this->b += dComplex.b;
	return *this;
}

Lab5::D_Complex Lab5::D_Complex::operator*(const D_Complex& dComplex) {
	return D_Complex(a * dComplex.a - b * dComplex.b, a * dComplex.a + b * dComplex.b);
}

Lab5::D_Complex& Lab5::D_Complex::operator*=(const D_Complex& dComplex) {
	this->a = this->a * dComplex.a - this->b * dComplex.b;
	this->b = this->a * dComplex.a + this->b * dComplex.b;
	return *this;
}

Lab5::D_Complex& Lab5::D_Complex::operator++()
{
	++this->a;
	return *this;
}

Lab5::D_Complex Lab5::D_Complex::operator++(int)
{
	Lab5::D_Complex temp = *this;
	++(*this);
	return temp;
}

std::string Lab5::D_Complex::GetString() const
{
	std::string real;
	if (a == (double)0) {
		real = "";
	}
	else {
		real = std::to_string(a);
	}

	std::string mnim;
	if (b == (double)0) {
		mnim = "";
	}
	else {
		char znak = b > std::numeric_limits<double>::epsilon() ? '+' : '-';
		if (znak == '+' && real == "") {
			mnim = std::to_string(b) + "i";
		}
		else {
			mnim = znak + std::to_string(b) + "i";
		}
	}

	std::string res = real + mnim;
	return res;
}

double Lab5::D_Complex::GetA() const
{
	return this->a;
}

double Lab5::D_Complex::GetB() const
{
	return this->b;
}

void Lab5::D_Complex::SetA(double a)
{
}

void Lab5::D_Complex::SetB(double b)
{
}

std::ostream& Lab5::operator<<(std::ostream& os, const D_Complex& dComplex)
{
	std::string result = dComplex.GetString();
	return os << result;
}

std::istream& Lab5::operator>>(std::istream& in, D_Complex& dComplex)
{
	double a;
	double b;
	in >> a >> b;
	if (in) 
	{
		dComplex.SetA(a);
		dComplex.SetB(b);
	}
	return in;
}

double Lab5::ScalarC(const D_Complex& num1, const D_Complex& num2)
{
	double result = num1.GetA() * num2.GetA() + num1.GetB() * num2.GetB();
	return result;
}

Lab5::D_Complex Lab5::absC(const D_Complex& num1, const D_Complex& num2)
{
	double absNum1 = sqrt(pow(num1.GetA(), 2) + pow(num1.GetB(), 2));
	double absNum2 = sqrt(pow(num2.GetA(), 2) + pow(num2.GetB(), 2));
	return absNum1 > absNum2 ? num1 : num2;
}

unsigned short Lab5::qC(const D_Complex& num)
{
	if (num.GetA() > std::numeric_limits<double>::epsilon()) {
		if (num.GetB() > std::numeric_limits<double>::epsilon()) {
			return 1;
		}
		else {
			return 4;
		}
	}
	else {
		if (num.GetB() > std::numeric_limits<double>::epsilon()) {
			return 2;
		}
		else {
			return 3;
		}
	}
	return 0;
}
