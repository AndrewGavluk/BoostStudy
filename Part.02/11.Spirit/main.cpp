
#include <boost/preprocessor/control/iif.hpp>
#include "libs/SimpleParser.hpp"

#include <string>
#include <iostream>

#define SAMPLE(T, N, cond) \
{\
    std::cout << "sample N:\n"; \
    BOOST_PP_SEQ_ELEM(N, PARSERS)<T> sample { BOOST_PP_IIF( cond, std::cin, std::wcin), BOOST_PP_IIF( cond, std::cout, std::wcout) };\
    sample.Run();\
}\

using namespace boost::spirit;

void RunAPISamples(){
    SAMPLE(char, 0, 1);
    SAMPLE(char, 1, 1);
    SAMPLE(char, 2, 1);
    SAMPLE(wchar_t, 3, 0);
}

void RunParserSamples(){
    SAMPLE(char, 4, 1);
    SAMPLE(char, 5, 1);
    SAMPLE(char, 6, 1);
    SAMPLE(char, 7, 1);
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
