#pragma once
#include <math.h>
#include <iostream>
enum typeArg
{
	ModArg,
	ReIm,
	Full
};

class Complex
{
private:
	double Re;
	double Im;

	double Ro;
	double Fi; 

public:
	Complex( double firstPar, double secondPar, typeArg type1 = typeArg::ReIm);
	Complex() :Complex(0.0, 0.0, typeArg::ReIm) {}
	~Complex();

	inline void UpdRoFi();
	inline void UpdReIm();

	Complex operator + (const Complex& c1);
	Complex operator - (const Complex& c1);

	Complex operator * (const Complex& c1);
	Complex operator / (const Complex& c1);

	friend std::ostream& operator << (std::ostream& ostr, const Complex& c1);

	friend void swap(Complex& c1, Complex& c2);
};

template <class cll>
class UnitBase
{
public:
	UnitBase()  {};
	~UnitBase() {};
	inline cll get() const { return info1; }
	inline cll set(const cll& inf1) { info1 = inf1; }
private:
	cll info1;
};

template <class cll>
class UnitInf: public UnitBase <cll>
{
public:
	UnitInf() {};
	~UnitInf() {};
	inline cll get() const { return info2; }
	inline cll set(const cll& inf1) { info2 = inf1; }
private:
	cll info2;
};
