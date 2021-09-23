#include "animal.hpp"

template <typename T>
T CreateAnimal ()
{
  T animals;
  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"dog", 4});
  animals.insert({"spider", 8});
return animals;
}

template <>
animal_multi_4 CreateAnimal ()
{
  animal_multi_4 animals;
  animals.push_back({"cat", 4});
  animals.push_back({"shark", 0});
  animals.push_back({"dog", 4});
  animals.push_back({"spider", 8});
return animals;
}

template <>
animal_multi_5 CreateAnimal ()
{
  animal_multi_5 animals;
  animals.emplace("cat", 4);
  animals.emplace("shark", 0);
  animals.emplace("dog", 4);
  animals.emplace("spider", 8);
return animals;
}

template animal_multi_1_2 CreateAnimal ();
template animal_multi_3 CreateAnimal ();
