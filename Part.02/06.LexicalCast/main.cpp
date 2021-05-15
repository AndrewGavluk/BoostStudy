#include <string>
#include <iostream>

#include <boost/lexical_cast.hpp>

int main()
{
    // sample 1
    // lexical_cast
    {
        std::cout << "sample1:\n";
        std::string s = boost::lexical_cast<std::string>(123);
        std::cout << s << '\n';
        double d = boost::lexical_cast<double>(s);
        std::cout << d << '\n';
    }
    // sample 2
    // lexical cast exception
    {
        std::cout << "sample2:\n";
        try
        {
            int i = boost::lexical_cast<int>("abc");
            std::cout << i << '\n';
        }
        catch (const boost::bad_lexical_cast &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}