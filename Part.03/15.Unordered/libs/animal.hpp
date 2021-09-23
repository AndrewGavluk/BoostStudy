#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <string>
#include <iostream>
#include <cstddef>

using animal_unordered_set_1 = boost::unordered_set<std::string> ;
using animal_unordered_map_2 = boost::unordered_map<std::string, int>;


struct animal
{
  std::string name;
  int legs;
};

using animal_unordered_set_3 = boost::unordered_set<animal>;

bool operator==(const animal &lhs, const animal &rhs);
std::size_t hash_value(const animal &a);

template <typename T>
T CreateAnimal ();