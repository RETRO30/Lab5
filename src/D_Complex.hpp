//Реализуйте класс D_Complex для работы с комплексными числами в формате a + bi.Он должен включать :
//
//1.	Базовые конструкторы(по умолчанию, полного заполнения)
//2.	Конструктор копирования
//3.	Оператор присваивания копированием
//4.	Деструктор с соответствующей записью в консоли
//5.	Операторы += и + , *= и *
//6.	Оператор ++ префиксный и постфиксный(увеличение действительной части числа на 1)
//7.	Операторы ввода и вывода

#include "iostream"
#include <string>
#include <limits>


namespace Lab5 {
	class D_Complex {
	private:
		double a;
		double b;

	public:
		D_Complex();
		D_Complex(double a, double b);
		D_Complex(const D_Complex &objToCopy);
		~D_Complex();

		D_Complex& operator=(const D_Complex& dComplex);
		D_Complex operator+(const D_Complex& dComplex);
		D_Complex operator+(double realNum);
		D_Complex& operator+=(const D_Complex& dComplex);
		D_Complex operator*(const D_Complex& dComplex);
		D_Complex& operator*=(const D_Complex& dComplex);

		D_Complex& operator++();
		D_Complex operator++(int);

		std::string GetString() const;
		double GetA() const;
		double GetB() const;

		void SetA(double a);
		void SetB(double b);
	};
	std::ostream& operator<<(std::ostream& os, const D_Complex &dComplex);
	std::istream& operator>>(std::istream& in, D_Complex& dComplex);

	double ScalarC(const D_Complex& num1, const D_Complex& num2);
	D_Complex absC(const D_Complex& num1, const D_Complex& num2);
	unsigned short qC(const D_Complex& num);
}