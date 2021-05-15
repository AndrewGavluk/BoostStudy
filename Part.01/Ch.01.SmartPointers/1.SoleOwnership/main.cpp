#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <iostream>
#include "Complex.hpp"

int main()
{
	int *_i = new int();
	delete _i;

	{
		std::cout << "Sample1:\n";
		boost::scoped_ptr<Complex> p(new Complex);
		std::cout << *p << '\n';
		p.reset(new Complex( 1.5, 0.5, typeArg::ReIm));
		std::cout << *p.get() << '\n';
		p.reset();
		std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
	}

	{
		std::cout << "Sample2:\n";
		const int SIZE = 5;
		const int SIZE2 = 3;
		boost::scoped_array<Complex> p (new Complex[SIZE]);
		*p.get() = {  -1., -1.,typeArg::ReIm };
		p.reset(new Complex[SIZE2]);
	}
	return 0;
}