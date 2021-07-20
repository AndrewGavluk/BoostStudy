#include "API_Samples.hpp"


#include <string>
#include <iostream>

using namespace boost::spirit;

int main()
{
    std::string s;
    std::getline(std::cin, s);


    // sample 1
    //
    {
        //std::cout << "sample 1:\n";
        API_Samples<std::string, std::istream, std::ostream> Sample1{std::cin, std::cout};
        Sample1.GetLine();
        Sample1.Run();
    }

    // sample 2
    //
    {
        //std::cout << "sample 2:\n";
        auto it = s.begin();    
        bool match = qi::phrase_parse(it, s.end(), ascii::digit, ascii::space);
        std::cout << std::boolalpha << match << '\n';
        if (it != s.end())
            std::cout << std::string{it, s.end()} << '\n';
    }

    // sample 3
    //
    {
        //std::cout << "sample 3:\n";
        auto it = s.begin();        
        bool match = qi::phrase_parse(it, s.end(), ascii::digit, ascii::space,
        qi::skip_flag::dont_postskip);
        std::cout << std::boolalpha << match << '\n';
        if (it != s.end())
            std::cout << std::string{it, s.end()} << '\n';
    }

    // sample 4
    //
    {
        //std::cout << "sample 4:\n";
        std::wstring s;
        std::getline(std::wcin, s);
        auto it = s.begin();
        bool match = qi::phrase_parse(it, s.end(), ascii::digit, ascii::space,
        qi::skip_flag::dont_postskip);
        std::wcout << std::boolalpha << match << '\n';
        if (it != s.end())
            std::wcout << std::wstring{it, s.end()} << '\n';
    }

    // sample 5
    //
    {
        //std::cout << "sample 5:\n";
    
    }

    // sample 6
    //
    {
        //std::cout << "sample 6:\n";
       
    }

    // sample 7
    //
    {
        //std::cout << "sample 7:\n";
        
    }
    return 0;
}
