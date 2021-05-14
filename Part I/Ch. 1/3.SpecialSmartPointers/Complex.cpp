#include "Complex.hpp"

inline void swapBaseD(double& d1, double& d2)
{
	d1 += d2;
	d2 = d1 - d2;
	d1 -= d2;
}

void swap(Complex& c1, Complex& c2)
{
	swapBaseD(c1.Re, c2.Re);
	swapBaseD(c1.Im, c2.Im);
	swapBaseD(c1.Ro, c2.Ro);
	swapBaseD(c1.Fi, c2.Fi);
}

Complex::Complex(double firstPar, double secondPar, typeArg type1)
{
	if (type1 == typeArg::ModArg)
	{
		Ro = firstPar;
		Fi = secondPar;
		UpdReIm();
	}
	else
	{
		Re = firstPar;
		Im = secondPar;
		UpdRoFi();
	}
}

inline void Complex::UpdRoFi()
{
	Ro = sqrt(Re * Re + Im * Im);
	Fi = atan(Re / Im);
}

inline void Complex::UpdReIm()
{
	Ro = sqrt(Re * Re + Im * Im);
	Fi = atan(Re / Im);
}

Complex Complex::operator+(const Complex & c1)
{
	return Complex( Re+c1.Re, Im+c1.Im, ReIm );
}

Complex Complex::operator-(const Complex & c1)
{
	return Complex(Re - c1.Re, Im - c1.Im, ReIm);
}

Complex Complex::operator*(const Complex & c1)
{
	return Complex( Re * c1.Re - Im * c1.Im, 
					Re * c1.Im + Im * c1.Re, 
		ReIm );
}

Complex Complex::operator/(const Complex & c1)
{
	return Complex(Re * c1.Re - Im * c1.Im,
		Re * c1.Im + Im * c1.Re,
		ReIm );
}

std::ostream& operator<< (std::ostream& ostr, const Complex& c1)
{
	ostr << c1.Re << "+(" << c1.Im << ")*i\n";
	return ostr;
}

Complex::~Complex()
{
}
