#define BOOST_SP_USE_QUICK_ALLOCATOR // samp 5
#include <boost/shared_ptr.hpp>   // samp 1, samp 2, samp 5
#include <boost/make_shared.hpp>  // samp 3
#include <boost/shared_array.hpp> // samp 4
#include <iostream>
#include <ctime>		// samp 5
#include "Complex.hpp"	// samp 1


int main()
{
	
	// samp 1
	{
		boost::shared_ptr<Complex> c1{ new Complex(0.,0.) };
		std::cout << *c1 << '\n';

		boost::shared_ptr<Complex> c2{ c1 };
		c1.reset(new Complex{ 1.,0. });

		std::cout << *c1.get() << '\n';
		c1.reset();

		std::cout << std::boolalpha << static_cast<bool> (c2) << '\n';
	}

	// samp 2
	{
		//boost::shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION, FALSE, GetCurrentProcessId()), CloseHandle);
	}

	// samp 3
	{
		auto c1 = boost::make_shared<Complex>();
		std::cout << typeid(c1).name() << '\n';

		auto c2 = boost::make_shared<Complex[]>(10);
		std::cout << typeid(c2).name() << '\n';
	}
	
	//samp 4
	{
		boost::shared_array<Complex> p1{ new Complex[1] };
		{
			boost::shared_array<Complex> p2{ p1 };
			p2[0] = Complex (1, 1);
		}
		std::cout << p1[0] << '\n';
	}

	//samp 5
	{
		boost::shared_ptr<Complex> c;
		std::time_t t1 = std::time(nullptr);

		for (int i = 0; i < 3000000; ++i)
			c.reset(new Complex);

		std::time_t t2 = std::time(nullptr);
		std::cout << t2 - t1 << '\n';
	}
	return 0;
}