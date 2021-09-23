#include <boost/multi_index_container.hpp>

// exersize 1-2
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

// exersize 3-4
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>

// exersize 5
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>

#include <string>


struct animal
{
  std::string name;
  int legs;
};

template <typename T>
T CreateAnimal ();

using namespace boost::multi_index;

using animal_multi_1_2 = multi_index_container<
  animal,
  indexed_by< 
    hashed_non_unique< member< animal, std::string, &animal::name > >,
    hashed_non_unique< member< animal, int, &animal::legs > >
  >
> ;

using animal_multi_3 = multi_index_container<
  animal,
  indexed_by< 
    hashed_non_unique< member< animal, std::string, &animal::name > >,
    hashed_unique< member< animal, int, &animal::legs > >
  >
> ;


using animal_multi_4 = multi_index_container<
  animal,
  indexed_by< 
    sequenced<>,
    ordered_non_unique< member< animal, int, &animal::legs > >,
    random_access<>
  >
>;

class animal5
{
public:
  animal5(std::string name, int legs) : name_{std::move(name)},
    legs_(legs) {}
  bool operator<(const animal5 &a) const { return legs_ < a.legs_; }
  const std::string &name() const { return name_; }
private:
  std::string name_;
  int legs_;
};

using animal_multi_5 = multi_index_container<
  animal5,
  indexed_by< 
    ordered_unique< identity<animal5> >,
    hashed_unique< const_mem_fun <animal5, const std::string&, &animal5::name > >
  >
>;
