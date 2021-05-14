#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <iostream>

#include "Complex.hpp"

void reset(boost::shared_ptr<Complex> &sh)
{
	sh.reset();
}

void print(boost::weak_ptr<Complex> &w)
{
	boost::shared_ptr<Complex> sh= w.lock();
	if (sh)
		std::cout << *sh << '\n';
}

int main()
{
	boost::shared_ptr<Complex> sh(new Complex);
	boost::weak_ptr<Complex> w(sh);

	std::thread t1(reset, std::ref(sh));
	std::thread t2(print, std::ref(w));

	t1.join();
	t2.join();

	return 0;
}