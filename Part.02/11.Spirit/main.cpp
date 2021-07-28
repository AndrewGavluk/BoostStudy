
#include <boost/preprocessor/control/iif.hpp>
#include <boost/vmd/equal.hpp>
#include "libs/SimpleParser.hpp"

#include <string>
#include <iostream>

using namespace boost::spirit;

#define SAMPLE(T, N) \
{\
    std::cout << "\nsample " + std::to_string(N) + ":\n"; \
    BOOST_PP_SEQ_ELEM(N, PARSERS)<T> sample { std::cin, std::cout};\
    sample.Run();\
}\

#define WSAMPLE(T, N) \
{ \
    std::cout << "\nsample" + std::to_string(N) + ":\n"; \
    BOOST_PP_SEQ_ELEM(N, PARSERS)<T> sample { std::wcin, std::wcout}; \
    sample.Run(); \
} \

// sample: 1 2 3 q w e
void RunAPISamples(){
    SAMPLE(char, 0);
    SAMPLE(char, 1);
    SAMPLE(char, 2);
    WSAMPLE(wchar_t, 3);
}

// sample: 1 2 q w
// sample: 12 qw
// sample: -12 qw
void RunParserSamples(){
    SAMPLE(char, 4);
    SAMPLE(char, 5);
    SAMPLE(char, 6);
    SAMPLE(char, 7);
}

void RunActionsSamples(){}

void RunAttributesSamples(){}

void RunRulesSamples(){}

void RunGrammarSamples(){}

int main()
{
    //RunAPISamples();
    RunParserSamples();

    return 0;
}
