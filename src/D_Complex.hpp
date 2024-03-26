//���������� ����� D_Complex ��� ������ � ������������ ������� � ������� a + bi.�� ������ �������� :
//
//1.	������� ������������(�� ���������, ������� ����������)
//2.	����������� �����������
//3.	�������� ������������ ������������
//4.	���������� � ��������������� ������� � �������
//5.	��������� += � + , *= � *
//6.	�������� ++ ���������� � �����������(���������� �������������� ����� ����� �� 1)
//7.	��������� ����� � ������

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