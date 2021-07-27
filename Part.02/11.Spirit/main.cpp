#include "libs/SimpleParser.hpp"

#include <string>
#include <iostream>

using namespace boost::spirit;

void RunAPISamples(){

    // sample 1
    //
    {
        std::cout << "sample 1:\n";
        Parser1<char> sample1{std::cin, std::cout};
        sample1.Run();
    }

    // sample 2
    //
    {
        std::cout << "sample 2:\n";
        Parser2<char> sample2{std::cin, std::cout};
        sample2.Run();
    }

    // sample 3
    //
    {
        std::cout << "sample 3:\n";
        Parser3<char> sample3{std::cin, std::cout};
        sample3.Run();
    }

    // sample 4
    //
    {
        std::cout << "sample 4:\n";
        Parser4<wchar_t> sample4{std::wcin, std::wcout};
        sample4.Run();
    }
}

void RunParserSamples(){
    
    // sample 5
    //
    {
        std::cout << "sample 5:\n";
        Parser5<char> sample5{std::cin, std::cout};
        sample5.Run();
    }

    // sample 6
    //
    {
        std::cout << "sample 6:\n";
        Parser6<char> sample6{std::cin, std::cout};
        sample6.Run();
    }

    // sample 7
    //
    {
        std::cout << "sample 7:\n";
        Parser7<char> sample7{std::cin, std::cout};
        sample7.Run();
    }

    // sample 8
    //
    {
        std::cout << "sample 8:\n";
        Parser8<char> sample8{std::cin, std::cout};
        sample8.Run();
    }
}

void RunActionsSamples(){}

void RunAttributesSamples(){}

void RunRulesSamples(){}

void RunGrammarSamples(){}

int main()
{
    RunAPISamples();
    RunAttributesSamples();

  
    return 0;
}
