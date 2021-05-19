#include <iostream>
#include <locale>
#include <regex> // c++ 11
#include <string>

#include <boost/regex.hpp>

int main()
{
    // sample 1
    // regex_match
    {
        std::cout << "sample 1:\n";
        // boost
        {
            std::string s = "Boost Libraries";
            boost::regex expr{"\\w+\\s\\w+"};
            std::cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
        }
        // c++11 STL
        {
            std::string s = "ST Libraries";
            std::regex expr{"\\w+\\s\\w+"};
            std::cmatch m;
            std::cout << std::boolalpha << std::regex_match(s.c_str(), m, expr) << '\n';
        }
    }

    // sample 2
    // regex_search + smatch
    {
        std::cout << "sample 2:\n";
        // boost
        {
            std::string s = "BoostXXLibrarieXXCPP";
            boost::regex expr{"(\\w+)XX(\\w+)XX(\\w+)"};
            boost::smatch what;
            if (boost::regex_search(s, what, expr))
            {
                std::cout << what[0] << '\n';
                std::cout << what[1] << " _ " << what[2] << " _ " << what[3] << '\n';
            }
        }
        // c++11 STL
        {

            std::string s = "ST Libraries CPP";
            std::regex expr{"(\\w+)\\s(\\w+)\\s(\\w+)"};
            std::smatch what;
            if (std::regex_search(s, what, expr))
            {
                std::cout << what[0] << '\n';
                std::cout << what[1] << " _ " << what[2] << " _ " << what[3] << '\n';
            }
        }
    }

    // sample 3
    // regex_replace
    {
        std::cout << "sample 3:\n";
        // boost
        {
            std::string s = "XXBoostXXLibrariesXX";
            boost::regex expr{"XX"};
            std::string fmt{"_*_"};
            std::cout << boost::regex_replace(s, expr, fmt) << '\n';
        }
        // c++11 STL
        {
            std::string s = " ST Libraries ";
            std::regex expr{"\\s"};
            std::string fmt{"_"};
            std::cout << std::regex_replace(s, expr, fmt) << '\n';
        }
    }

    // sample 4
    // regex_replace + format string
    {
        std::cout << "sample 4:\n";
        // boost
        {
            std::string s = "BoostXXLibraries";
            boost::regex expr{"(\\w+)\\XX(\\w+)"};
            std::string fmt{"\\2 \\1"}; // or  fmt{"$2 $1"};
            std::cout << boost::regex_replace(s, expr, fmt) << '\n';
        }
        // c++11 STL
        {
            std::string s = "ST Libraries";
            std::regex expr{"(\\w+)\\s(\\w+)"};
            std::string fmt{"$2 $1"};
            std::cout << std::regex_replace(s, expr, fmt) << '\n';
        }
    }

    // sample 5
    // output epected : \2 \1
    {
        std::cout << "sample 5:\n";
        // boost
        {
            std::string s = "Boost Libraries";
            boost::regex expr{"(\\w+)\\s(\\w+)"};
            std::string fmt{"\\2 \\1"};
            std::cout << boost::regex_replace(s, expr, fmt,
                                              boost::regex_constants::format_literal)
                      << '\n';
        }
        // c++11 STL
        {
            std::string s = "Boost Libraries";
            boost::regex expr{"(\\w+)\\s(\\w+)"};
            std::string fmt{"\\2 \\1"};
            std::cout << boost::regex_replace(s, expr, fmt,
                                              boost::regex_constants::format_literal)
                      << '\n';
        }
    }

    // sample 6
    //
    {
        std::cout << "sample 6:\n";
        // boost
        {
            std::string s = "Boost Libraries C++";
            boost::regex expr{"\\w*[o,i]+"};
            boost::regex_token_iterator<std::string::iterator> it{s.begin(), s.end(), expr};
            boost::regex_token_iterator<std::string::iterator> end;
            while (it != end)
                std::cout << *it++ << '\n';
        }
        // c++11 STL
        {
            std::string s = "Boost Libraries and st libraries";
            std::regex expr{"\\w*[t,s]+"};
            std::regex_token_iterator<std::string::iterator> it{s.begin(), s.end(), expr};
            std::regex_token_iterator<std::string::iterator> end;
            while (it != end)
                std::cout << *it++ << '\n';
        }
    }

    // sample 7
    //
    {
        std::cout << "sample 7:\n";
        // boost
        {
            std::string s = "Boost Libraries";
            boost::regex expr{"(\\w)\\w+"};
            boost::regex_token_iterator<std::string::iterator> it{s.begin(), s.end(),
                                                                  expr, 1};
            boost::regex_token_iterator<std::string::iterator> end;
            while (it != end)
                std::cout << *it++ << '\n';
        }
        // c++11 STL
        {
            std::string s = "Boost Libraries and st libraries";
            std::regex expr{"(\\w)\\w+"};
            std::regex_token_iterator<std::string::iterator> it{s.begin(), s.end(),
                                                                expr, 1};
            std::regex_token_iterator<std::string::iterator> end;
            while (it != end)
                std::cout << *it++ << '\n';
        }
    }

    // sample 8
    //
    {
        std::cout << "sample 8:\n";
        // boost
        {
            std::string s = "Boost Библиотеки";
            boost::basic_regex<char, boost::cpp_regex_traits<char>> expr;
            expr.imbue(std::locale{"Russian"});
            expr = "\\w+\\s\\w+";
            std::cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
        }
        // c++11 STL
        {

        }
    }

    return 0;
}