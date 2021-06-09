#include <iostream>
#include <locale>
#include <string>

#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>


namespace bxp = boost::xpressive;

int main()
{
    // sample 1
    // regex_match
    {
        std::cout << "sample 1:\n";
        std::string s = "Boost libraries";
	bxp::sregex expr = bxp::sregex::compile("\\w+\\s\\w+");
	std::cout << std::boolalpha << regex_match(s, expr) << '\n';
    }

    // sample 2
    // regex_search + smatch
    {
        std::cout << "sample 2:\n";
	const char *c = "Boost Libraries";
	bxp::cregex expr = bxp::cregex::compile("\\w+\\s\\w+");	
	std::cout << std::boolalpha << regex_match(c, expr) << '\n';
    }

    // sample 3
    // regex_replace
    {
	std::cout << "sample 3:\n";
	std::string s = "Boost libraries";
	bxp::sregex expr = +bxp::_w >> bxp::_s >> +bxp::_w;	
	std::cout << std::boolalpha << regex_match(s, expr) << '\n';
    }

    // sample 4
    // regex_replace + format string
    {
        std::cout << "sample 4:\n";
        std::string s = "Boost libraries";
	std::ostream_iterator<std::string> it{std::cout,"/n"};
	bxp::sregex expr = (+bxp::_w)[*bxp::ref(it) = bxp::_] >> s >> + bxp::_w;
	std::cout <<  std::boolalpha << regex_match(s, expr) << '\n';
    }

    return 0;
}
