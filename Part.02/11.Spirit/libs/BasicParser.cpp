
#include "BasicParser.hpp"

#include <boost/phoenix/phoenix.hpp>
#include <boost/variant.hpp>

#include <string>
#include <iostream>
#include <vector>
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

template <typename T> 
void Parser9<T>::Parse(){
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::int_[([](int i){ std::cout << i << std::endl; })], 
        ascii::space);
}

template <typename T> 
void ParserA<T>::Parse(){
    using boost::phoenix::ref;
    int i;
    BasicParser<T>::m_match = qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::int_[ref(i) = qi::_1],
        ascii::space);

    if (BasicParser<T>::m_match)
        std::cout << i << '\n';
}

template <typename T> 
void ParserB<T>::Parse(){
    int i;
    if (qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::int_, 
        ascii::space, 
        i))
        std::cout << i << '\n';
}

template <typename T> 
void ParserC<T>::Parse(){
    std::vector<int> v;
    if (qi::phrase_parse(
        BasicParser<T>::m_it,
        BasicParser<T>::m_string.end(),
        qi::int_ % ',',
        ascii::space,
        v))
    {
        std::ostream_iterator<int> out{std::cout, ";"};
        std::copy(v.begin(), v.end(), out);
    }
}

template <typename T>
void ParserD(std::basic_istream<T>& istream,  std::basic_ostream<T>& ostream)
{
    using String = std::basic_string<T>;
    String s;
    std::getline(istream, s);
    auto it = s.begin();

    qi::rule<typename String::iterator, std::vector<int>(),
    ascii::space_type> values = qi::int_ % ',';
    
    std::vector<int> v;
    if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
    {
        std::ostream_iterator<int, T> out{std::cout, ";" };
        std::copy(v.begin(), v.end(), out);
    }
}


struct print : public boost::static_visitor<>
{
  template <typename T>
  void operator()(T t) const
  {
    std::cout << std::boolalpha << t << ';';
  }
};

template <typename T>
void ParserE(std::basic_istream<T>& istream,  std::basic_ostream<T>& ostream)
{
    using String = std::basic_string<T>;
    String s;
    std::getline(istream, s);
    auto it = s.begin();

    qi::rule< typename String::iterator, boost::variant<int, bool>(),
        ascii::space_type> value = qi::int_ | qi::bool_;
    qi::rule< typename String::iterator, std::vector<boost::variant<int, bool> >(),
        ascii::space_type> values = value % ',';

    std::vector<boost::variant<int, bool>> v;
    if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
        for (const auto &elem : v)
            boost::apply_visitor(print{}, elem);
    
}

template <typename Iterator, typename Skipper>
struct my_grammar : qi::grammar<Iterator,
  std::vector<boost::variant<int, bool>>(), Skipper>
{
  my_grammar() : my_grammar::base_type{values}
  {
    value = qi::int_ | qi::bool_;
    values = value % ',';
  }

  qi::rule<Iterator, boost::variant<int, bool>(), Skipper> value;
  qi::rule<Iterator, std::vector<boost::variant<int, bool>>(), Skipper>
    values;
};

template <typename T>
void ParserF(std::basic_istream<T>& istream,  std::basic_ostream<T>& ostream)
{
    using String = std::basic_string<T>;
    String s;
    std::getline(istream, s);
    auto it = s.begin();
    my_grammar<typename String::iterator,  ascii::space_type> g;
    std::vector<boost::variant<int, bool>> v;
    if (qi::phrase_parse(it, s.end(), g, ascii::space, v))
    {
        for (const auto &elem : v)
            boost::apply_visitor(print{}, elem);
    }
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
    template void ParserE(std::basic_istream<T>& istream,  std::basic_ostream<T>& ostream);\
    template void ParserF(std::basic_istream<T>& istream,  std::basic_ostream<T>& ostream);\

#define INSTANTIATION\
    BOOST_PP_SEQ_FOR_EACH(PARSERS_CONSSTRUCTORS, , PARSERS)
    INSTANTIATION_T(char)\
    INSTANTIATION_T(wchar_t)\
    template void ParserD(std::basic_istream<char>& istream,  std::basic_ostream<char>& ostream);\

INSTANTIATION