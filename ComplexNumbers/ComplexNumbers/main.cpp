#include <iostream>
using namespace std;

class ComplexNumber {
public:
	ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i){}

	ComplexNumber(const ComplexNumber& number) {
		real = number.real;
		imaginary = number.imaginary;
	}

	//Przeciążony operator <<
	friend ostream& operator<<(ostream& os, const ComplexNumber& number) {
		os << number.real << " + (" << number.imaginary << "i)";
		return os;
	}

	//Przeciążony oeprator +
	ComplexNumber operator+(const ComplexNumber& number) {
		return ComplexNumber(real + number.real, imaginary + number.imaginary);
	}

	//Przeciążony oeprator -
	ComplexNumber operator-(const ComplexNumber& number) {
		return ComplexNumber(real - number.real, imaginary - number.imaginary);
	}

	//Przeciążony oeprator *
	ComplexNumber operator*(const ComplexNumber& number) {
		return ComplexNumber(real * number.real  - (imaginary * number.imaginary), real * number.imaginary + imaginary * number.real);
	}

	//Przeciążony operator // 
	ComplexNumber operator/(const ComplexNumber& number) {
		double denominator = (number.real * number.real) + (number.imaginary * number.imaginary);
		if (denominator == 0) {
			cout << "Nie wolono dzielić przez 0" << endl;
			return ComplexNumber(real, imaginary);
		}
		return ComplexNumber( (real * number.real + imaginary * number.imaginary)/ denominator, (imaginary * number.real - real * number.imaginary) / denominator);
	}

private:
	double real = 0;
	double imaginary = 0;
};

int main() {
	ComplexNumber number1(20.00, -4.00);
	ComplexNumber number2(3.00, 2.00);

	cout << number1 + 5;

	return 0;
}