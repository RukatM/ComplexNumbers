#include <iostream>
#include <stdexcept>
using namespace std;

class ComplexNumber {
public:
	ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i){}

	ComplexNumber(const ComplexNumber& number) : real(number.real), imaginary(number.imaginary) {}

	//Przeciążony operator <<
	friend ostream& operator<<(ostream& os, const ComplexNumber& number) {
		if (number.imaginary < 0) {
			os << number.real << " - " << -number.imaginary << "i";
		}
		else {
			os << number.real << " + " << number.imaginary << "i";
		}
		return os;
	}

	//Przeciążony oeprator +
	friend ComplexNumber operator+(const ComplexNumber& number, const ComplexNumber& otherNumber){
		return ComplexNumber(number.real + otherNumber.real, number.imaginary + otherNumber.imaginary);
	}

	//Przeciążony oeprator -
	friend ComplexNumber operator-(const ComplexNumber& number, const ComplexNumber& otherNumber){
		return ComplexNumber(number.real - otherNumber.real, number.imaginary - otherNumber.imaginary);
	}

	//Przeciążony oeprator *
	friend ComplexNumber operator*(const ComplexNumber& number, const ComplexNumber& otherNumber){
		return ComplexNumber(number.real * otherNumber.real 
		- (number.imaginary * otherNumber.imaginary), number.real * otherNumber.imaginary + number.imaginary * otherNumber.real);
	}

	//Przeciążony operator // 
	friend ComplexNumber operator/(const ComplexNumber& number, const ComplexNumber& otherNumber) {
		double denominator = (otherNumber.real * otherNumber.real) + (otherNumber.imaginary * otherNumber.imaginary);
		if (denominator == 0) {
			throw runtime_error("Błąd: Wykryto próbę dzielenia przez 0");
		}
		return ComplexNumber( (number.real * otherNumber.real + number.imaginary * otherNumber.imaginary)/ denominator, 
			(number.imaginary * otherNumber.real - number.real * otherNumber.imaginary) / denominator);
	}

private:
	double real = 0;
	double imaginary = 0;
};

int main() {
	ComplexNumber number1(20.00, -4.00);
	ComplexNumber number2(3.00, 2.00);

	cout << "Obsługa operatora +" << endl;
	cout << number1 + 5 << endl;
	cout << 5 + number1 << endl;
	cout << number1 + number2 << endl;

	// -
	cout << endl << "Obsługa operatora -" << endl;
	cout << number1 - 5 << endl;
	cout << 5 - number1 << endl;
	cout << number1 - number2 << endl;

	// *
	cout << endl << "Obsługa operatora *" << endl;
	cout << number1 * 5 << endl;
	cout << 5 * number1 << endl;
	cout << number1 * number2 << endl;

	// /
	cout << endl << "Obsługa operatora /" << endl;
	cout << number1 / 5 << endl;
	cout << 5 / number1 << endl;
	cout << number1 / number2 << endl;
	return 0;
}