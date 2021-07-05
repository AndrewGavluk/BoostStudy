#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

using tokenizer = boost::tokenizer<boost::char_separator<char>>;
using wtokenizer = boost::tokenizer<boost::char_separator<wchar_t>,
                                    std::wstring::const_iterator,
                                    std::wstring>;
using etokenizer = boost::tokenizer<boost::escaped_list_separator<wchar_t>>;
using ostokenizer = boost::tokenizer<boost::offset_separator>;
void show(const tokenizer &tok)
{
    for (const auto &t : tok)
        std::cout << t << '\n';
}

int main()
{
    std::string s = "Boost C++ Libraries";

    // sample 1
    // tokenizer
    {
        std::cout << "sample 1:\n";

        tokenizer tok{s};
        for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
            std::cout << *it << '\n';
    }

    // sample 2
    // char separator
    {
        std::cout << "sample 2:\n";
        boost::char_separator<char> sep{" "};
        tokenizer tok{s, sep};
        show(tok);
    }

    // sample 3
    // char separator several params
    {
        std::cout << "sample 3:\n";
        boost::char_separator<char> sep{" ", "+"};
        tokenizer tok{s, sep};
        show(tok);
    }

    // sample 4
    // char separator third params
    {
    // regex_replace + format string
        std::cout << "sample 4:\n";
        boost::char_separator<char> sep{" ", "+", boost::keep_empty_tokens};
        tokenizer tok{s, sep};
        show(tok);
    }

    // sample 5
    // Wstring
    {
        std::cout << "sample 5:\n";
        std::wstring s = L"Boost C++ Libraries";
        boost::char_separator<wchar_t> sep{L" "};
        wtokenizer tok{s, sep};
        for (const auto &t : tok)
            std::wcout << t << '\n';
    }

    // sample 6
    // csv format
    {
        std::cout << "sample 6:\n";
        std::string s = "Boost,\"C++ Libraries\"";
        etokenizer tok{s};
        for (const auto &t : tok)
            std::cout << t << '\n';
    }

    // sample 7
    // ofset separator format
    {
        std::cout << "sample 7:\n";
        std::string s = "Boost_C++_Libraries";
        int offsets[] = {5, 5, 9};
        boost::offset_separator sep{offsets, offsets + 3};
        ostokenizer tok{s, sep};
        for (const auto &t : tok)
            std::cout << t << '\n';
    }
    return 0;
}
