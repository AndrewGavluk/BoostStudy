#include <string>
#include <memory>
#include <cstdio>

#include <boost/scope_exit.hpp>
/*
struct CloseFile
{
	void operator()(std::FILE *file)
	{
		std::fclose(file);
	}
};*/

void write_to_file(const std::string &s)
{
	//std::unique_ptr<std::FILE, CloseFile> file{
	//  std::fopen("hello-world.txt", "a") };
	std::FILE* file;
	fopen_s(&file, "hello-world.txt", "a");
	
	int c;
	std::fprintf(file, s.c_str());

	
	BOOST_SCOPE_EXIT(&file)
	{
		std::fclose(file);
	}
	BOOST_SCOPE_EXIT_END
}

int main()
{
	write_to_file("Hello, ");
	write_to_file("world!");

}