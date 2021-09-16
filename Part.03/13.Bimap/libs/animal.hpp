#include <boost/bimap.hpp>

// exersize 4
#include <boost/bimap/multiset_of.hpp>

// exersize 5
#include <boost/bimap/unconstrained_set_of.hpp>
#include <boost/bimap/support/lambda.hpp>

#include <string>
#include <iostream>


struct animal
{
  std::string name;
  int legs;
};

template <typename T>
T CreateAnimal ();

using namespace boost::multi_index;

using animal_bimap_1_2 = boost::bimap<std::string, int>;

using animal_bimap_3 = boost::bimap<
    boost::bimaps::set_of<std::string>,
    boost::bimaps::set_of<int> >;

using animal_bimap_4 = boost::bimap<
    boost::bimaps::set_of<std::string>,
    boost::bimaps::multiset_of<int> >;

using animal_bimap_5 = boost::bimap<
    std::string,
    boost::bimaps::unconstrained_set_of<int>>;
