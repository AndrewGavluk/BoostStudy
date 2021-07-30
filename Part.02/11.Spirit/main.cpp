
#include "libs/BasicParser.hpp"

#include <boost/preprocessor/control/iif.hpp>
#include <boost/vmd/equal.hpp>

#include <string>
#include <iostream>

using namespace boost::spirit;

#define CSAMPLE(T, N) SAMPLE(T, N, std::cin, std::cout)
#define WSAMPLE(T, N) SAMPLE(T, N, std::wcin, std::wcout)

#define SAMPLE(T, N, Tcin, Tcout)\
{\
    std::cout << "\nsample" + std::to_string(N) + ":\n"; \
    BOOST_PP_SEQ_ELEM(N, PARSERS)<T> sample { Tcin, Tcout}; \
    sample.Run();\
}\

void RunAPISamples(){
    CSAMPLE(char, 0);
    CSAMPLE(char, 1);
    CSAMPLE(char, 2);
    WSAMPLE(wchar_t, 3);
}

void RunParserSamples(){
    CSAMPLE(char, 4);
    CSAMPLE(char, 5);
    CSAMPLE(char, 6);
    CSAMPLE(char, 7);
}

void RunActionsSamples(){

}

void RunAttributesSamples(){}

void RunRulesSamples(){}

void RunGrammarSamples(){}

int main()
{
    RunAPISamples();
    RunParserSamples();

    return 0;
}
