#include "animal.hpp"

bool operator==(const animal &lhs, const animal &rhs)
{
  return lhs.name == rhs.name && lhs.legs == rhs.legs;
}

std::size_t hash_value(const animal &a)
{
  std::size_t seed = 0;
  boost::hash_combine(seed, a.name);
  boost::hash_combine(seed, a.legs);
  return seed;
}

template <>
animal_unordered_set_1 CreateAnimal()
{
  animal_unordered_set_1 animals;
  animals.emplace("cat");
  animals.emplace("shark");
  animals.emplace("spider");

  return animals;
}

template <>
animal_unordered_map_2 CreateAnimal()
{
  animal_unordered_map_2 animals;
  animals.emplace("cat", 4);
  animals.emplace("shark", 0);
  animals.emplace("spider", 8);

  return animals;
}

template <>
animal_unordered_set_3 CreateAnimal()
{
  animal_unordered_set_3 animals;
  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});

  return animals;
}