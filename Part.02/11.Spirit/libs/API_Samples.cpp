#include "API_Samples.hpp"
#include <string>
#include <iostream>

using namespace boost::spirit;

template < typename T, typename Tcin, typename Tcout>
API_Samples<T, Tcin, Tcout>::API_Samples(Tcin& _istream,  Tcout& _ostream): 
     m_istream(_istream), m_ostream(_ostream){}

template < typename T, typename Tcin, typename Tcout>
void API_Samples<T, Tcin, Tcout>::GetLine(){
    std::getline(m_istream, m_string);
}

template < typename T, typename Tcin, typename Tcout>
void API_Samples< T, Tcin, Tcout>::Run(){
    auto it = m_string.begin();
    bool match = qi::parse(it, m_string.end(), ascii::digit);
    std::cout << std::boolalpha << match << '\n';
    if (it != m_string.end())
        std::cout << std::string{it, m_string.end()} << '\n';
}

template < class T, class Tcin, class Tcout>
void API_Samples<T, Tcin, Tcout>::Run(const ascii::space_type& spaceTypes){
    auto it = m_string.begin();
    bool match = qi::parse(it, m_string.end(), spaceTypes);
    std::cout << std::boolalpha << match << '\n';
    if (it != m_string.end())
        std::cout << std::string{it, m_string.end()} << '\n';
}

template < class T, class Tcin, class Tcout>
void API_Samples<T, Tcin, Tcout>::Run(const ascii::space_type& spaceTypes, qi::skip_flag skipFlag){
    auto it = m_string.begin();
    bool match = qi::parse(it, m_string.end(), spaceTypes, skipFlag);
    std::cout << std::boolalpha << match << '\n';
    if (it != m_string.end())
        std::cout << std::string{it, m_string.end()} << '\n';
}

#define INSTANTIATION_TTT( T, Tcin, Tcout)\
    template API_Samples<T, Tcin, Tcout>::API_Samples(Tcin&,  Tcout&);\
    template void API_Samples<T, Tcin, Tcout>::GetLine();\
    template void API_Samples<T, Tcin, Tcout>::Run();\
    template void API_Samples<T, Tcin, Tcout>::Run(const ascii::space_type&);\
    template void API_Samples<T, Tcin, Tcout>::Run(const ascii::space_type&, qi::skip_flag);\

#define INSTANTIATION \
    INSTANTIATION_TTT(std::string, std::istream,  std::ostream)\
    INSTANTIATION_TTT(std::wstring, std::wistream,  std::wostream)\

INSTANTIATION