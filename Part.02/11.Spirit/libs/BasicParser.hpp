#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

template < typename T >
class BasicParser
{
    public:

        BasicParser(std::basic_istream<T>&, std::basic_ostream<T>&);
        void Run(); 
        
    protected:

        std::basic_string<T>    m_string;
        typename std::basic_string<T>::iterator m_it;
        std::basic_istream<T>&  m_istream;
        std::basic_ostream<T>&  m_ostream;
        bool m_match; 

    private:

        void GetLine();
        void virtual Parse() = 0;
        void Print();

};

#define PARSERS \
(Parser1)\
(Parser2)\
(Parser3)\
(Parser4)\
(Parser5)\
(Parser6)\
(Parser7)\
(Parser8)\

#define TEMPLATE_CLASS(r, TT, elem) \
template < typename T > \
class elem : public BasicParser<T> \
{ \
     public: \
        elem(std::basic_istream<T>&, std::basic_ostream<T>&); \
     private: \
        void virtual Parse() final; \
}; \

BOOST_PP_SEQ_FOR_EACH(TEMPLATE_CLASS, , PARSERS);
