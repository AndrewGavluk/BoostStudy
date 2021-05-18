#include <string>
#include <iostream>

#include <boost/format.hpp>

struct animal
{
    std::string name;
    int legs;
};

std::ostream &operator<<(std::ostream &os, const animal &a)
{
    return os << a.name << ',' << a.legs;
}

int main()
{
    // sample 1
    // format
    {
        std::cout << "sample1:\n";
        std::cout << boost::format{"%1%.%2%.%3%"} % 12 % 5 % 2014 << '\n';
    }

    // sample 2
    // format
    {
        std::cout << "sample2:\n";
        std::cout << boost::format{"%2%/%1%/%3%"} % 12 % 5 % 2014 << '\n';
    }

    // sample 3
    // boost::io::group, std::showpos
    {
        std::cout << "sample3:\n";
        std::cout << boost::format{"%1% %2% %1%"} %
                         boost::io::group(std::showpos, 1.1) % 2
                  << '\n';
    }

    // sample 4
    // special characters
    {
        std::cout << "sample4:\n";
        std::cout << boost::format{"%|1$+| %2% %1%"} % 1.1 % 2 << '\n';
    }

    // sample 5
    // format_error
    {
        std::cout << "sample5:\n";
        try
        {
            std::cout << boost::format{"%|+| %2% %1%"} % 1 % 2 << '\n';
        }
        catch (boost::io::format_error &ex)
        {
            std::cout << ex.what() << '\n';
        }
    }

    // sample 6
    // Placeholders without numbers
    {
        std::cout << "sample6:\n";
        std::cout << boost::format{"%|+| %|| %||"} % 1 % 2 % 1 << '\n';
    }

    // sample 7
    // With the syntax used from printf
    {
        std::cout << "sample7:\n";
        std::cout << boost::format{"%+d %d %d"} % 1 % 2 % 1 << '\n';
    }

    // sample 8
    // seemingly invalid placeholders
    {
        std::cout << "sample8:\n";
        std::cout << boost::format{"%+s %s %s"} % 1 % 2 % 1 << '\n';
    }

    // sample 9
    // with user-defined type

    {
        std::cout << "sample9:\n";
        animal a{"cat", 4};
        std::cout << boost::format{"%1%"} % a << '\n';
    }

    return 0;
}