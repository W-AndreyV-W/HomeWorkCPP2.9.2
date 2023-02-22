#include <iostream>
#include <locale.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	void reductionfraction() {
		int num = 0;
		if (numerator_ > denominator_) {
			num = numerator_;
		}
		else {
			num = denominator_;
		}
		for (; num > 0; num--) {
			if (!(numerator_ % num) && !(denominator_ % num)) {
				numerator_ /= num;
				denominator_ /= num;
				break;
			}
		}
	}

	Fraction operator + (Fraction other) { return Fraction((numerator_ * other.denominator_) + (other.numerator_ * denominator_), denominator_ * other.denominator_); }
	Fraction operator - (Fraction other) { return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_); }
	Fraction operator * (Fraction other) { return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_); }
	Fraction operator / (Fraction other) { return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_); }
	Fraction& operator ++ () { numerator_ += denominator_; denominator_; return *this; }
	Fraction operator ++ (int) {
		Fraction temp = *this;
		numerator_ += denominator_;
		return temp;
	}
	Fraction operator -- () { return Fraction(numerator_ -= denominator_, denominator_); }
	Fraction operator -- (int) {
		{
			Fraction temp = *this;
			numerator_ -= denominator_;
			return temp;
		}
	}
	Fraction operator - () { return Fraction(numerator_ = -numerator_, denominator_); }

	void print() {
		reductionfraction();
		std::cout << numerator_ << "/" << denominator_;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int num1 = 1, num2 = 1, num3 = 1, num4 = 1;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> num2;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num3;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> num4;
	Fraction f1(num1, num2);
	Fraction f2(num3, num4);

	f1.print();
	std::cout << " + ";
	f2.print();
	std::cout << " = ";
	Fraction fp = f1 + f2;
	fp.print();
	std::cout << std::endl;

	f1.print();
	std::cout << " - ";
	f2.print();
	std::cout << " = ";
	Fraction fs = f1 - f2;
	fs.print();
	std::cout << std::endl;

	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	Fraction fm = f1 * f2;
	fm.print();
	std::cout << std::endl;

	f1.print();
	std::cout << " / ";
	f2.print();
	std::cout << " = ";
	Fraction fd = f1 / f2;
	fd.print();
	std::cout << std::endl;

	std::cout << "++";
	f1.print();
	std::cout << " * ";
	f2.print(); 
	std::cout << " = ";
	Fraction fipr = ++ f1 * f2;
	fipr.print();
	std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << std::endl;
	
	std::cout << "--";
	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	Fraction fdpr = -- f1 * f2;
	fdpr.print();
	std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << std::endl;

	f1.print();
	std::cout << "++ * ";
	f2.print();
	std::cout << " = ";
	Fraction fipo = f1 ++ * f2;
	fipo.print();
	std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << std::endl;

	f1.print();
	std::cout << "-- * ";
	f2.print();
	std::cout << " = ";
	Fraction fdpo = f1 -- * f2;
	fdpo.print();
	std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << std::endl;

	Fraction fsu = -f1;
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << std::endl;

	return 0;
}