namespace Lab5 {
	class D_Complex {
	private:
		double a;
		double b;

	public:
		D_Complex();
		D_Complex(float a, float b);
		D_Complex(double a, double b);
		D_Complex(int a, int b);
		D_Complex(const D_Complex &objToCopy);
		~D_Complex();

		D_Complex& operator=(const D_Complex& d_complex);

	};
}