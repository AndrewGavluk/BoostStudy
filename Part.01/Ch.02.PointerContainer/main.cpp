#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <memory>
#include <set>

#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>

int main()
{
	// Sample 1
	// boost::ptr_vector<int> v; 
	{
		std::cout << "Sample1:\n";
		boost::ptr_vector<int> v;
		v.push_back(new int{ 1 });
		v.push_back(new int{ 2 });
		std::cout << v.back() << '\n';
	}

	// Sample 2
	// indirect_fun, ptr_set
	{
		std::cout << "Sample2:\n";
		boost::ptr_set<int> s;
		s.insert(new int{ 2 });
		s.insert(new int{ 1 });
		std::cout << *s.begin() << '\n';

		std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v;
		v.insert(std::unique_ptr<int>(new int{ 2 }));
		v.insert(std::unique_ptr<int>(new int{ 1 }));
		std::cout << **v.begin() << '\n';
	}

	// Sample 3
	// indirect_fun, ptr_set
	{
		std::cout << "Sample3:\n";
		boost::ptr_vector<int> v;
		std::array<int, 3> a{ {0, 1, 2} };
		std::copy(a.begin(), a.end(), boost::ptr_container::ptr_back_inserter(v));
		std::cout << v.size() << '\n';
	}
}