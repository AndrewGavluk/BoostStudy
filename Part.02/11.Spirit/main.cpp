#include "API_Samples.hpp"


#include <string>
#include <iostream>

using namespace boost::spirit;

void RunAPISamples()
{
    API_Samples<std::string, std::istream, std::ostream> Sample1_3{std::cin, std::cout};
    // sample 1
    //
    {
        std::cout << "sample 1:\n";
        Sample1_3.GetLine();
        Sample1_3.Run();
    }

    // sample 2
    //
    {
        std::cout << "sample 2:\n";
        Sample1_3.GetLine();
        Sample1_3.Run(ascii::space);
    }

    // sample 3
    //
    {
        std::cout << "sample 3:\n";
        //Sample1_3.GetLine();
        //Sample1_3.Run(ascii::space,  qi::skip_flag::dont_postskip);
    }

    API_Samples<std::wstring, std::wistream, std::wostream> Sample4{std::wcin, std::wcout};
    // sample 4
    //
    {
        std::cout << "sample 4:\n";
        Sample4.GetLine();
        Sample4.Run(ascii::space/*,  qi::skip_flag::dont_postskip*/);
    }
}

int main()
{
    RunAPISamples();
    

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
