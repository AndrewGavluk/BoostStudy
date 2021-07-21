#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

template < typename T, typename Tcin, typename Tcout>
class API_Samples
{
    public:
        API_Samples(Tcin&,  Tcout&);
        void GetLine();
        void Run(); 
        void Run(const ascii::space_type&); 
        void Run(const ascii::space_type&, qi::skip_flag); 
    private:
        T m_string;
        Tcin& m_istream;
        Tcout& m_ostream;
};