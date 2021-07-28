
#include "BasicParser.hpp"
#include <string>
#include <iostream>

using namespace boost::spirit;

template <typename T>
BasicParser<T>::BasicParser(std::basic_istream<T>& _istream,  std::basic_ostream<T>& _ostream): 
     m_istream(_istream), m_ostream(_ostream){}

template <typename T>
void BasicParser<T>::GetLine(){
    std::getline(m_istream, m_string);
    m_it = m_string.begin();
}

template <typename T>
void BasicParser<T>::Print(){
    std::cout << std::boolalpha << m_match << '\n';
    if (m_it != m_string.end())
        m_ostream << std::basic_string<T>{m_it, m_string.end()} << '\n';
}

template <typename T>
void BasicParser<T>::Run(){
    GetLine();
    Parse();
    Print();
}

template <typename T>
void BasicParser<T>::Parse(){}

template <typename T> 
void Parser1<T>::Parse(){
    BasicParser<T>::m_match = qi::parse(
        BasicParser<T>::m_it, 
        BasicParser<T>::m_string.end(), 
        ascii::digit);
}

template <typename T> 
void Parser2<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        ascii::digit,
        ascii::space);
}

template <typename T> 
void Parser3<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it, 
        BasicParser<T>::m_string.end(), 
        ascii::digit, 
        ascii::space,
        qi::skip_flag::dont_postskip);
}

template <typename T> 
void Parser4<T>::Parse(){
   BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it, 
        BasicParser<T>::m_string.end(),
        ascii::digit,
        ascii::space,
        qi::skip_flag::dont_postskip);
}

template <typename T> 
void Parser5<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        ascii::digit >> ascii::digit,
        ascii::space);
}

template <typename T> 
void Parser6<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::lexeme[ascii::digit >> ascii::digit],
        ascii::space);
}

template <typename T> 
void Parser7<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        +ascii::digit,
        ascii::space);
}

template <typename T> 
void Parser8<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::int_,
        ascii::space);
}


#define PARSERS_CONSSTRUCTORS(r, TT ,elem1) \
    template <typename T> elem1<T>::elem1(std::basic_istream<T>& _istream, std::basic_ostream<T>& _ostream): \
    BasicParser<T>(_istream, _ostream){} \

#define INSTANTIATION_PARSER(r,  T, elem1) \
    template elem1<T>::elem1(std::basic_istream<T>&, std::basic_ostream<T>&);\
    template void elem1<T>::Parse();\

#define INSTANTIATION_T(T)\
    template BasicParser<T>::BasicParser(std::basic_istream<T>&, std::basic_ostream<T>&);\
    template void BasicParser<T>::GetLine();\
    template void BasicParser<T>::Print();\
    template void BasicParser<T>::Run();\
    template void BasicParser<T>::Parse();\
    BOOST_PP_SEQ_FOR_EACH(INSTANTIATION_PARSER, T, PARSERS)\

#define INSTANTIATION\
    BOOST_PP_SEQ_FOR_EACH(PARSERS_CONSSTRUCTORS, , PARSERS)
    INSTANTIATION_T(char)\
    INSTANTIATION_T(wchar_t)\

INSTANTIATION