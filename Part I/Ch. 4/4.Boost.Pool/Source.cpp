#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstddef>

#include <boost/pool/object_pool.hpp>

#include <iostream>

#include <boost/pool/singleton_pool.hpp>

struct int_pool {};
typedef boost::singleton_pool<int_pool, sizeof(int)> singleton_int_pool;

int main()
{
	{	
		boost::simple_segregated_storage<std::size_t> storage;
	
		std::vector<char> v(1024);
		storage.add_block(&v.front(), v.size(), 256);

		int *i = static_cast<int*>(storage.malloc());
		*i = 1;

		int *j = static_cast<int*>(storage.malloc_n(1, 512));
		j[10] = 2;

		storage.free(i);
		storage.free_n(j, 1, 512);
	}
	{
		boost::object_pool<int> pool;

		int *i = pool.malloc();
		*i = 1;

		int *j = pool.construct(2);

		pool.destroy(i);
		pool.destroy(j);
	}
	{
		boost::object_pool<int> pool{ 32, 0 };
		pool.construct();
		std::cout << pool.get_next_size() << '\n';
		pool.set_next_size(8);
	}
	{
		int *i = static_cast<int*>(singleton_int_pool::malloc());
		*i = 1;

		int *j = static_cast<int*>(singleton_int_pool::ordered_malloc(10));
		j[9] = 2;

		singleton_int_pool::release_memory();
		singleton_int_pool::purge_memory();
	}
}
