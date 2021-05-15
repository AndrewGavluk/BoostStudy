//Example 1
#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstddef>

//Example 2
#include <boost/pool/object_pool.hpp>

//Example 3
#include <iostream>

//Example 4
#include <boost/pool/singleton_pool.hpp>

//Example 5
#include <boost/pool/pool_alloc.hpp>
#include <vector>

struct int_pool {};
typedef boost::singleton_pool<int_pool, sizeof(int)> singleton_int_pool;

int main()
{
	//Example 1
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

	//Example 2
	{
		boost::object_pool<int> pool;

		int *i = pool.malloc();
		*i = 1;

		int *j = pool.construct(2);

		pool.destroy(i);
		pool.destroy(j);
	}

	//Example 3
	{
		boost::object_pool<int> pool{ 32, 0 };
		pool.construct();
		std::cout << pool.get_next_size() << '\n';
		pool.set_next_size(8);
	}

	//Example 4
	{
		int *i = static_cast<int*>(singleton_int_pool::malloc());
		*i = 1;

		int *j = static_cast<int*>(singleton_int_pool::ordered_malloc(10));
		j[9] = 2;

		singleton_int_pool::release_memory();
		singleton_int_pool::purge_memory();
	}

	//Example 5
	{
		std::vector<int, boost::pool_allocator<int>> v;
		for (int i = 0; i < 1000; ++i)
			v.push_back(i);

		v.clear();
		boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::
			purge_memory();
	}


}
