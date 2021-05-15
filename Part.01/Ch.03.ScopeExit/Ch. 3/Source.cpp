
#include <boost/scope_exit.hpp>
#include <iostream>

#include <utility>

int *foo1()
{
	int *i = new int{ 10 };
	BOOST_SCOPE_EXIT(&i)
	{
		delete i;
		i = 0;
	} BOOST_SCOPE_EXIT_END
		std::cout << *i << '\n';
	return i;
}

template <typename T>
struct scope_exit2
{
	scope_exit2(T &&t) : t_{ std::move(t) } {}
	~scope_exit2() { t_(); }
	T t_;
};

template <typename T>
scope_exit2<T> make_scope_exit(T &&t) {
	return scope_exit2<T>{
		std::move(t)};
}

int *foo2()
{
	int *i = new int{ 10 };
	auto cleanup = make_scope_exit([&i]() mutable { delete i; i = 0; });
	std::cout << *i << '\n';
	return i;
}

struct x3
{
	int i;

	void foo()
	{
		i = 10;
		BOOST_SCOPE_EXIT(void)
		{
			std::cout << "last\n";
		} BOOST_SCOPE_EXIT_END
			BOOST_SCOPE_EXIT(this_)
		{
			this_->i = 20;
			std::cout << "first\n";
		} BOOST_SCOPE_EXIT_END
	}
};

int main()
{
	{
		int *j = foo1();
		std::cout << j << '\n';
	}
	{
		int *j = foo2();
		std::cout << j << '\n';
	}
	{
		x3 obj;
		obj.foo();
		std::cout << obj.i << '\n';
	}
}