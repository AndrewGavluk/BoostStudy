#include <algorithm>
#include <string>
#include <iostream>
#include <locale> // sample 2
#include <vector> // sample 5

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>

using namespace boost::algorithm;

int main()
{
    // sample 1
    // same to_upper_copy(), to_lower_copy(), to_upper() to_lower()
    {
        std::cout << "sample 1:\n";
        std::string str = "Boost C++ Libraries";
        std::string str1{str}, str2{str};
        std::cout << boost::algorithm::to_upper_copy(str1) << '\n';
        std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        std::cout << str2 << '\n';
    }
    // sample 2
    // locale {u8"ru_RU"} or {"Russian"}
#ifdef __linux__
#define RUS_LOC u8"ru_RU"
#else
#define RUS_LOC u8"ru-RU"
#endif //__linux__
    {
        std::cout << "sample 2:\n";
        std::string s = "Boost C++ Библиотеки";
        std::string upper_case1 = boost::algorithm::to_upper_copy(s);
        std::locale::global(std::locale{u8"ru_RU"});
        std::string upper_case2 = boost::algorithm::to_upper_copy(s, std::locale{u8"ru_RU"});
        std::cout << upper_case1 << '\n';
        std::cout << upper_case2 << '\n';
    }

    // sample 3
    // remove characters from a string
    {
        std::cout << "sample 3:\n";
        std::string s = "Boost C++ Libraries";
        std::cout << erase_first_copy(s, "s") << '\n';
        std::cout << erase_nth_copy(s, "s", 0) << '\n';
        std::cout << erase_last_copy(s, "s") << '\n';
        std::cout << erase_all_copy(s, "s") << '\n';
        std::cout << erase_head_copy(s, 5) << '\n';
        std::cout << erase_tail_copy(s, 9) << '\n';
        // STL version:
        // str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());
    }

    // sample 4
    // Searching for substrings find_last, find_nth, find_head, find_tail
    {
        std::cout << "sample 4:\n";
        std::string s = "Boost C++ Libraries";
        boost::iterator_range<std::string::iterator> r = boost::algorithm::find_first(s, "C++");
        std::cout << r << '\n';
        r = boost::algorithm::find_first(s, "xyz");
        std::cout << r << '\n';
        // STL : string::find_first_of string::find_lasr_of 
    }

    // sample 5
    // concatenating
    {
        std::cout << "sample 5:\n";
        std::vector<std::string> v{"Boost", "C++", "Libraries"};
        std::cout << boost::algorithm::join(v, " ") << '\n';
    }

    // sample 6
    // replace characters in a string
    {
        std::cout << "sample 6:\n";
        std::string s = "Boost C++ Libraries";
        std::cout << replace_first_copy(s, "+", "-") << '\n';
        std::cout << replace_nth_copy(s, "+", 0, "-") << '\n';
        std::cout << replace_last_copy(s, "+", "-") << '\n';
        std::cout << replace_all_copy(s, "+", "-") << '\n';
        std::cout << replace_head_copy(s, 5, "BOOST") << '\n';
        std::cout << replace_tail_copy(s, 9, "LIBRARIES") << '\n';
        // STL string replace
    }

    // sample 7
    // Algorithms to trim
    {
        std::cout << "sample 7:\n";
        std::string s = "\t Boost C++ Libraries \t";
        std::cout << "_" << trim_left_copy(s) << "_\n";
        std::cout << "_" << trim_right_copy(s) << "_\n";
        std::cout << "_" << trim_copy(s) << "_\n";
    }

    // sample 8
    //  Creating predicates with is_any_of
    {
        std::cout << "sample 8:\n";
        std::string s = "--Boost C++ Libraries--";
        std::cout << trim_left_copy_if(s, is_any_of("-")) << '\n';
        std::cout << trim_right_copy_if(s, is_any_of("-")) << '\n';
        std::cout << trim_copy_if(s, is_any_of("-")) << '\n';
        //trim_[left, right. ]_[copy, ]_[if, ]
    }

    // sample 9
    //  Creating predicates with is_any_of
    {
        std::cout << "sample 9:\n";
        std::string s = "123456789Boost C++ Libraries123456789";
        std::cout << trim_left_copy_if(s, is_digit()) << '\n';
        std::cout << trim_right_copy_if(s, is_digit()) << '\n';
        std::cout << trim_copy_if(s, is_digit()) << '\n';
    }

    // sample 10
    //  Creating predicates with is_any_of
    {
        std::cout << "sample 10:\n";
        std::string s = "Boost C++ Libraries";
        std::cout.setf(std::ios::boolalpha);
        std::cout << starts_with(s, "Boost") << '\n';
        std::cout << ends_with(s, "Libraries") << '\n';
        std::cout << contains(s, "C++") << '\n';
        std::cout << lexicographical_compare(s, "Boost") << '\n';
    }

    // sample 11
    // Splitting strings
    {
        std::cout << "sample 11:\n";
        std::string s = "Boost C++ Libraries";
        std::vector<std::string> v;
        split(v, s, is_space());
        std::cout << v.size() << '\n';
    }

    // sample 12
    //  Searching strings
    {
        std::cout << "sample 12:\n";
        std::string s = "Boost C++ Libraries";
        boost::iterator_range<std::string::iterator> r =
            find_regex(s, boost::regex{"\\w\\+\\+"});
        std::cout << r << '\n';
    }

    return 0;
}